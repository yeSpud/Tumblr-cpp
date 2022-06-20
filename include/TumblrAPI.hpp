//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_TUMBLRAPI_HPP
#define TUMBLRAPI_TUMBLRAPI_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <cpr/cpr.h>
#include <rapidjson/document.h>

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
	std::shared_ptr<spdlog::logger> logger;

	/**
	 * TODO Documentation
	 * @param token
	 */
	explicit TumblrAPI(std::string token): APIKey(std::move(token)) {

		// Setup the logger for fetching TumblrAPI stuff.
		this->logger = spdlog::basic_logger_mt("TumblrAPI Logger", "TumblrAPI-log.txt");
		this->logger->flush_on(spdlog::level::info);
		this->logger->info("Finished setting up logger for Tumblr API");
	};

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param key
	 * @return
	 */
	static const rapidjson::Value* setValueFromJson(const rapidjson::Value &jsonObject, const char *key);

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param key
	 * @param stringBuffer
	 */
	static void setStringFromJson(const rapidjson::Value &jsonObject, const char* key, std::string &stringBuffer);

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param key
	 * @param booleanBuffer
	 */
	static void setBooleanFromJson(const rapidjson::Value &jsonObject, const char* key, bool &booleanBuffer);

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param key
	 * @param numberBuffer
	 */
	static void setUInt64FromJson(const rapidjson::Value &jsonObject, const char* key, unsigned long long &numberBuffer);

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
