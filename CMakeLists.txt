project(GAME)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

file(GLOB_RECURSE proj_SRC
    "*.h"
    "*.cpp"
)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
include_directories("${PROJECT_SOURCE_DIR}")

link_libraries(SDL2main SDL2_image SDL2_ttf SDL2_mixer SDL2)

add_executable(${PROJECT_NAME} ${SRC_LIST})
#target_link_libraries(${PROJECT_NAME} engineLib)


