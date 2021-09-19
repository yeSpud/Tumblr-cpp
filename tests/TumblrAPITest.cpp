//
// Created by Spud on 7/24/21.
//

//#ifndef TUMBLRAPI_TEST_CPP
//#define TUMBLRAPI_TEST_CPP

#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include "TumblrAPI.hpp"
#include "blog.hpp"

std::unique_ptr<TumblrAPI> api;

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

	api = std::make_unique<TumblrAPI>(TumblrAPI(api_key));

	return session.run();
}

TEST_CASE("Test Blog Json", "[TumblrAPI]") {

	SECTION("Blog Info") {
		cpr::Response response = api->getBlogInfoJson("david.tumblr.com");
		REQUIRE(response.status_code == 200);
		REQUIRE(!response.text.empty());
		Blog blog = Blog::generateBlog(response.text.c_str());
		// TODO Test blog
	}

	SECTION("Blog Avatar") {
		cpr::Response response = api->getBlogAvatarJson("david.tumblr.com");
		REQUIRE(response.status_code == 200);
		REQUIRE(!response.text.empty());
		// It returns an image...
		// TODO Test blog avatar
	}

}

//#endif //TUMBLRAPI_TEST_CPP
