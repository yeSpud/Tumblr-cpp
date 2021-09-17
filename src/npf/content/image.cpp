//
// Created by Spud on 7/14/21.
//

#include "npf/content/image.hpp"

Image::~Image() = default;

void Image::populateNPF(JSON_OBJECT entry) { // TODO Comments

	// Iterate to get media.
	populateVectorObject(entry, "media", media);

	objectHasValue(entry, "feedback_token", feedback_token);

	// Get poster.
	POPULATE_OBJECT(entry, "poster", Media posterMedia;
			posterMedia.populateNPF(entry["poster"].GetObj());
			poster = posterMedia;)

	// Get attribution.
	POPULATE_OBJECT(entry, "attribution", Attribution attr;
			attribution = std::shared_ptr<Attribution>(new Attribution);
			attribution->populateNPF(entry["attribution"].GetObj());)

	objectHasValue(entry, "alt_text", alt_text);

}