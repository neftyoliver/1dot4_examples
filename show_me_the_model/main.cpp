#include <iostream>
#include <vulkan/vulkan.hpp>

//import NeftyUtility;

const std::string NAME = "Vulkan Minimal Sample";

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
    { /* this scope is just for printing. */
        std::cout << "Physical Devices and some information about them" << std::endl << std::endl;
        for (const auto& physicalDevice : physicalDevices) {
            std::cout << physicalDevice.getProperties().deviceName << std::endl;
            std::cout << physicalDevice.getProperties().vendorID << std::endl;

            for (const auto& queueFamilyProperties: physicalDevice.getQueueFamilyProperties()) {
                std::cout << "Number of queues " << queueFamilyProperties.queueCount << " : " ;
                std::cout << "What queue can do ";

                std::vector<std::string> queueFamilyPropertyFlagNames(1);
                queueFamilyPropertyFlagNames.emplace_back(queueFamilyProperties.queueFlags | vk::QueueFlagBits::eGraphics ? "Graphics, " : "");
                queueFamilyPropertyFlagNames.emplace_back(queueFamilyProperties.queueFlags | vk::QueueFlagBits::eCompute ? "Compute, " : "");
                queueFamilyPropertyFlagNames.emplace_back(queueFamilyProperties.queueFlags | vk::QueueFlagBits::eTransfer ? "Transfer, " : "");
                queueFamilyPropertyFlagNames.emplace_back(queueFamilyProperties.queueFlags | vk::QueueFlagBits::eSparseBinding ? "SparseBinding" : "");

                for (const auto& queue_family_property_flag_name : queueFamilyPropertyFlagNames) {
                    std::cout << queue_family_property_flag_name ;
                }
                std::cout << std::endl;
            }
        }
    }


    //enumerateDeviceExtensionProperties()
    // const auto deviceExtensions = physicalDevices.front().

    instance.destroy();
    return 0;
}
