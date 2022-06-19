//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_TUMBLRAPI_HPP
#define TUMBLRAPI_TUMBLRAPI_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <cpr/cpr.h>
#include "npf/npf.hpp"

/**
 * TODO Documentation
 */
class TumblrAPI {

private:

	/**
	 * Your OAuth Consumer Key.
	 */
	const std::string APIKey;

	//const auto oAuth; TODO

public:

	/**
	 * Logger for the TumblrAPI.
	 */
	static std::shared_ptr<spdlog::logger> logger;

	/**
	 * TODO Documentation
	 * @param token
	 */
	explicit TumblrAPI(std::string token): APIKey(std::move(token)) {

		// Setup the logger for fetching TumblrAPI stuff.
		TumblrAPI::logger = spdlog::basic_logger_mt("TumblrAPI Logger", "TumblrAPI-log.txt");
		TumblrAPI::logger->flush_on(spdlog::level::info);
		TumblrAPI::logger->info("Finished setting up logger for Tumblr API");
	};

	/**
	 * TODO Documentation
	 * @param endpoint
	 * @param authRequired
	 * @param optionalParams
	 * @return
	 */
	cpr::Response sendGetRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams = "") const;


	/**
	 * TODO Documentation
	 * @param jsonString
	 * @return
	 */
	rapidjson::GenericObject<false, rapidjson::Value> parseJsonResponse(const std::string& jsonString) const;

	/**
	 * TODO Documentation
	 * @param blogURL
	 * @param number
	 * @return
	 */
    [[deprecated("Use the blog to get posts")]]
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
