message("CMake version: ${CMAKE_VERSION} (should be at least 3.5)")
cmake_minimum_required(VERSION 3.5)

project(
        TumblrAPI
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

# cpr
cmake_policy(SET CMP0079 NEW)
if (WIN32)
    set(DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(CPR_FORCE_WINSSL_BACKEND ON)
    set(DCPR_BUILD_TESTS_SSL ON)
endif (WIN32)
set(CPR_BUILD_TESTS OFF)
set(CPR_BUILD_TESTS_SSL OFF)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG origin/master)
FetchContent_MakeAvailable(cpr)

# include the src directory
add_subdirectory(src)

# Attempt to add link library "cpr::cpr" to target "TumblrAPI" which is not built in this directory.
# This is allowed only when policy CMP0079 is set to NEW.
target_link_libraries(TumblrAPI PRIVATE cpr::cpr)

message("Checking tests need to be included")
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message("Including tests")
    add_subdirectory(tests)
else ()
    message("Skipping tests")
endif ()
