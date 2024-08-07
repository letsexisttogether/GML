# This shit does not work not for a reason when being linked to a lib

# target_include_directories(${PROJECT_NAME}
#    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Vector)
add_subdirectory(Matrix)
add_subdirectory(Variations)

add_subdirectory(Utility)
