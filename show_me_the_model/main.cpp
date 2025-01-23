#include <iostream>
#include <vulkan/vulkan.hpp>

import neftyUtility;

const std::string NAME = "Vulkan Minimal Sample";

#define DEVICE_SELECTION 0

int main() {
    std::cout << "Vulkan Minimal Sample Application" << std::endl << std::endl;
    const auto appInfo = vk::ApplicationInfo(NAME.c_str(), 1, "none", 1, VK_API_VERSION_1_3);
    const auto instanceCreateInfo = vk::InstanceCreateInfo({}, &appInfo);
    const auto instance = vk::createInstance(instanceCreateInfo);

    { /* this scope is just for printing */
        std::cout << "Available Instance Extensions" << std::endl;
        for ( // In this for loop you can scan and detect instance extensions are available or not.
            const auto instanceExtensions = vk::enumerateInstanceExtensionProperties();
            const auto& extension : instanceExtensions
            ) {
            std::cout << extension.extensionName << " version: " << extension.specVersion << std::endl;
            }
        std::cout << std::endl;
    }

    const auto physicalDevices = instance.enumeratePhysicalDevices();
    NU::PrintDeviceInfo(physicalDevices);


    /* Now time to select queue family to use.
     * all the queue family with TRANSFER and GRAPHICS are Okay
     *
     * And then when the device is created the queue will be there too
     * */

    const auto physicalDeviceQueueFamilyProperties = physicalDevices[0].getQueueFamilyProperties();



    instance.destroy();
    return 0;
}
