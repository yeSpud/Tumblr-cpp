//
// Created by Spud on 6/25/22.
//

#ifndef TUMBLRAPI_MINIMAL_BLOG_HPP
#define TUMBLRAPI_MINIMAL_BLOG_HPP

#include "TumblrAPI.hpp"

class MinimalBlog {

public:

	MinimalBlog()= default;

	explicit MinimalBlog(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject) {

		TumblrAPI::setStringFromJson(jsonObject, "name", this->name);
		TumblrAPI::setStringFromJson(jsonObject, "title", this->title);
		TumblrAPI::setStringFromJson(jsonObject, "description", this->description);
		TumblrAPI::setStringFromJson(jsonObject, "url", this->url);
		TumblrAPI::setStringFromJson(jsonObject, "uuid", this->uuid);

		TumblrAPI::setUInt64FromJson(jsonObject, "updated", this->updated);
	}

	/**
	 * The short blog name that appears before tumblr.com in a standard blog hostname
	 */
	std::string name;

	/**
	 * The display title of the blog.
	 */
	std::string title;

	/**
	 * The blog's description.
	 */
	std::string description;

	/**
	 * Undocumented.
	 * The url of the blog. This is usually the blog identifier. Use the blog identifier.
	 */
	std::string url;

	/**
	 * Each blog also has a unique identifier that you can retrieve from any API response that includes a blog,
	 * in the uuid field (example: t:DvRFDGL05g8KB0gwiBJv1A).
	 */
	std::string uuid;

	/**
	 * The time of the most recent post, in seconds since the epoch.
	 */
	unsigned long long updated = 0;

};

#endif //TUMBLRAPI_MINIMAL_BLOG_HPP
