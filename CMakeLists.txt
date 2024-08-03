cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Graphics mathematical library
project(GLM LANGUAGES CXX)

# Change to add_library()
add_executable(${PROJECT_NAME})

add_subdirectory(Source)
