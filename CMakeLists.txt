cmake_minimum_required(VERSION 3.10)

project(UltraSmartMatrix)
set(ULTRA_SMART_MATRIX_SRC main.cpp UltraSmartMatrix.cpp)
set(ULTRA_SMART_MATRIX_HDR UltraSmartMatrix.hpp)
add_executable(${PROJECT_NAME} ${ULTRA_SMART_MATRIX_SRC} ${ULTRA_SMART_MATRIX_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data.dat
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})