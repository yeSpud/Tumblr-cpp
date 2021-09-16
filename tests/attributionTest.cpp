//
// Created by Spud on 7/24/21.
//

#include "catch2/catch.hpp"
#include "attributionTest.hpp"
#include "mediaTest.hpp"
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

TEST_CASE("Parsing Attribution Test", "[Attribution]") {

	/*
	{
		"type": "app",
		"url": "https://www.instagram.com/p/BVZyxTklQWX/",
		"app_name": "Instagram",
		"display_text": "tibbythecorgi - Very Cute",
		"logo": {
			"url": "https://scontent.cdninstagram.com/path/to/logo.jpg",
			"type": "image/jpeg",
			"width": 64,
			"height": 64
		}
	}
	 */

	rapidjson::Document appAttributionDocument;

	appAttributionDocument.Parse(R"({"type":"app","url":"https://www.instagram.com/p/BVZyxTklQWX/","app_name":"Instagram","display_text":"tibbythecorgi - Very Cute","logo":{"url":"https://scontent.cdninstagram.com/path/to/logo.jpg","type":"image/jpeg","width":64,"height":64}})");

	REQUIRE(appAttributionDocument.IsObject());

	REQUIRE(appAttributionDocument.HasMember("type"));
	REQUIRE(appAttributionDocument.HasMember("url"));
	REQUIRE(appAttributionDocument.HasMember("app_name"));
	REQUIRE(appAttributionDocument.HasMember("display_text"));
	REQUIRE(appAttributionDocument.HasMember("logo"));

	Attribution appAttribution;
	appAttribution.populateNPF(appAttributionDocument.GetObj());

	AttributionTest::testAttribution(appAttribution, attribution_app, "https://www.instagram.com/p/BVZyxTklQWX/",
									 "Instagram", "tibbythecorgi - Very Cute");

	MediaTest::testMedia(appAttribution.logo, "image/jpeg", "https://scontent.cdninstagram.com/path/to/logo.jpg", 64, 64, true, false,
	                     false);

	// TODO Rest of tests (other attribution types).
}
