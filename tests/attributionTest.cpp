//
// Created by Spud on 7/24/21.
//

#include "catch2/catch.hpp"
#include "attributionTest.hpp"

void AttributionTest::testAttribution(const Attribution &attribution, const attributionType &type, const std::string &url, const std::string &app_name,
                                      const std::string &display_text) { // TODO Comments

	REQUIRE(attribution.type == type);
	REQUIRE(attribution.url == url);
	REQUIRE(attribution.app_name == app_name);
	REQUIRE(attribution.display_text == display_text);

}

// TODO Rest of tests
