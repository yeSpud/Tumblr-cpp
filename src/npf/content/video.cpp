//
// Created by Spud on 7/14/21.
//

#include "npf/content/video.hpp"

void Video::populateNPF(JSON_OBJECT entry) { // TODO Comments

	objectHasValue(entry, "url", url);

	// Media
	if (entry.HasMember("media")) {
		Media m;
		m.populateNPF(entry["media"].GetObj());
		media = m;
	}

	objectHasValue(entry, "provider", provider);
	objectHasValue(entry, "embed_html", embed_html);

	// iFrame
	if (entry.HasMember("embed_iframe")) {
		if (entry["embed_iframe"].IsObject()) {
			iFrame iframe;
			iframe.populateNPF(entry["embed_iframe"].GetObj());
			embed_iframe = iframe;
		}
	}

	objectHasValue(entry, "embed_url", embed_url);

	// Poster
	if (entry.HasMember("poster")) {
		if (entry["poster"].IsObject()) {
			Image image;
			image.populateNPF(entry["poster"].GetObj());
			poster = image;
		} else if (entry["poster"].IsArray()) {
			Image image;
			image.populateNPF(entry["poster"].GetArray()[0].GetObj());
			poster = image;
		}
	}

	// Attribution
	if (entry.HasMember("attribution")) {
		if (entry["attribution"].IsObject()) {
			Attribution attr;
			attr.populateNPF(entry["attribution"]);
			attribution = attr;
		}
	}

	// Filmstrip
	populateVectorObject(entry, "filmstrip", filmstrip);

	objectHasValue(entry, "can_autoplay_on_cellular", can_autoplay_on_cellular);

}
