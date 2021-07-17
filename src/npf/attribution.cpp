//
// Created by Spud on 7/14/21.
//

#include "npf/attribution.hpp"

/*
{
	"type": "app",
	"url": "https://www.instagram.com/p/BVZyxTklQWX/",
	"app_name": "Instagram",
	"display_text": "tibbythecorgi - Very Cute", // or "Listen on Bandcamp" for audio
	"logo": {
		"url": "https://scontent.cdninstagram.com/path/to/logo.jpg",
		"type": "image/jpeg",
		"width": 64,
		"height": 64
	}
}
 */

void Attribution::populateNPF(JSON_OBJECT entry) { // TODO Comments

	// Determine type.
	std::string typeString;
	objectHasValue(entry, "type", typeString);
	if (typeString == "link") {
		type = link;
	} else if (typeString == "blog") {
		type = blog;
	} else if (typeString == "post") {
		type = post;
	} else if (typeString == "app") {
		type = app;
	}

	objectHasValue(entry, "url", url);

	// TODO Post pointer

	// TODO Blog pointer

	objectHasValue(entry, "app_name", app_name);
	objectHasValue(entry, "display_text", display_text);

	// Logo
	if (entry.HasMember("logo")) {
		if (entry["logo"].IsObject()) {
			Media media;
			media.populateNPF(entry["logo"].GetObj());
			logo = media;
		}
	}
}