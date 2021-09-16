# Contributing

## What needs to be done

### Headers

* [audio.hpp](/include/npf/content/audio.hpp) - metadata field
* [image.hpp](/include/npf/content/image.hpp) - colors field
* [video.hpp](/include/npf/content/video.hpp) - metadata field
* [rows.hpp](/include/npf/layout/rows.hpp) - mode field
* [attribution.hpp](/include/npf/attribution.hpp) - Fix circular dependencies
* [post.hpp](/include/post.hpp) - Fix circular dependencies, add overloaded operators
* [theme.hpp](/include/theme.hpp) - convert avatar_shape to enum, header_bounds field
* [TumblrAPI.hpp](/include/TumblrAPI.hpp) - see file

18/25 (72%) done

### Headers documentation / comments

* [audio.hpp](/include/npf/content/audio.hpp)
* [content.hpp](/include/npf/content/content.hpp)
* [formatting.hpp](/include/npf/content/formatting.hpp)
* [iframe.hpp](/include/npf/content/iframe.hpp)
* [image.hpp](/include/npf/content/image.hpp)
* [link.hpp](/include/npf/content/link.hpp)
* [media.hpp](/include/npf/content/media.hpp)
* [text.hpp](/include/npf/content/text.hpp)
* [video.hpp](/include/npf/content/video.hpp)
* [ask.hpp](/include/npf/layout/ask.hpp)
* [carousel.hpp](/include/npf/layout/carousel.hpp)
* [condensed.hpp](/include/npf/layout/condensed.hpp)
* [layout.hpp](/include/npf/layout/layout.hpp)
* [rows.hpp](/include/npf/layout/rows.hpp)
* [attribution.hpp](/include/npf/attribution.hpp)
* [npf.hpp](/include/npf/npf.hpp)
* [trail.hpp](/include/npf/trail.hpp)
* [blog.hpp](/include/blog.hpp)
* [post.hpp](/include/post.hpp)
* [theme.hpp](/include/theme.hpp)
* [TumblrAPI.hpp](/include/TumblrAPI.hpp)

### Source

* audio.cpp - metadata field
* text.cpp - cleanup massive elseif statements (?)
* video.cpp - metadata field
* rows.cpp - mode field
* attribution.cpp - cleanup massive elseif statements(?)
* trail.cpp - check content & layout pointer array, figure out carousel type, cleanup massive elseif statements(?)
* theme.cpp - header_bounds field

16/22 (73%) done

### Source documentation / comments

* audio.cpp
* formatting.cpp
* iframe.cpp
* image.cpp
* link.cpp
* media.cpp
* video.cpp
* ask.cpp
* carousel.cpp
* condensed.cpp
* rows.cpp
* attribution.cpp
* trail.cpp
* blog.cpp
* post.cpp
* theme.cpp

### Tests

* askTest.cpp
* askTest.hpp
* attributionTest.cpp
* audioTest.cpp - move post test to its own file
* blogTest.cpp
* carouselTest.cpp
* carouselTest.hpp
* condensedTest.cpp
* condensedTest.hpp
* iframeTest.cpp
* iframeTest.hpp
* imageTest.cpp
* imageTest.hpp
* mediaTest.cpp
* postTest.cpp
* postTest.hpp
* rowsTest.cpp
* rowsTest.hpp
* textTest.cpp
* textTest.hpp
* themeTest.cpp
* trailTest.cpp
* trailTest.hpp
* videoTest.cpp
* videoTest.hpp

10/34 (29%) done

### Test documentation / comments

* attributionTest.cpp
* attributionTest.hpp
* audioTest.cpp
* audioTest.hpp
* blogTest.hpp
* formattingTest.cpp
* formattingTest.hpp
* mediaTest.cpp
* mediaTest.hpp
* themeTest.cpp
* themeTest.hpp