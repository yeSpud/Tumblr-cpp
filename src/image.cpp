//
// Created by Spud on 7/14/21.
//

#include "image.hpp"

/*
struct image::Image {

	**
	 * The MIME type of the image asset, or a best approximation will be made based on the given URL
	 *
	std::string type;

	**
	 * TODO Documentation
	 * Undocumented?
	 *
	std::string media_key;

	**
	 * TODO Documentation
	 *
	std::vector<Media> media;

	// TODO
	// auto colors;

	**
	 * TODO Documentation
	 *
	std::string feedback_token;

	**
	 * TODO Documentation
	 *
	Media poster;

	**
	 * TODO Documentation
	 *
	Attribution attribution;

	**
	 * TODO Documentation
	 *
	std::string alt_text;

};
 */

Image Image::generateImage(const rapidjson::Value &entry) { // TODO Comments

	/* FIXME
	Image image;

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

	}

	return image;
	 */
}