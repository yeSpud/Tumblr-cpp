//
// Created by Spud on 7/14/21.
//

#include "npf/attribution.hpp"

Attribution::~Attribution() = default;

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
	POPULATE_OBJECT(entry, "post", post = std::shared_ptr<Post>(new Post);post->populatePost(entry["post"].GetObj());)

	// Blog pointer
	POPULATE_OBJECT(entry, "blog", blog = std::shared_ptr<Blog>(new Blog);blog->populateBlog(entry["blog"].GetObj());)

	objectHasValue(entry, "app_name", app_name);
	objectHasValue(entry, "display_text", display_text);

	// Logo
	POPULATE_OBJECT(entry, "logo", Media media; media.populateNPF(entry["logo"].GetObj()); logo = media;)
}