//
// Created by Spud on 7/14/21.
//

#include "npf/content/audio.hpp"

void Audio::populateNPF(JSON_OBJECT entry) {

	objectHasValue(entry, "url", url);

	// TODO Media

	objectHasValue(entry, "provider", provider);
	objectHasValue(entry, "title", title);
	objectHasValue(entry, "artist", artist);
	objectHasValue(entry, "album", album);

	// Poster
	POPULATE_SUBGROUP(entry, "poster",Image posterMedia; posterMedia.populateNPF(entry["poster"].GetObj()); poster = posterMedia;)
	/*
	if (entry.HasMember("poster")) {
		if (entry["poster"].IsObject()) {
			Image posterMedia;
			posterMedia.populateNPF(entry["poster"].GetObj());
			poster = posterMedia;
		}
	}
	 */

	objectHasValue(entry, "embed_html", embed_html);
	objectHasValue(entry, "embed_url", embed_url);

	// TODO Attribution

}
