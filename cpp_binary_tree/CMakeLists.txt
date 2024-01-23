cmake_minimum_required(VERSION 3.0)
project(BinaryTree)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRL)

add_executable(${PROJECT_NAME} ${SRL})