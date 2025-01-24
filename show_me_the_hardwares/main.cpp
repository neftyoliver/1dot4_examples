#include <iostream>
#include <cstdint>
#include <cctype>
#include <string>
#include <vulkan/vulkan.hpp>

#include "instnceInformation.h"

auto isNumber(const std::string& str) -> bool {
    for (const auto c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
        return true;
}

int main() {
    vk::Instance instance;
    vk::PhysicalDevice physicalDevice;


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
                case 1: {} break;
                case 2: {} break;
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
    }

    return 0;
}