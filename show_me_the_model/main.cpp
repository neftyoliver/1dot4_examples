#include <iostream>
#include <vector>
#include <vulkan/vulkan.hpp>
#include "neftyUtility.hpp"


const std::string NAME = "Vulkan Minimal Sample";

#define DEVICE_SELECTION 0

int main() {
    std::cout << "Vulkan Minimal Sample Application" << std::endl << std::endl;
    const auto appInfo = vk::ApplicationInfo(NAME.c_str(), 1, "none", 1, VK_API_VERSION_1_3);
    const auto instanceCreateInfo = vk::InstanceCreateInfo({}, &appInfo);
    const auto instance = vk::createInstance(instanceCreateInfo);

    NU::PRINT::PrintInstanceExtensions();

    const auto physicalDevices = instance.enumeratePhysicalDevices();
    NU::PRINT::PrintDeviceInfo(physicalDevices);


    /* Now time to select queue family to use.
     * all the queue family with TRANSFER and GRAPHICS are Okay
     *
     * And then when the device is created the queue will be there too
     * */

    const auto physicalDeviceQueueFamilyProperties = physicalDevices[DEVICE_SELECTION].getQueueFamilyProperties();
    const auto queueFamilyIndex = NU::findGraphicAndTransferQueueFamilyIndex(physicalDeviceQueueFamilyProperties);

    const float queuePriority = 1.0f;

    const auto deviceQueueCreateInfo = vk::DeviceQueueCreateInfo(
            vk::DeviceQueueCreateFlags(), //Currently 0x00000001 is the only value can use. it's a VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT
            static_cast<uint32_t>(queueFamilyIndex),
            1, //only one queue is all we need
            &queuePriority
        );

    const auto deviceCreateInfo = vk::DeviceCreateInfo(
        vk::DeviceCreateFlags(), //Ignore this thing...
        deviceQueueCreateInfo
        );

    const auto device = physicalDevices[DEVICE_SELECTION].createDevice(deviceCreateInfo);
    const auto queue = device.getQueue(queueFamilyIndex, 0); //There should be a queue that can do graphics and transfer.

    


    instance.destroy();
    return 0;
}
