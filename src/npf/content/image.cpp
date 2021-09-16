//
// Created by Spud on 7/14/21.
//

#include "npf/content/image.hpp"

void Image::populateNPF(JSON_OBJECT entry) { // TODO Comments

	objectHasValue(entry, "media_key", media_key);

	// Iterate to get media.
	populateVectorObject(entry, "media", media);

	objectHasValue(entry, "feedback_token", feedback_token);

	// Get poster.
	POPULATE_OBJECT(entry, "poster", Media posterMedia;
			posterMedia.populateNPF(entry["poster"].GetObj());
			poster = posterMedia;)

	// Get attribution.
	POPULATE_OBJECT(entry, "attribution", Attribution attr;
			attr.populateNPF(entry["attribution"].GetObj());
			attribution = new Attribution;
			*attribution = attr;)

	objectHasValue(entry, "alt_text", alt_text);

}