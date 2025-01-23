#pragma once
#include <iostream>
#include <vector>
#include <vulkan/vulkan.hpp>

#define MAX_DEVICE_SUPPORT

namespace NU {
    namespace PRINT {
        inline void PrintInstanceExtensions() {
            std::cout << "Available Instance Extensions" << std::endl;
            for ( // In this for loop you can scan and detect instance extensions are available or not.
                const auto instanceExtensions = vk::enumerateInstanceExtensionProperties();
                const auto& extension : instanceExtensions
                ) {
                std::cout << extension.extensionName << " version: " << extension.specVersion << std::endl;
                }
            std::cout << std::endl;
        }

        inline void PrintDeviceInfo(std::vector<vk::PhysicalDevice> const& physicalDevices) {
            {
                std::cout << "Physical Devices and some information about them" << std::endl << std::endl;
                for (const auto& physicalDevice : physicalDevices) {
                    std::cout << "Vendor ID: " << physicalDevice.getProperties().deviceName << std::endl;
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
        }
    }

    inline auto findGraphicAndTransferQueueFamilyIndex(std::vector<vk::QueueFamilyProperties> vecQueueFamilyProperties) -> uint32_t {
        const auto queueFamilyGraphicsAndTransfer = std::ranges::find_if(vecQueueFamilyProperties,
                                                                         [](const vk::QueueFamilyProperties& queueFamilyProperties) {
                                                                             if (queueFamilyProperties.queueFlags | (vk::QueueFlagBits::eGraphics | vk::QueueFlagBits::eTransfer)){

                                                                                 return true;
                                                                             }

                                                                             return false;
                                                                         });

        const uint32_t index = std::distance(vecQueueFamilyProperties.begin(), queueFamilyGraphicsAndTransfer);

        std::cout << index << std::endl;

        return index;
    }
}