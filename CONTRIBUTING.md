# Contributing

## What needs to be done:

### Headers

#### [`audio_post.hpp`](/include/posts/audio_post.hpp)
* Metadata field needs to be implemented.

#### [`image_post.hpp`](/include/posts/image_post.hpp)
* Color field needs to be implemented.

#### [`video_post.hpp`](/include/posts/video_post.hpp)
* Metadata field needs to be implemented.

#### [`rows.hpp`](/include/layout/rows.hpp)
* Mode field needs to be implemented.

#### [`theme.hpp`](/include/theme.hpp)
* Header_bounds field needs to be implemented.

#### [`blog.hpp`](/include/blog.hpp)
* Getting the post queue needs to be implemented. Requires oAuth.
* Reordering the post queue needs to be implemented. Requires oAuth.
* Shuffling the queued posts needs to be implemented. Requires oAuth.
* Drafting posts needs to be implemented. Requires oAuth.
* Getting post submissions needs to be implemented. Requires oAuth.
* Getting notifications needs to be implemented. Requires oAuth.
* Creating new posts needs to be implemented. Requires oAuth.
* Fetching posts needs to be implemented. Requires oAuth.
* Editing posts needs to be implemented. Requires oAuth.
* Deleting posts needs to be implemented. Requires oAuth.
* Getting notes needs to be implemented. Requires API key.

#### [`TumblrAPI.hpp`](/include/TumblrAPI.hpp)
* oAuth needs to be implemented.
* Getting user info needs to be implemented. Requires oAuth.
* Getting the user dashboard needs to be implemented. Requires oAuth.
* Getting followers and following needs to be implemented.
* Unfollowing a user needs to be implemented. Requires oAuth.
* Liking a users post needs to be implemented. Requires oAuth.
* Unliking a users post needs to be implemented. Requires oAuth.
* Filtering content needs to be implemented. Requires oAuth.
* Tagged method needs to be implemented. Can require oAuth.

### Source files

#### [`blog.cpp`](/src/blog.cpp)
* getLikes method (needs to implement options and parse likes).

#### [`content.cpp`](/src/content.cpp)
* getContentFromJsonObject method should separate each text post type

#### [`layout.cpp`](/src/layout.cpp)
* getLayoutFromJsonObject method needs to check for carousel mode

### Test files - this just amounts to writing more unit tests

* [`blogTest.cpp`](/tests/blogTest.cpp)
* [`themeTest.cpp`](/tests/themeTest.cpp)
* [`TumblrAPITest.cpp`](/tests/TumblrAPITest.cpp)