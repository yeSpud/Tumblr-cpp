//
// Created by Spud on 7/13/21.
//

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "theme.hpp"

TEST_CASE("Theme test", "[Content]") {

	// Test empty theme
	Theme theme;
	REQUIRE(theme.avatar_shape.empty());
	REQUIRE(theme.background_color.empty());
	REQUIRE(theme.body_font.empty());
	// theme.header_bounds;
	REQUIRE(theme.header_image.empty());
	REQUIRE(theme.header_image_focused.empty());
	REQUIRE(theme.header_image_poster.empty());
	REQUIRE(theme.header_image_scaled.empty());
	REQUIRE_FALSE(theme.header_stretch);
	REQUIRE(theme.link_color.empty());
	REQUIRE_FALSE(theme.show_avatar);
	REQUIRE_FALSE(theme.show_description);
	REQUIRE_FALSE(theme.show_header_image);
	REQUIRE_FALSE(theme.show_title);
	REQUIRE(theme.title_color.empty());
	REQUIRE(theme.title_font.empty());
	REQUIRE(theme.title_font_weight.empty());

	// Test populating theme
	// TODO

	// Rerun tests on populated theme
	// TODO

	// Test new empty theme
	// TODO

}