message("CMake version: ${CMAKE_VERSION} (should be at least 3.5)")
cmake_minimum_required(VERSION 3.5)

project(TumblrAPI
        VERSION 2021.09.15
        DESCRIPTION "Tumblr API client written in C++"
        LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    include(CTest)
endif ()
message("C++ standard: ${CMAKE_CXX_STANDARD} (should be at least 17)")

# ease of use stuff
include(ExternalProject)
include(FetchContent)

# spdlog
FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog.git GIT_TAG v1.10.0)
FetchContent_MakeAvailable(spdlog)
set(SPDLOG_BUILD_TESTS OFF)
set(SPDLOG_BUILD_TESTS_HO OFF)
set(SPDLOG_BUILD_ALL OFF)
set(SPDLOG_BUILD_EXAMPLE OFF)
set(SPDLOG_BUILD_EXAMPLE_HO OFF)

# cpr
cmake_policy(SET CMP0079 NEW)
if (WIN32)
    set(DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(CPR_FORCE_WINSSL_BACKEND ON)
    set(DCPR_BUILD_TESTS_SSL ON)
endif (WIN32)
set(CPR_BUILD_TESTS OFF)
set(CPR_BUILD_TESTS_SSL OFF)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG db351ffbbadc6c4e9239daaa26e9aefa9f0ec82d)
FetchContent_MakeAvailable(cpr)

# RapidJSON
include("${CMAKE_SOURCE_DIR}/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

# include the src directory
add_subdirectory(src)

# Attempt to add link library "cpr::cpr" and "spdlog::spdlog" to target "TumblrAPI" which is not built in this directory.
# This is allowed only when policy CMP0079 is set to NEW.
target_link_libraries(TumblrAPI PRIVATE cpr::cpr spdlog::spdlog)

message("Checking tests need to be included")
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message("Including tests")
    add_subdirectory(tests)
else ()
    message("Skipping tests")
endif ()
