cmake_minimum_required(VERSION 3.5)

# Set a default build type if none was specified

set(MY_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE ${MY_BUILD_TYPE} CACHE STRING "Choose the type of build." FORCE)
message("Setting build type to ${MY_BUILD_TYPE} as none was specified.")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
"MinSizeRel" "RelWithDebInfo")

project(build_type)

add_executable(build_type main.cpp)