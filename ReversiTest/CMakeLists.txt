cmake_minimum_required(VERSION 3.8)
project(ReversiTest)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(${ReversiTest_SOURCE_DIR}/lib/googletest-master)
include_directories(${reversi_SOURCE_DIR}/)
include_directories(${gtest_SOURCE_DIR}/include)

#Add project files
file(GLOB Reversi_Sources ${reversi_SOURCE_DIR}/src/*.cpp)
file(GLOB Test_Sources ${ReversiTest_SOURCE_DIR}/Tests/*.cpp)
set(SOURCE_FILES ${Test_Sources} ${Reversi_Sources})
list(REMOVE_ITEM SOURCE_FILES ${reversi_SOURCE_DIR}/src/main.cpp)


add_executable(ReversiTest ${SOURCE_FILES})
target_link_libraries(ReversiTest gtest gtest_main)
