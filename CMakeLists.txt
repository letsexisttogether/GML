cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Graphics mathematical library
project(GML LANGUAGES CXX)

#[[
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} 
    PRIVATE Source/Main.cpp)
]]

add_library(${PROJECT_NAME} STATIC)

add_subdirectory(Source)
add_subdirectory(Dependencies)
