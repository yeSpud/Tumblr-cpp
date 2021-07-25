# Tumblr-cpp
Tumblr API static library written in C++.

## Requirements

* C++ 17
* CMake 3.5

Any version greater than these listed will suffice.

### Dependencies used by the library

* [RapidJSON](https://github.com/tencent/rapidjson)
* [cpr](https://github.com/whoshuu/cpr)
* [Catch2](https://github.com/catchorg/Catch2/tree/v2.x) (Only for unit tests - not used in the actual library)

## Usage

### Adding with CMake

To add this library to your project using cmake add the following to your top level `CMakeLists.txt`:
```cmake
# TumblrAPI
#include(FetchContent) # If FetchContent wasnt declared before do it now by uncommenting this line
FetchContent_Declare(TumblrAPI GIT_REPOSITORY https://github.com/yeSpud/Tumblr-cpp.git GIT_TAG origin/main) # Pull from the main branch
FetchContent_MakeAvailable(TumblrAPI)
```

After doing that be sure to add it to your project target by adding the following near or at the bottom of the file:
```cmake
target_link_libraries(YOUR_PROJECT PRIVATE TumblrAPI::TumblrAPI ANY_ADDITIONAL_LIBRARIES_HERE)
```

## Contributing

Don't (for now at least).