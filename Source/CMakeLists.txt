target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Vector)
add_subdirectory(Matrix)
add_subdirectory(Variations)

add_subdirectory(Utility)
