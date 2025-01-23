
export module neftyUtility;

import std;

export namespace NU {


    void PrintDeviceInfo(std::vector<vk::PhysicalDevice> const& physicalDevices) {
        { /* this scope is just for printing. */
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