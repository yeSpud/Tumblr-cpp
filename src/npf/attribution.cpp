//
// Created by Spud on 7/14/21.
//

#include "npf/attribution.hpp"

void Attribution::populateNPF(JSON_OBJECT entry) { // TODO Comments

	// Determine type.
	std::string typeString;
	objectHasValue(entry, "type", typeString);
	if (typeString == "link") {
		type = attribution_link;
	} else if (typeString == "blog") {
		type = attribution_blog;
	} else if (typeString == "post") {
		type = attribution_post;
	} else if (typeString == "app") {
		type = attribution_app;
	}

	objectHasValue(entry, "url", url);

	// Post pointer
	POPULATE_OBJECT(entry, "post", postObject = new Post();postObject->populatePost(entry["post"].GetObj());)

	// Blog pointer
	POPULATE_OBJECT(entry, "blog", blogObject = new Blog();blogObject->populateBlog(entry["blog"].GetObj());)

	objectHasValue(entry, "app_name", app_name);
	objectHasValue(entry, "display_text", display_text);

	// Logo
	POPULATE_OBJECT(entry, "logo", Media media;
			media.populateNPF(entry["logo"].GetObj());
			logo = media;)
}
