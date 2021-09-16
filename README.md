# Tumblr-cpp
Tumblr API static library written in C++.

## Requirements

* C++ 17
* CMake 3.5

Any version greater than these listed will suffice.

### Dependencies used by the library

* [RapidJSON](https://github.com/tencent/rapidjson) (see license notice below)
* [cpr](https://github.com/libcpr/cpr)
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
# Because cpr is used in the api and the api requests return a cpr response object be sure to add cpr::cpr to your linked libraries.
# Remember: TumblrAPI is dependent on cpr (and thus cpr is included in TumblrAPI)
target_link_libraries(YOUR_PROJECT PRIVATE TumblrAPI::TumblrAPI cpr::cpr ANY_ADDITIONAL_LIBRARIES_HERE)
```

## Contributing

Don't (for now at least, or unless there is a glaring issue such as license or dependency issues).

## Copyright and Licensing

RapidJSON
```text
Tencent is pleased to support the open source community by making RapidJSON available.

Copyright (C) 2015 THL A29 Limited, a Tencent company, and Milo Yip.

Licensed under the MIT License (the "License"); you may not use this file except
in compliance with the License. You may obtain a copy of the License at

http://opensource.org/licenses/MIT

Unless required by applicable law or agreed to in writing, software distributed 
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
CONDITIONS OF ANY KIND, either express or implied. See the License for the 
specific language governing permissions and limitations under the License.
```