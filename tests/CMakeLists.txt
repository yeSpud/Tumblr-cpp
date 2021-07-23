FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG 5c88067bd339465513af4aec606bd2292f1b594a)
FetchContent_MakeAvailable(Catch2)

add_executable(testlib audioTest.cpp formattingTest.cpp iframeTest.cpp imageTest.cpp mediaTest.cpp textTest.cpp themeTest.cpp videoTest.cpp)

target_compile_features(testlib PRIVATE cxx_std_17)

target_link_libraries(testlib PRIVATE TumblrAPI cpr::cpr Catch2::Catch2)

add_test(NAME testlibtest COMMAND testlib)
