//
// Created by Spud on 7/14/21.
//

#include "image.hpp"

/**
 * TODO Documentation & comments
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