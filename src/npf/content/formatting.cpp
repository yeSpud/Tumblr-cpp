//
// Created by Spud on 7/16/21.
//

#include "npf/content/formatting.hpp"

void Formatting::populateNPF(JSON_OBJECT entry) { // TODO Comments

	objectHasValue(entry, "type", type);
	objectHasValue(entry, "start", start);
	objectHasValue(entry, "end", end);
	objectHasValue(entry, "url", url);

	// FIXME
	POPULATE_OBJECT(entry, "blog", const char* blogString = entry["blog"].GetString();blog = Blog::generateBlog(blogString);)

	objectHasValue(entry, "hex", hex);

}
