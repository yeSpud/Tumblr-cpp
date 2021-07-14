cmake_minimum_required(VERSION 3.19)

project(
        TumblrAPI
        VERSION 2021.07.1
        DESCRIPTION "Tumblr API client written in C++"
        LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    set(CMAKE_CXX_STANDARD 20)

    set(CMAKE_CXX_EXTENSIONS OFF)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

endif ()

# ease of use stuff
include(ExternalProject)
include(FetchContent)

# rapidjson
include("${PROJECT_SOURCE_DIR}/vendor/rapidjson.cmake")
include_directories(${RAPIDJSON_INCLUDE_DIR})

# cpr
if (WIN32)
    set(DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(CPR_FORCE_WINSSL_BACKEND ON)
    set(DCPR_BUILD_TESTS_SSL ON)
endif (WIN32)
set(CPR_BUILD_TESTS OFF)
set(CPR_BUILD_TESTS_SSL OFF)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG origin/master)
FetchContent_MakeAvailable(cpr)

# include the src directory
add_subdirectory(src)

# add external libary dependencies
add_dependencies(TumblrAPI rapidjson)
target_link_libraries(TumblrAPI PRIVATE cpr::cpr)

message("Checking if we need to run tests")
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)# OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    message("Running tests")
    add_subdirectory(tests)
else ()
    message("Skipping tests")
endif ()
