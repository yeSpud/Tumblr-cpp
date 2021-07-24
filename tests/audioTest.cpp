//
// Created by Spud on 7/22/21.
//

#include "catch2/catch.hpp"
#include "npf/content/audio.hpp"

TEST_CASE("Blank Audio Test", "[Audio]") {

	// Test empty audio
	Audio audio;

	REQUIRE(audio.type == "audio");
	REQUIRE(audio.url.empty());

	REQUIRE(audio.media.type.empty());
	REQUIRE(audio.media.url.empty());
	REQUIRE(audio.media.width == 0);
	REQUIRE(audio.media.height == 0);
	REQUIRE(audio.media.original_dimensions_missing);
	REQUIRE_FALSE(audio.media.cropped);
	REQUIRE_FALSE(audio.media.has_original_dimensions);

	REQUIRE(audio.provider.empty());
	REQUIRE(audio.title.empty());
	REQUIRE(audio.artist.empty());
	REQUIRE(audio.album.empty());

	REQUIRE(audio.poster.type.empty());
	REQUIRE(audio.poster.url.empty());
	REQUIRE(audio.poster.width == 0);
	REQUIRE(audio.poster.height == 0);
	REQUIRE(audio.poster.original_dimensions_missing);
	REQUIRE_FALSE(audio.poster.cropped);
	REQUIRE_FALSE(audio.poster.has_original_dimensions);

	REQUIRE(audio.embed_url.empty());
	REQUIRE(audio.embed_url.empty());

	REQUIRE(audio.attribution.type == 0);
	REQUIRE(audio.attribution.url.empty());
	REQUIRE(audio.attribution.postObject == nullptr);
	REQUIRE(audio.attribution.blogObject == nullptr);
	REQUIRE(audio.attribution.app_name.empty());
	REQUIRE(audio.attribution.display_text.empty());

	REQUIRE(audio.attribution.logo.type.empty());
	REQUIRE(audio.attribution.logo.url.empty());
	REQUIRE(audio.attribution.logo.width == 0);
	REQUIRE(audio.attribution.logo.height == 0);
	REQUIRE(audio.attribution.logo.original_dimensions_missing);
	REQUIRE_FALSE(audio.attribution.logo.cropped);
	REQUIRE_FALSE(audio.attribution.logo.has_original_dimensions);

}

TEST_CASE("Parsing Audio Test", "[Audio]") {

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

	// TODO

}
