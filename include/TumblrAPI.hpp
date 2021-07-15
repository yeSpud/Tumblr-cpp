//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_TUMBLRAPI_HPP
#define TUMBLRAPI_TUMBLRAPI_HPP

#include <string>
#include <utility>
#include "cpr/cpr.h"
#include "Content.hpp"
#include "theme.hpp"
#include "image.hpp"

class Content;

/**
 * TODO Documentation
 */
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
	cpr::Response sendGetRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams = "");

public:

	/**
	 * TODO TODO Documentation
	 * @param token
	 */
	TumblrAPI(std::string &token):token(std::move(token)){};

	/**
	 * This method returns general information about the blog, such as the title, number of posts,
	 * and other high-level data as a JSON object.
	 * @param blogURL
	 * @return
	 */
	cpr::Response getBlogInfoJson(const std::string& blogURL) { return sendGetRequest("blog/" + blogURL + "/info", true); };

	/**
	 * You can get a blog's avatar in 9 different sizes. The default size is 64x64.
	 * @param blogURL
	 * @return
	 */
	cpr::Response getBlogAvatarJson(const std::string& blogURL) { return sendGetRequest("blog/" + blogURL + "/avatar",
	                                                                                    false); };

	// TODO Blog blocks (both get, post, and delete)

	/**
	 * This method can be used to retrieve the publicly exposed likes from a blog.
	 * @param blogURL
	 * @return
	 */
	cpr::Response getBlogLikesJson(const std::string& blogURL) { return sendGetRequest("blog/" + blogURL + "/likes",
	                                                                                   true); };

	// TODO Blog following

	// TODO Blog followers

	// TODO Blog followed by

	/**
	 * TODO Documentation
	 * @param blogURL
	 * @param number
	 * @return
	 */
	cpr::Response getPostsJson(const std::string& blogURL, const unsigned int number) {return sendGetRequest(
				"blog/" + blogURL + "/posts", true, "&npf=true&limit=" + std::to_string(number));};

	// TODO Post queue

	// TODO Reorder post queue

	// TODO Shuffle queued posts

	// TODO Draft posts

	// TODO Post submissions

	// TODO Notifications

	// TODO Create new posts

	// TODO Fetching and editing posts

	// TODO Deleting posts

	/**
	 * Get notes for a specific Post.
	 * @param blogURL
	 * @return
	 */
	cpr::Response getNotesJson(const std::string& blogURL) { return sendGetRequest("blog/" + blogURL + "/notes", true); };

	// TODO User info

	// TODO User dashboard

	// TODO User likes

	// TODO User following and follow

	// TODO Unfollow user

	// TODO Like a users post

	// TODO Unlike a users post

	// TODO Filtered content

	// TODO Tagged method

};


#endif //TUMBLRAPI_TUMBLRAPI_HPP
