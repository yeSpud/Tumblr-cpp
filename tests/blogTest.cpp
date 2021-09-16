//
// Created by Spud on 7/24/21.
//

#include "blogTest.hpp"
#include "catch2/catch.hpp"
#include <iostream>

void BlogTest::testBlog(const Blog *blog, const bool &ask, const bool &ask_anon, const std::string &ask_page_title,
                        const bool &ask_allow_media, const bool &can_chat, const bool &can_subscribe,
                        const std::string &description, const bool &is_nsfw, const std::string &name,
                        const uint64_t &posts, const uint64_t &likes, const bool &shared_likes, const bool &subscribed,
                        const std::string &title, const uint64_t &total_posts, const uint64_t &updated,
                        const std::string &tz, const std::string &timezone_offset, const std::string &url,
                        const std::string &uuid, const bool &is_blocked_from_primary, const bool &is_optout_ads) {

	std::cout << "\nTesting blog..." << std::endl;

	if (blog == nullptr) {
		std::cout << "Blog is null so returning early.\n" << std::endl;
		return;
	}

	REQUIRE(blog->ask == ask);
	REQUIRE(blog->ask_anon == ask_anon);
	REQUIRE(blog->ask_page_title == ask_page_title);
	REQUIRE(blog->asks_allow_media == ask_allow_media);
	REQUIRE(blog->can_chat == can_chat);
	REQUIRE(blog->can_subscribe == can_subscribe);
	REQUIRE(blog->description == description);
	REQUIRE(blog->is_nsfw == is_nsfw);
	REQUIRE(blog->name == name);
	REQUIRE(blog->posts == posts);
	REQUIRE(blog->likes == likes);
	REQUIRE(blog->shared_likes == shared_likes);
	REQUIRE(blog->subscribed == subscribed);
	REQUIRE(blog->title == title);
	REQUIRE(blog->total_posts == total_posts);
	REQUIRE(blog->updated == updated);
	REQUIRE(blog->timezone == tz);
	REQUIRE(blog->timezone_offset == timezone_offset);
	REQUIRE(blog->url == url);
	REQUIRE(blog->uuid == uuid);
	REQUIRE(blog->is_blocked_from_primary == is_blocked_from_primary);
	REQUIRE(blog->is_optout_ads == is_optout_ads);

	std::cout << "Tested blog successfully!\n" << std::endl;

}

// TODO Rest of tests
