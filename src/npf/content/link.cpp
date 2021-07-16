//
// Created by Spud on 7/14/21.
//

#include "npf/content/link.hpp"

/*
{
	"type": "link",
	"url": "https://www.nytimes.com/2017/06/15/us/politics/secrecy-surrounding-senate-health-bill-raises-alarms-in-both-parties.html",
	"title": "Secrecy Surrounding Senate Health Bill Raises Alarms in Both Parties",
	"description": "Senate leaders are writing legislation to repeal and replace the Affordable Care Act without a single hearing on the bill and without an open drafting session.",
	"author": "Thomas Kaplan and Robert Pear",
	"poster": [
		{
			"url": "https://static01.nyt.com/images/2017/06/15/us/politics/15dchealth-2/15dchealth-2-facebookJumbo.jpg",
			"type": "image/jpeg",
			"width": 1050,
			"height": 549
		}
	]
}
 */

Image getPoster(const JSON_OBJECT &entry) { // TODO Documentation
	Image image;
	image.populateNPF(entry);
	return image;
}

void Link::populateNPF(JSON_OBJECT entry) { // TODO Comments

	objectHasValue(entry, "url", url);
	objectHasValue(entry, "title", title);
	objectHasValue(entry, "description", description);
	objectHasValue(entry, "author", author);
	objectHasValue(entry, "site_name", site_name);
	objectHasValue(entry, "display_url", display_url);

	// Poster
	if (entry.HasMember("poster")) {
		if (entry["poster"].IsArray()) {
			poster = getPoster(entry["poster"].GetArray()[0].GetObj());
		} else if (entry["poster"].IsObject()) {
			poster = getPoster(entry["poster"].GetObj());
		}
	}
}
