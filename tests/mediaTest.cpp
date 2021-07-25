//
// Created by Spud on 7/22/21.
//

#include "catch2/catch.hpp"
#include "mediaTest.hpp"
#include <iostream>

void MediaTest::testMedia(const Media &media, const std::string &type, const std::string &url, const int &width,
                          const int &height, const bool &original_dimensions_missing, const bool &cropped,
                          const bool &has_original_dimensions) { // TODO Comments

	std::cout << "\nTesting media..." << std::endl;

	REQUIRE(media.type == type);
	REQUIRE(media.url == url);
	REQUIRE(media.width == width);
	REQUIRE(media.height == height);
	REQUIRE(media.original_dimensions_missing == original_dimensions_missing);
	REQUIRE(media.cropped == cropped);
	REQUIRE(media.has_original_dimensions == has_original_dimensions);

	std::cout << "Media tested successfully!\n" << std::endl;

}

// TODO Rest of tests
