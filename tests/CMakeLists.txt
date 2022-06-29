FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8)
FetchContent_MakeAvailable(Catch2)

file(GLOB TEST_HEADERS CONFIGURE_DEPENDS "./*.hpp")
file(GLOB TEST_SOURCE CONFIGURE_DEPENDS "./*.cpp")

add_executable(testlib ${TEST_HEADERS} ${TEST_SOURCE})

target_compile_features(testlib PRIVATE cxx_std_17)

target_link_libraries(testlib PRIVATE TumblrAPI cpr::cpr spdlog::spdlog Catch2::Catch2)