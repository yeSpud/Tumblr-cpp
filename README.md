# Tumblr-cpp
Tumblr API static library written in C++.

## Requirements

* C++ 17
* CMake 3.5

Any version greater than these listed will suffice.

### Dependencies used by the library

* [RapidJSON](https://github.com/tencent/rapidjson) (see license notice below)
* [cpr](https://github.com/libcpr/cpr)
* [spdlog](https://github.com/gabime/spdlog)
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
target_link_libraries(YOUR_PROJECT PRIVATE TumblrAPI::TumblrAPI cpr::cpr spdlog::spdlog ANY_ADDITIONAL_LIBRARIES_HERE)
```

### Basic usage

Get started by creating a new [TumblrAPI](/include/TumblrAPI.hpp) object using your api key.
```cpp
TumblrAPI api = TumblrAPI("YOUR_API_KEY_HERE")
```

You can then retrieve blog info by creating a [blog](/include/blog.hpp) object. The blog's identifier as well as your API object are required.
```cpp
Blog blog = Blog("blog-identifier", api);
```

You can call other methods on the blog object once it has been created. Such as:
```cpp
std::string blogAvatar = blog.getAvatar(); // This will get the blog's avatar as a url. 

// If you want to get a specific size simply pass that as an argument to the function call.
std::string specificBlogAvatarSize = blog.getAvatar(16);

// You can also get the blogs likes. Not that this requires the blog to have shared_likes set to true.
if (blog.share_likes) {
	Blog::blogLikes blogLikes = blog.getLikes();
	// ...
}
```

In order to get [posts](/include/post.hpp) from the blog simply call `getPosts`.
```cpp
std::vector<Post> posts = blog.getPosts();
```

You can also specify the type of posts to get.
```cpp
std::vector<Post> videoPosts = blog.getPosts(Content::postType:video);
```

Or the number of posts to get. This example will only get the most recent post.
```cpp

// Here we are going to be a bit fancy.
// We want to get the most recent post type, 
// so set the type of posts to all types, 
// set the id to 0 (which will result in the id argument being excluded from the request paramenters),
// set the tag to an empty string (which will result in the tag argument being excluded from the request parameters),
// and set the number of results to 1.
// Then only get the 0th index (the first entry) of the returned posts.
Post mostRecentPost = blog.getPosts(Content::postType::all, 0, "", 1)[0];
```

Once you have the post you can then parse the content of the post based on its type.
```cpp
for (Post post : posts) {
    
	for (const auto& postContent : post.content) {
		
		switch(postContent->type) {
			case Content::text: {
				std::shared_ptr<Text> textPostPointer = std::static_pointer_cast<Text>(postContent);
				// Do whatever you need to do with a text post...
			}
			case Content::photo {
				std::shared_ptr<Image> imagePostPointer = std::static_pointer_cast<Image>(postContent);
				// Do what ever you need to do with an image post...
			}
			// You get the idea...
			
		}
	}
}
```
The different types of posts can be found in the [posts directory](/include/posts).

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