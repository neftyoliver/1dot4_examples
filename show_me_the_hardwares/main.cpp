#include <iostream>
#include <cstdint>
#include <cctype>
#include <string>
#include <algorithm>
#include <vulkan/vulkan.hpp>

auto isNumber(const std::string& str) -> bool {
    return std::ranges::all_of(str, [&str](const char ch) { return std::isdigit(ch); });
}

int main() {
    std::vector<vk::LayerProperties> validInstanceLayers = vk::enumerateInstanceLayerProperties();
    std::vector<vk::ExtensionProperties> validInstanceExtensions = vk::enumerateInstanceExtensionProperties();


    vk::ApplicationInfo applicationInfo("", 0, "", 0);
    vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);
    vk::Instance instance = vk::createInstance(instanceCreateInfo);

    const auto physicalDevices = instance.enumeratePhysicalDevices();


    std::cout << "Welcome to the Hardware program!\n\n";
    std::cout << "1. view device list" << std::endl;
    std::cout << "2. select device" << std::endl;
    std::cout << "3. print selected device name" << std::endl;
    std::cout << "4. view selected device extensions" << std::endl;
    std::cout << "5. view instance extensions" << std::endl;
    std::cout << "6. view instance layer" << std::endl;
    std::cout << "0. quit" << std::endl;


    uint32_t deviceSelection = 0;
    uint32_t optionSelection = 0;

    while (true) {
        std::cout << ">";
        std::string input;
        std::cin >> input;

        if (isNumber(input)) {

            optionSelection = static_cast<uint32_t>(std::stoi(input));

            if (optionSelection == 0) {
                std::cout << "Quit" << std::endl;
                break;
            }

            switch (optionSelection) {
                case 1: {
                    uint32_t dev = 0;
                    for (auto value: physicalDevices) {
                        std::cout << dev << ". " << value.getProperties().deviceName << " ";
                        if (dev == deviceSelection) {
                            std::cout << " << " << std::endl;
                        }
                        std::cout << std::endl;
                        dev += 1;
                    }
                } break;
                case 2: {
                    std::cout << "Select device: ";
                    std::string dev;
                    std::cin >> dev;

                    dev.erase(dev.begin(), std::find_if(dev.begin(), dev.end(), [](const wchar_t w) {
                        return !std::isspace(w) || w == L'\n';
                    }));

                    if (!isNumber(dev)) {
                        std::cout << dev << " is not a number " << std::endl;
                        break;
                    }

                    if (const auto devIdx = static_cast<uint32_t>(std::stoi(dev)); devIdx > dev.size()) {
                        std::cout << "No device with number " << dev << std::endl;
                        break;
                    }

                    std::cout << deviceSelection << " is a selected device. " << std::endl;

                } break;
                case 3: {} break;
                case 4: {} break;
                case 5: {} break;
                case 6: {} break;
                default: std::cout << "Invalid selection" << std::endl; break;
            }
        }
        else {
            std::cout << input << " is not a number.\n";
            return 1;
        }


        LOOP_END:
    }

    return 0;
}