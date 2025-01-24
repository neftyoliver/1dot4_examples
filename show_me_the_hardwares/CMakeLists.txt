cmake_minimum_required(VERSION 3.30)
project(show_me_the_hardwares)

set(CMAKE_CXX_STANDARD 23)

add_executable(show_me_the_hardwares
        main.cpp
        instnceInformation.cpp
        instnceInformation.h)

set_target_properties(show_me_the_hardwares
        PROPERTIES COMPILE_WARNING_AS_ERROR ON
)


target_include_directories(show_me_the_hardwares PUBLIC C:/VulkanSDK/1.4.304.0/Include)
target_include_directories(show_me_the_hardwares PUBLIC C:/msys64/ucrt64/include)

target_link_directories(show_me_the_hardwares PUBLIC C:/VulkanSDK/1.4.304.0/Lib)
target_link_directories(show_me_the_hardwares PUBLIC  C:/msys64/ucrt64/lib)

target_link_libraries(show_me_the_hardwares vulkan-1)