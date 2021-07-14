//
// Created by Spud on 7/13/21.
//

#include "Content.hpp"
#include "TumblrAPI.hpp"

struct Video {

	/**
	 * TODO Documentation
	 */
	std::string type;

	/**
	 * The URL to use for the video content, if no media is present.
	 */
	std::string url;

	// TODO
	// auto media;

	/**
	 * The provider of the video, whether it's tumblr for native video or a trusted third party.
	 */
	std::string provider;

	/**
	 * HTML code that could be used to embed this video into a webpage.
	 */
	std::string embed_html;

	// TODO
	// auto embed_iframe;

	/**
	 * A URL to the embeddable content to use as an iframe.
	 */
	std::string embed_url;

	/**
	 * An image to use as a "poster" for the video, usually a single frame.
	 */
	Content::Image poster;

	// TODO
	// auto metadata;

	/**
	 * TODO Documentation
	 */
	Content::Attribution attribution;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	std::vector<Content::Image> filmstrip;

	/**
	 * Whether this video can be played on a cellular connection.
	 */
	bool can_autoplay_on_cellular;

};

// TODO Convert the bottom 3 into 1 with templating?
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
