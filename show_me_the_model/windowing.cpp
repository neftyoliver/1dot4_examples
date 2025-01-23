#pragma once

#include <memory>

#include "headerCollaction.hpp"
#include <stdlib.h>

struct WindowSettings { //no icon, not resizble, just a boring window.
    std::pair<uint32_t, uint32_t> windowSize = { 1920, 1080 };
    std::pair<uint32_t, uint32_t> windowPosition = { 0, 0 };
    const auto resizeable = false;
    const auto title = "SimpleModelRenderer";

};

struct SimpleVulkanWindow {
    auto settingsPtr = WindowSettings();

    auto window = std::unique_ptr<SDL_Window>();

    SimpleVulkanWindow() {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Vulkan_LoadLibrary(nullptr);
        this->window = std::unique_ptr<SDL_Window>(SDL_CreateWindow(
        this->settingsPtr.title.c_str(),
        this->settingsPtr.windowPosition.first, this->settingsPtr.windowPosition.second,
        this->settingsPtr.windowSize.first, this->settingsPtr.windowSize.second,
        SDL_WINDOW_SHOWN | this->settingsPtr.resizable | SDL_WINDOW_VULKAN
            ));
    }
    ~SimpleVulkanWindow() {
        SDL_DestroyWindow(this->window.get());
        SDL_Quit();
    }
};