//
// Created by Spud on 7/14/21.
//

#include "npf/content/audio.hpp"

/*
{
	"content": [
		{
			"type": "audio",
			"provider": "tumblr",
			"title": "Track Title",
			"artist": "Track Artist",
			"album": "Track Album",
			"media": {
				"type": "audio/mp3",
				"url": "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1.mp3"
			},
			"poster": [
				{
					"type": "image/jpeg",
					"url": "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg",
					"width": 500,
					"height": 400
				}
			]
		}
	]
}
*/

/*
{
	"content": [
		{
			"type": "audio",
			"provider": "soundcloud",
			"title": "Mouth Sounds",
			"artist": "neilcic",
			"url": "https://soundcloud.com/neilcic/mouth-sounds",
			"embed_html": "<iframe width="100%" height="450" scrolling="no" frameborder="no" src="https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/146805680&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true"></iframe>",
			"embed_url": "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/146805680&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true",
			"media": {
				"type": "audio/mp3",
				"url": "https://soundcloud.com/neilcic/mouth-sounds.mp3"
			},
			"poster": [
				{
					"type": "image/jpeg",
					"url": "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg",
					"width": 500,
					"height": 400
				}
			]
		}
	]
}
*/


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
	POPULATE_OBJECT(entry, "poster", Image posterMedia; posterMedia.populateNPF(entry["poster"].GetObj()); poster = posterMedia;)
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

	// TODO Attribution
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
