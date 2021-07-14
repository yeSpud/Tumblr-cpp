//
// Created by Spud on 7/13/21.
//

#include "Content.hpp"
#include "TumblrAPI.hpp"

struct Content::Attribution {

	/**
	 * The type of the attribution.
	 * Current valid values are "link", "blog", "post", or "app".
	 */
	Content::attributionType type;

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

	/**
	 * A specific logo that the client should use with the third-party app attribution.
	 */
	Content::Image logo;

};

struct Content::Audio {

	/**
	 * TODO Documentation
	 */
	std::string type;

	/**
	 * The URL to use for the audio content, if no media is present.
	 */
	std::string url;

	// TODO
	// auto media;

	/**
	 * The provider of the audio source, whether it's tumblr for native audio or a trusted third party.
	 */
	std::string provider;

	/**
	 * The title of the audio asset.
	 */
	std::string title;

	/**
	 * The artist of the audio asset.
	 */
	std::string artist;

	/**
	 * The album from which the audio asset originated.
	 */
	std::string album;

	/**
	 * An image to use as a "poster" for the audio track, usually album art.
	 */
	Content::Image poster;

	/**
	 * HTML code that could be used to embed this audio track into a webpage.
	 */
	std::string embed_html;

	/**
	 * A URL to the embeddable content to use as an iframe.
	 */
	std::string embed_url;

	// TODO
	// auto metadata;

	/**
	 * TODO Documentation
	 */
	Content::Attribution attribution;
};

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
