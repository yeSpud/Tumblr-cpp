//
// Created by Spud on 7/22/21.
//

#include "imageTest.hpp"
#include "catch2/catch.hpp"
#include <iostream>

void ImageTest::testImage(const Image *image, const std::string &feedback_token, const std::string &alt_text) {

	std::cout << "\nTesting image..." << std::endl;

	if (image == nullptr) {
		std::cout << "Image is null!" << std::endl;
		return;
	}

	// TODO Colors

	REQUIRE(image->feedback_token == feedback_token);
	REQUIRE(image->alt_text == alt_text);

	std::cout << "Image tested successfully!\n" << std::endl;

}

