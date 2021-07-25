# Contributing

## What needs to be done

### Headers

* audio.hpp - metadata field
* content.hpp - remove commented deprecation
* image.hpp - initialize attribution, colors field, fix destructor 
* text.hpp - initialize subtype
* video.hpp - initialize autoplay, metadata field
* condensed.hpp - initialize truncate_after
* rows.hpp - mode field, initialize truncate_after
* attribution.hpp - replace Image with media (?), convert logo to image(?)
* npf.hpp - remove commented-out code & includes
* trail.hpp - initialize post and blog, override destructor
* blog.hpp - convert type to enum, convert format to enum, convert state to enum, add overloaded operators
* theme.hpp - convert avatar_shape to enum, header_bounds field
* TumblrAPI.hpp - see file

13/25 (52%) done

### Headers documentation / comments

* audio.hpp
* content.hpp
* formatting.hpp
* iframe.hpp
* image.hpp
* link.hpp
* media.hpp
* text.hpp
* video.hpp
* ask.hpp
* carousel.hpp
* condensed.hpp
* layout.hpp
* rows.hpp
* attribution.hpp
* npf.hpp
* trail.hpp
* blog.hpp
* post.hpp
* theme.hpp
* TumblrAPI.hpp

### Source

* audio.cpp - metadata field
* image.cpp - remove commented-out code
* text.cpp - remove commented-out code, cleanup massive elseif statements (?)
* ask.cpp - remove commented-out code
* rows.cpp - removed commented-out code
* attribution.cpp - remove commented-out code
* trail.cpp - remove commented-out code, check content & layout pointer array, figure out carousel type 
* blog.cpp - remove commented out-code
* post.cpp - remove commented out-code
* theme.cpp - header_bounds field

13/22 (59%) done

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
* TumblrAPI.cpp

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
