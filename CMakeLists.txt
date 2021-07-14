cmake_minimum_required(VERSION 3.19)
project(TumblrAPI)

set(CMAKE_CXX_STANDARD 20)

# rapidjson
include(ExternalProject)
include("${CMAKE_SOURCE_DIR}/vendor/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

# cpr
include(FetchContent)
if(WIN32)
    set(DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(CPR_FORCE_WINSSL_BACKEND ON)
    set(DCPR_BUILD_TESTS_SSL ON)
endif(WIN32)
set(CPR_BUILD_TESTS OFF)
set(CPR_BUILD_TESTS_SSL OFF)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG origin/master)
FetchContent_MakeAvailable(cpr)

add_library(TumblrAPI src/Content.cpp src/Content.hpp)
add_dependencies(TumblrAPI rapidjson)
target_link_libraries(TumblrAPI PRIVATE cpr::cpr)