//
// Created by Spud on 7/22/21.
//

#include "imageTest.hpp"
#include "catch2/catch.hpp"

void ImageTest::testImage(const Image &image, const std::string &feedback_token, const std::string &alt_text) {

	// TODO Colors

	REQUIRE(image.feedback_token == feedback_token);
	REQUIRE(image.alt_text == alt_text);

}

