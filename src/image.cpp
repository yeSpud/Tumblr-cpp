//
// Created by Spud on 7/14/21.
//

#include "image.hpp"

/*
Image Image::generateImage(const rapidjson::Value &entry) {


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

		/*
		image.width = width;
		image.height = height;
		image.url = url;
		image.has_original_dimensions = has_original_dimensions;

	}

	return image;

}
 */

/**
 * TODO Documentaiton & comments
 * @param entry
 * @return
 */
Media getMediaFromObject(const JSONOBJECT &entry) {

	Media returnedMedia;
	returnedMedia.populateNPF(entry);
	return returnedMedia;
}

void Image::populateNPF(JSONOBJECT entry) { // TODO Comments

	objectHasValue(entry, "media_key", media_key);

	// Iterate to get media.
	if (entry.HasMember("media")) {
		if (entry["media"].IsArray()) {
			for (auto& mediaEntry : entry["media"].GetArray()) {
				if (mediaEntry.IsObject()) {
					Media mediaArray = getMediaFromObject(mediaEntry);
					media.push_back(mediaArray);
				}
			}
		} else if (entry["media"].IsObject()) {
			Media mediaEntry = getMediaFromObject(entry["media"]);
			media.push_back(mediaEntry);
		}
	}

	objectHasValue(entry, "feedback_token", feedback_token);

	// Get poster.
	if (entry.HasMember("poster")) {
		if (entry["poster"].IsObject()) {
			Media posterMedia;
			posterMedia.populateNPF(entry["poster"].GetObj());
			poster = posterMedia;
		}
	}

	// TODO Attribution.

	objectHasValue(entry, "alt_text", alt_text);

}