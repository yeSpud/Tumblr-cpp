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

// TODO Rest of tests
