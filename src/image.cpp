//
// Created by Spud on 7/14/21.
//

#include <vector>
#include "media.hpp"
#include "attribution.hpp"
#include "Content.hpp"
#include "image.hpp"

struct image::Image {

	/**
	 * The MIME type of the image asset, or a best approximation will be made based on the given URL
	 */
	std::string type;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	std::string media_key;

	/**
	 * TODO Documentation
	 */
	std::vector<media::MediaObject> media;

	// TODO
	// auto colors;

	/**
	 * TODO Documentation
	 */
	std::string feedback_token;

	/**
	 * TODO Documentation
	 */
	media::MediaObject poster;

	/**
	 * TODO Documentation
	 */
	attribution::Attribution *attribution;

	/**
	 * TODO Documentation
	 */
	std::string alt_text;

};

image::Image image::generateImage(const rapidjson::Value &entry) { // TODO Comments

	image::Image image;

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

		// FIXME
		/*
		image.width = width;
		image.height = height;
		image.url = url;
		image.has_original_dimensions = has_original_dimensions;
		 */
	}

	return image;
}