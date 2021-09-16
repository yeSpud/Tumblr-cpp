//
// Created by Spud on 7/13/21.
//

#include "catch2/catch.hpp"
#include "themeTest.hpp"
#include <iostream>

void ThemeTest::testTheme(const Theme &theme, const std::string &avatar_shape, const std::string &background_color,
                          const std::string &body_font, const std::string &header_image,
                          const std::string &header_image_focused, const std::string &header_image_poster,
                          const std::string &header_image_scaled, const bool &header_stretch,
                          const std::string &link_color, const bool &show_avatar, const bool &show_description,
                          const bool &show_header_image, const bool &show_title, const std::string &title_color,
                          const std::string &title_font, const std::string &title_font_weight) { // TODO Comments

	std::cout << "\nTesting theme..." << std::endl;

	REQUIRE(theme.avatar_shape == avatar_shape);
	REQUIRE(theme.background_color == background_color);
	REQUIRE(theme.body_font == body_font);
	// theme.header_bounds; // TODO Add when implemented
	REQUIRE(theme.header_image == header_image);
	REQUIRE(theme.header_image_focused == header_image_focused);
	REQUIRE(theme.header_image_poster == header_image_poster);
	REQUIRE(theme.header_image_scaled == header_image_scaled);
	REQUIRE(theme.header_stretch == header_stretch);
	REQUIRE(theme.link_color == link_color);
	REQUIRE(theme.show_avatar == show_avatar);
	REQUIRE(theme.show_description == show_description);
	REQUIRE(theme.show_header_image == show_header_image);
	REQUIRE(theme.show_title == show_title);
	REQUIRE(theme.title_color == title_color);
	REQUIRE(theme.title_font == title_font);
	REQUIRE(theme.title_font_weight == title_font_weight);

	std::cout << "Tested theme successfully!\n" << std::endl;

}

TEST_CASE("Blank Theme Test", "[Theme]") {

	// Test empty theme
	Theme theme;

	ThemeTest::testTheme(theme, "", "", "", "", "", "", "", false, "", false, false, false, false, "", "", "");

}

// TODO Add test for populating theme.
