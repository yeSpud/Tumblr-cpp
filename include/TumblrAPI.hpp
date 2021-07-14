//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_TUMBLRAPI_HPP
#define TUMBLRAPI_TUMBLRAPI_HPP

#include <string>
#include "cpr/cpr.h"

class TumblrAPI {

private:

	/**
	 * TODO Documentation
	 */
	const std::string token;

	/**
	 * TODO Documentation
	 * @param endpoint
	 * @param authRequired
	 * @param optionalParams
	 * @return
	 */
	cpr::Response sendRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams = "");

public:

	/**
	 * TODO Documentation
	 */
	struct Blog {

		// TODO

	};

	/**
	 * TODO Documentation
	 */
	struct Post {

		// TODO

	};

	/**
	 * TODO Documentaton
	 * @param json
	 * @return
	 */
	static Blog generateBlog(const char *json);

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static std::vector<Post> generatePosts(const char *json);

	/**
	 * TODO TODO Documentation
	 * @param token
	 */
	TumblrAPI(const std::string token):token(token){};

	cpr::Response getPostsJson(const std::string blogURL, const unsigned int number) {
		return sendRequest("blog/" + blogURL + "/posts", true, "&npf=true&limit=" + std::to_string(number));
	};

	cpr::Response getBlogInfoJson(const std::string blogURL) { return sendRequest("blog/" + blogURL + "/info", true); };

	cpr::Response getBlogAvatarJson(const std::string blogURL) { return sendRequest("blog/" + blogURL + "/avatar", false); };

};


#endif //TUMBLRAPI_TUMBLRAPI_HPP
