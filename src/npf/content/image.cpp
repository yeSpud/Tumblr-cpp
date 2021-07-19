//
// Created by Spud on 7/14/21.
//

#include "npf/content/image.hpp"

/*
 * TODO Documentation & comments
 * @param entry
 * @return
 */
 /*
Media getMediaFromObject(const JSON_OBJECT &entry) {
	Media returnedMedia;
	returnedMedia.populateNPF(entry);
	return returnedMedia;
}
*/

void Image::populateNPF(JSON_OBJECT entry) { // TODO Comments

	objectHasValue(entry, "media_key", media_key);

	// Iterate to get media.
	populateVectorObject(entry, "media", media);
	/*
	if (entry.HasMember("media")) {
		if (entry["media"].IsArray()) {
			for (auto &mediaEntry : entry["media"].GetArray()) {
				if (mediaEntry.IsObject()) {
					Media mediaArray = getMediaFromObject(mediaEntry.GetObj());
					media.push_back(mediaArray);
				}
			}
		} else if (entry["media"].IsObject()) {
			Media mediaEntry = getMediaFromObject(entry["media"].GetObj());
			media.push_back(mediaEntry);
		}
	}
	 */

	/*
	populateSubgroup(entry, "media", []() {
		Media mediaEntry = getMediaFromObject(entry)
	});
	 */

	objectHasValue(entry, "feedback_token", feedback_token);

	// Get poster.
	POPULATE_SUBGROUP(entry, "poster",
	                  Media posterMedia;posterMedia.populateNPF(entry["poster"].GetObj());poster = posterMedia;)
	/*
	if (entry.HasMember("poster")) {
		if (entry["poster"].IsObject()) {
			Media posterMedia;
			posterMedia.populateNPF(entry["poster"].GetObj());
			poster = posterMedia;
		}
	}
	 */

	// Get attribution.
	POPULATE_SUBGROUP(entry, "attribution", Attribution attr;attr.populateNPF(
			entry["attribution"].GetObj());attribution = new Attribution;*attribution = attr;)
	/*
	if (entry.HasMember("attribution")) {
		if (entry["attribution"].IsObject()) {
			Attribution attr;
			attr.populateNPF(entry["attribution"].GetObj());
			attribution = new Attribution;
			*attribution = attr;
		}
	}
	 */

	objectHasValue(entry, "alt_text", alt_text);

}