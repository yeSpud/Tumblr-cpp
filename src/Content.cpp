//
// Created by Spud on 7/13/21.
//

#include "../include/Content.hpp"
#include "TumblrAPI.hpp"

struct Content::Attribution {

	/**
	 * The type of the attribution.
	 * Current valid values are "link", "blog", "post", or "app".
	 */
	std::string type; // TODO Make this into an enum

	/**
	 * The URL to be attributed.
	 */
	std::string url;

	/**
	 * A Post with at least the id field.
	 */
	TumblrAPI::Post post;

	/**
	 * A Blog with at least the uuid field.
	 */
	TumblrAPI::Blog blog;

	/**
	 * The name of the application to be attributed.
	 */
	std::string app_name;

	/**
	 * Any display text that the client should use with the attribution.
	 */
	std::string display_text;

	// TODO
	// auto logo;

};

bool Content::entryHasString(const rapidjson::Value &entry, const char *value, std::string &buffer) { // TODO Comments
	if (entry.HasMember(value)) {
		buffer = entry[value].GetString();
		return true;
	} else {
		return false;
	}
}

bool Content::entryHasNumber(const rapidjson::Value &entry, const char *value, uint64_t &buffer) { // TODO Comments
	if (entry.HasMember(value)) {
		buffer = entry[value].GetUint();
		return true;
	} else {
		return false;
	}
}

bool Content::entryHasBool(const rapidjson::Value &entry, const char *value, bool &buffer) { // TODO Comments
	if (entry.HasMember(value)) {
		buffer = entry[value].GetBool();
		return true;
	} else {
		return false;
	}
}

Content::Image Content::generateImage(const rapidjson::Value &entry) { // TODO Comments

	Content::Image image;

	if (entry.IsObject()) {
		std::string url;
		uint64_t width, height;

		if (!Content::entryHasString(entry, "url", url)) {
			return image;
		}

		if (!Content::entryHasNumber(entry, "width", width)) {
			return image;
		}

		if (!Content::entryHasNumber(entry, "height", height)) {
			return image;
		}

		image.width = width;
		image.height = height;
		image.url = url;
	}

	return image;
}
