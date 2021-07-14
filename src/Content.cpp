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
		std::string media_key, media_type, url;
		uint64_t width, height;

		if (!Content::entryHasString(entry, "media_key", media_key)) {
			// Media key is not critical so for now just ignore it.
		}

		if (!Content::entryHasString(entry, "type", media_type)) {
			return image;
		}

		if (!Content::entryHasString(entry, "url", url)) {
			return image;
		}

		if (!Content::entryHasNumber(entry, "width", width)) {
			return image;
		}

		if (!Content::entryHasNumber(entry, "height", height)) {
			return image;
		}

		bool has_original_dimensions = entry.HasMember("has_original_dimensions");

		image.media_key = media_key;
		image.type = media_type;
		image.width = width;
		image.height = height;
		image.url = url;
		image.has_original_dimensions = has_original_dimensions;
	}

	return image;
}
