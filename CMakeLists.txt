project(GAME)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(src SRC_LIST)

#QTCreator precisa da lista de headers para adicionar ao projeto.
FILE(GLOB_RECURSE HEADER_LIST "include/*.h")

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
include_directories(${PROJECT_SOURCE_DIR}/include)

link_libraries(SDL2main SDL2_image SDL2_ttf SDL2_mixer SDL2)

add_executable(${PROJECT_NAME} main.cpp ${SRC_LIST} ${HEADER_LIST})



