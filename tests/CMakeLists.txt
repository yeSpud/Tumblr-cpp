FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG origin/devel)
FetchContent_MakeAvailable(Catch2)

#add_executable(testlib ) TODO

#target_compile_features()

target_link_libraries(testlib PRIVATE TumblrAPI Catch2::Catch2)

#add_test()
