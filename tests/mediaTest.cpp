//
// Created by Spud on 7/22/21.
//

#include "test.hpp"
#include "npf/content/media.hpp"

/**
 * TODO Documentation & comments
 * @param media
 * @param type
 * @param url
 * @param width
 * @param height
 * @param original_dimensions_missing
 * @param cropped
 * @param has_original_dimensions
 */
void testMedia(const Media &media, const std::string &type, const std::string &url, const int &width, const int &height,
               const bool &original_dimensions_missing, const bool &cropped,
               const bool &has_original_dimensions) {

	REQUIRE(media.type == type);
	REQUIRE(media.url == url);
	REQUIRE(media.width == width);
	REQUIRE(media.height == height);
	REQUIRE(media.original_dimensions_missing == original_dimensions_missing);
	REQUIRE(media.cropped == cropped);
	REQUIRE(media.has_original_dimensions == has_original_dimensions);

}

// TODO
