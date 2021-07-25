//
// Created by Stephen Ogden on 7/24/21.
//

#ifndef TUMBLRAPI_MEDIATEST_HPP
#define TUMBLRAPI_MEDIATEST_HPP

#include "npf/content/media.hpp"

/**
 * TODO Documentation
 */
class MediaTest {

public:

	/**
	 * TODO Documentation
	 * @param media
	 * @param type
	 * @param url
	 * @param width
	 * @param height
	 * @param original_dimensions_missing
	 * @param cropped
	 * @param has_original_dimensions
	 */
	static void
	testMedia(const Media &media, const std::string &type, const std::string &url, const int &width, const int &height,
	          const bool &original_dimensions_missing, const bool &cropped, const bool &has_original_dimensions);

};

#endif //TUMBLRAPI_MEDIATEST_HPP
