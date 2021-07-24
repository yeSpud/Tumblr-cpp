//
// Created by Spud on 7/14/21.
//

#include "npf/content/audio.hpp"

void Audio::populateNPF(JSON_OBJECT entry) {

	objectHasValue(entry, "url", url);

	// Media
	POPULATE_OBJECT(entry, "media", Media audioMedia; audioMedia.populateNPF(entry["media"].GetObj()); media = audioMedia;)
	/*
	if (entry.HasMember("media")) {
		if (entry["media"].IsObject()) {
			Media audioMedia;
			audioMedia.populateNPF(entry["media"].GetObj());
			media = audioMedia;
		}
	}
	 */

	objectHasValue(entry, "provider", provider);
	objectHasValue(entry, "title", title);
	objectHasValue(entry, "artist", artist);
	objectHasValue(entry, "album", album);

	// Poster
	POPULATE_OBJECT(entry, "poster", Media posterMedia; posterMedia.populateNPF(entry["poster"].GetObj()); poster = posterMedia;)
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

	// TODO metadata (when implemented)

	// Attribution
	POPULATE_OBJECT(entry, "attribution", Attribution attr; attr.populateNPF(entry["attribution"].GetObj()); attribution = attr;)
	/*
	if (entry.HasMember("attribution")) {
		if (entry["attribution"].IsObject()) {
			Attribution attr;
			attr.populateNPF(entry["attribution"].GetObj());
			attribution = attr;
		}
	}
	 */

}
