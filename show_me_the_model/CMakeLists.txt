cmake_minimum_required(VERSION 3.30)
project(show_me_the_model)

set(CMAKE_CXX_STANDARD 23)

add_executable(show_me_the_model)

set_target_properties(show_me_the_model PROPERTIES CXX_STANDARD 23)

target_sources(show_me_the_model
        PUBLIC
        main.cpp
        neftyUtility.hpp
)

#target_sources(show_me_the_model
#        PUBLIC
#        FILE_SET cpp_modules TYPE CXX_MODULES FILES
#        {Module name}
#)

target_include_directories(show_me_the_model PUBLIC C:/VulkanSDK/1.4.304.0/Include)
target_include_directories(show_me_the_model PUBLIC C:/msys64/ucrt64/include)
target_link_directories(show_me_the_model PUBLIC C:/VulkanSDK/1.4.304.0/Lib)
target_link_directories(show_me_the_model PUBLIC  C:/msys64/ucrt64/lib)
target_link_libraries(show_me_the_model vulkan-1 SDL2)

