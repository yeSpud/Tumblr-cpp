//
// Created by Spud on 7/24/21.
//

//#ifndef TUMBLRAPI_TEST_CPP
//#define TUMBLRAPI_TEST_CPP

#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include "TumblrAPI.hpp"
#include "blogTest.hpp"

std::unique_ptr<TumblrAPI> apiPointer;

int main(int argc, char* argv[]) {

	Catch::Session session;

	std::string api_key;

	Catch::clara::Parser cli = session.cli() | Catch::clara::Opt(api_key, "api key")["-k"]
			["--api_key"]("The Tumblr API key.");

	session.cli(cli);

	int returnCode = session.applyCommandLine(argc, argv);
	if (returnCode != 0) {
		return returnCode;
	}

	apiPointer = std::make_unique<TumblrAPI>(TumblrAPI(api_key));

	return session.run();
}

TEST_CASE("Blog Tests", "[TumblrAPI]") {

	Blog davidBlog = Blog("david.tumblr.com", *apiPointer);

	SECTION("Blog Info") {

		// Test the blog info.
		/*
		 {
			"blog": {
			"ask": true,
			"ask_anon": false,
			"ask_page_title": "Ask me anything",
			"asks_allow_media": true,
			"can_chat": false,
			"can_subscribe": false,
			"description": "Est. 2006",
			"is_nsfw": false,
			"name": "david",
			"posts": 4955,
			"share_likes": false,
			"subscribed": false,
			"title": "David's Log",
			"total_posts": 4955,
			"updated": 1591035760,
			"url": "https://www.davidslog.com/",
			"uuid": "t:cCQ0A8KpxS8of3Op9-6PJA",
			"is_optout_ads": true
			}
		}
		 */
		BlogTest::testBlogInfo(davidBlog, true, false, "Ask me anything",
		                       true, false, false, "Est. 2006", false,
		                       "david", 4955, 0, false, false, "David's Log",
		                       4955, 1591035760, "", "", "https://www.davidslog.com/",
		                       "t:cCQ0A8KpxS8of3Op9-6PJA", false, true);
	}

	SECTION("Blog avatar") {

		// Test get avatar.
		BlogTest::testGetAvatar(davidBlog);
	}

	SECTION("Blog likes") {

		// Test getting blog likes.
		BlogTest::testGetLikes(davidBlog);
	}

	SECTION("Blog posts") {

		// Test getting blog posts.
		BlogTest::testGetPost(davidBlog);
	}

	SECTION("Blog notes") {

		// Get getting blog notes.
		BlogTest::testGetNotes(davidBlog);
	}

    // TODO Test other blog functions
}

//#endif //TUMBLRAPI_TEST_CPP
