//
// Created by Spud on 7/24/21.
//

#include "catch2/catch.hpp"
#include "attributionTest.hpp"
#include <iostream>

void
AttributionTest::testAttribution(const Attribution &attribution, const attributionType &type, const std::string &url,
                                 const std::string &app_name, const std::string &display_text) { // TODO Comments

	std::cout << "\nTesting attribution..." << std::endl;

	REQUIRE(attribution.type == type);
	REQUIRE(attribution.url == url);
	REQUIRE(attribution.app_name == app_name);
	REQUIRE(attribution.display_text == display_text);

	std::cout << "Attribution tested successfully!\n" << std::endl;

}

/*
{
	"type": "app",
	"url": "https://www.instagram.com/p/BVZyxTklQWX/",
	"app_name": "Instagram",
	"display_text": "tibbythecorgi - Very Cute", // or "Listen on Bandcamp" for audio
	"logo": {
		"url": "https://scontent.cdninstagram.com/path/to/logo.jpg",
		"type": "image/jpeg",
		"width": 64,
		"height": 64
	}
}
 */


// TODO Rest of tests
