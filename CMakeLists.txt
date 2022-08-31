cmake_minimum_required(VERSION 3.12)

project(
    chttpp
    VERSION 0.0.0
    DESCRIPTION "cpp http client lib"
    LANGUAGES CXX
    HOMEPAGE_URL "https://github.com/ixst/chttpp"
)

set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS_DEBUG -g)
set(CMAKE_CXX_FLAGS_RELEASE -Os)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

link_directories(
    ${CMAKE_SOURCE_DIR}/lib
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(app)

