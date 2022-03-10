//
// Created by Spud on 7/24/21.
//

#ifndef TUMBLRAPI_IMAGETEST_HPP
#define TUMBLRAPI_IMAGETEST_HPP

#include "npf/content/image.hpp"

/**
 * TODO Documentation
 */
class ImageTest {

public:

	/**
	 * TODO Documentation
	 * @param image
	 * @param media_key
	 * @param feedback_token
	 * @param alt_text
	 */
	static void testImage(const Image *image, const std::string &feedback_token, const std::string &alt_text);

};

#endif //TUMBLRAPI_IMAGETEST_HPP
