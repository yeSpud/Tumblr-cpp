cmake_minimum_required(VERSION 3.19)
project(TumblrAPI)

set(CMAKE_CXX_STANDARD 20)

# ease of use stuff
include(ExternalProject)
include(FetchContent)

# rapidjson
include("${CMAKE_SOURCE_DIR}/vendor/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

# cpr
if(WIN32)
    set(DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(CPR_FORCE_WINSSL_BACKEND ON)
    set(DCPR_BUILD_TESTS_SSL ON)
endif(WIN32)
set(CPR_BUILD_TESTS OFF)
set(CPR_BUILD_TESTS_SSL OFF)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG origin/master)
FetchContent_MakeAvailable(cpr)

# catch
FetchContent_Declare(Catch2 GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG origin/devel)
FetchContent_MakeAvailable(Catch2)

add_library(TumblrAPI src/Content.cpp src/Content.hpp src/TumblrAPI.cpp src/TumblrAPI.hpp)
add_dependencies(TumblrAPI rapidjson)
target_link_libraries(TumblrAPI PRIVATE cpr::cpr)

# tests
#add_executable(TumblrAPI test.cpp)
#target_link_libraries(TumblrAPI PRIVATE Catch2::Catch2)