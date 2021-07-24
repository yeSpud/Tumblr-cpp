//
// Created by Spud on 7/22/21.
//

#include "catch2/catch.hpp"
#include "npf/content/formatting.hpp"

TEST_CASE("Blank Formatting Test", "[Formatting]") {

	Formatting formatting;

	REQUIRE(formatting.type.empty());
	REQUIRE(formatting.start == 0);
	REQUIRE(formatting.end == 0);
	REQUIRE(formatting.url.empty());

	// Blog
	REQUIRE_FALSE(formatting.blog.ask);
	REQUIRE_FALSE(formatting.blog.ask_anon);
	REQUIRE(formatting.blog.ask_page_title.empty());
	REQUIRE_FALSE(formatting.blog.asks_allow_media);
	REQUIRE(formatting.blog.avatar.empty());
	REQUIRE_FALSE(formatting.blog.can_chat);
	REQUIRE_FALSE(formatting.blog.can_subscribe);
	REQUIRE(formatting.blog.description.empty());
	REQUIRE_FALSE(formatting.blog.is_nsfw);
	REQUIRE(formatting.blog.name.empty());
	REQUIRE(formatting.blog.posts == 0);
	REQUIRE(formatting.blog.likes == 0);
	REQUIRE_FALSE(formatting.blog.shared_likes);
	REQUIRE_FALSE(formatting.blog.subscribed);

	// Blog Theme
	REQUIRE(formatting.blog.theme.avatar_shape.empty());
	REQUIRE(formatting.blog.theme.background_color.empty());
	REQUIRE(formatting.blog.theme.body_font.empty());
	// theme.header_bounds; // TODO Add when implemented.
	REQUIRE(formatting.blog.theme.header_image.empty());
	REQUIRE(formatting.blog.theme.header_image_focused.empty());
	REQUIRE(formatting.blog.theme.header_image_poster.empty());
	REQUIRE(formatting.blog.theme.header_image_scaled.empty());
	REQUIRE_FALSE(formatting.blog.theme.header_stretch);
	REQUIRE(formatting.blog.theme.link_color.empty());
	REQUIRE_FALSE(formatting.blog.theme.show_avatar);
	REQUIRE_FALSE(formatting.blog.theme.show_description);
	REQUIRE_FALSE(formatting.blog.theme.show_header_image);
	REQUIRE_FALSE(formatting.blog.theme.show_title);
	REQUIRE(formatting.blog.theme.title_color.empty());
	REQUIRE(formatting.blog.theme.title_font.empty());
	REQUIRE(formatting.blog.theme.title_font_weight.empty());

	REQUIRE(formatting.blog.title.empty());
	REQUIRE(formatting.blog.total_posts == 0);
	REQUIRE(formatting.blog.updated == 0);
	REQUIRE(formatting.blog.timezone.empty());
	REQUIRE(formatting.blog.timezone_offset.empty());
	REQUIRE(formatting.blog.url.empty());
	REQUIRE(formatting.blog.uuid.empty());
	REQUIRE_FALSE(formatting.blog.is_blocked_from_primary);
	REQUIRE_FALSE(formatting.blog.is_optout_ads);

	REQUIRE(formatting.hex.empty());
}

TEST_CASE("Parsing Formatting Test", "[Formatting]") {

	// TODO

}
