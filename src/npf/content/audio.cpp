//
// Created by Spud on 7/14/21.
//

#include "npf/content/audio.hpp"

void Audio::populateNPF(JSON_OBJECT entry) {

	objectHasValue(entry, "url", url);

	// Media
	POPULATE_OBJECT(entry, "media",
	                Media audioMedia; audioMedia.populateNPF(entry["media"].GetObj()); media = audioMedia;)

	objectHasValue(entry, "provider", provider);
	objectHasValue(entry, "title", title);
	objectHasValue(entry, "artist", artist);
	objectHasValue(entry, "album", album);

	// Poster - posters for audio objects are an array.
	POPULATE_ARRAY(entry, "poster", Media posterMedia; posterMedia.populateNPF(
			entry["poster"].GetArray()[0].GetObj()); poster = posterMedia;)

	objectHasValue(entry, "embed_html", embed_html);
	objectHasValue(entry, "embed_url", embed_url);

	// TODO metadata (when implemented)

	// Attribution
	POPULATE_OBJECT(entry, "attribution",
	                Attribution attr; attr.populateNPF(entry["attribution"].GetObj()); attribution = attr;)

}
