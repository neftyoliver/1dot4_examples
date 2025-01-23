cmake_minimum_required(VERSION 3.30)
project(show_me_the_model)

set(CMAKE_CXX_STANDARD 23)

add_executable(show_me_the_model main.cpp
        )
target_include_directories(show_me_the_model PUBLIC C:/VulkanSDK/1.4.304.0/Include)
target_link_directories(show_me_the_model PUBLIC C:/VulkanSDK/1.4.304.0/Lib)
target_link_libraries(show_me_the_model vulkan-1)
