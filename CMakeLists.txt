project(GAME)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
#add_subdirectory("${GAME_SOURCE_DIR}/engine")

file(GLOB_RECURSE proj_SRC
    "*.h"
    "*.cpp"
)
#include_directories(${untitled1_SOURCE_DIR}/include)
#link_directories(${untitled1_SOURCE_DIR}/src)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories(C:/SDL2-2.0.5/i686-w64-mingw32/include)

link_directories(C:/SDL2-2.0.5/i686-w64-mingw32/lib)
link_libraries(Mingw32 SDL2main SDL2_image SDL2_ttf SDL2_mixer SDL2)

add_executable(${PROJECT_NAME} ${SRC_LIST})
#target_link_libraries(${PROJECT_NAME} engineLib)


