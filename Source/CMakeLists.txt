target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${PROJECT_NAME}
    PRIVATE Main.cpp)

add_subdirectory(Vector)
add_subdirectory(Matrix)
add_subdirectory(Transformation)
