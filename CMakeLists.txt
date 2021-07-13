cmake_minimum_required(VERSION 3.19)
project(TumblrAPI)

set(CMAKE_CXX_STANDARD 20)

# rapidjson
include(ExternalProject)
include("${CMAKE_SOURCE_DIR}/vendor/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

add_library(TumblrAPI src/Content.cpp src/Content.hpp)
add_dependencies(TumblrAPI rapidjson)