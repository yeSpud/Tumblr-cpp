//
// Created by Spud on 7/22/21.
//

#include "catch2/catch.hpp"
#include "npf/content/audio.hpp"

TEST_CASE("Blank Audio Test", "[Audio]") { // TODO Comments

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

	REQUIRE(audio.attribution.type == post);
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

TEST_CASE("Parsing Audio Test", "[Audio]") { // TODO Comments

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

	// Create document parsers for the tumblr and soundcloud json.
	rapidjson::Document tumblrAudioDocument, soundcloudAudioDocument;

	// Parse the strings into their respective document.
	tumblrAudioDocument.Parse(
			R"({"content": [{"type": "audio","provider": "tumblr","title": "Track Title","artist": "Track Artist","album": "Track Album","media": {"type": "audio/mp3","url": "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1.mp3"},"poster": [{"type": "image/jpeg","url": "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg","width": 500,"height": 400}]}]})");
	soundcloudAudioDocument.Parse(
			R"({"content": [{"type": "audio","provider": "soundcloud","title": "Mouth Sounds","artist": "neilcic","url": "https://soundcloud.com/neilcic/mouth-sounds","embed_html": "<iframe width=\"100%\" height=\"450\" scrolling=\"no\" frameborder=\"no\" src=\"https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/146805680&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true\"></iframe>","embed_url": "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/146805680&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true","media": {"type": "audio/mp3","url": "https://soundcloud.com/neilcic/mouth-sounds.mp3"},"poster": [{"type": "image/jpeg","url": "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg","width": 500,"height": 400}]}]})");

	// Get the content from the documents.
	REQUIRE(tumblrAudioDocument.IsObject());
	REQUIRE(soundcloudAudioDocument.IsObject());
	REQUIRE(tumblrAudioDocument.HasMember("content"));
	REQUIRE(soundcloudAudioDocument.HasMember("content"));
	JSON_ARRAY tumblrAudioContent = tumblrAudioDocument["content"].GetArray();
	JSON_ARRAY soundcloudAudioContent = soundcloudAudioDocument["content"].GetArray();

	// Get the first object in the content array.
	JSON_OBJECT tumblrAudioObject = tumblrAudioContent[0].GetObj();
	JSON_OBJECT soundcloudAudioObject = soundcloudAudioContent[0].GetObj();

	// Create the audio objects.
	Audio tumblrAudio, soundcloudAudio;

	// Populate the audio object.
	tumblrAudio.populateNPF(tumblrAudioObject);
	soundcloudAudio.populateNPF(soundcloudAudioObject);

	// Test the objects.

	/*
	 * Tumblr Audio
	 */
	REQUIRE(tumblrAudio.type == "audio");
	REQUIRE(tumblrAudio.url.empty());

	REQUIRE(tumblrAudio.media.type == "audio/mp3");
	REQUIRE(tumblrAudio.media.url == "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1.mp3");
	REQUIRE(tumblrAudio.media.width == 0);
	REQUIRE(tumblrAudio.media.height == 0);
	REQUIRE(tumblrAudio.media.original_dimensions_missing);
	REQUIRE_FALSE(tumblrAudio.media.cropped);
	REQUIRE_FALSE(tumblrAudio.media.has_original_dimensions);

	REQUIRE(tumblrAudio.provider == "tumblr");
	REQUIRE(tumblrAudio.title == "Track Title");
	REQUIRE(tumblrAudio.artist == "Track Artist");
	REQUIRE(tumblrAudio.album == "Track Album");

	REQUIRE(tumblrAudio.poster.type == "image/jpeg");
	REQUIRE(tumblrAudio.poster.url == "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg");
	REQUIRE(tumblrAudio.poster.width == 500);
	REQUIRE(tumblrAudio.poster.height == 400);
	REQUIRE(tumblrAudio.poster.original_dimensions_missing);
	REQUIRE_FALSE(tumblrAudio.poster.cropped);
	REQUIRE_FALSE(tumblrAudio.poster.has_original_dimensions);

	REQUIRE(tumblrAudio.embed_html.empty());
	REQUIRE(tumblrAudio.embed_url.empty());

	REQUIRE(tumblrAudio.attribution.type == post);
	REQUIRE(tumblrAudio.attribution.url.empty());
	REQUIRE(tumblrAudio.attribution.postObject == nullptr);
	REQUIRE(tumblrAudio.attribution.blogObject == nullptr);
	REQUIRE(tumblrAudio.attribution.app_name.empty());
	REQUIRE(tumblrAudio.attribution.display_text.empty());

	REQUIRE(tumblrAudio.attribution.logo.type.empty());
	REQUIRE(tumblrAudio.attribution.logo.url.empty());
	REQUIRE(tumblrAudio.attribution.logo.width == 0);
	REQUIRE(tumblrAudio.attribution.logo.height == 0);
	REQUIRE(tumblrAudio.attribution.logo.original_dimensions_missing);
	REQUIRE_FALSE(tumblrAudio.attribution.logo.cropped);
	REQUIRE_FALSE(tumblrAudio.attribution.logo.has_original_dimensions);

	/*
	 * Soundcloud audio
	 */
	REQUIRE(soundcloudAudio.type == "audio");
	REQUIRE(soundcloudAudio.url == "https://soundcloud.com/neilcic/mouth-sounds");

	REQUIRE(soundcloudAudio.media.type == "audio/mp3");
	REQUIRE(soundcloudAudio.media.url == "https://soundcloud.com/neilcic/mouth-sounds.mp3");
	REQUIRE(soundcloudAudio.media.width == 0);
	REQUIRE(soundcloudAudio.media.height == 0);
	REQUIRE(soundcloudAudio.media.original_dimensions_missing);
	REQUIRE_FALSE(soundcloudAudio.media.cropped);
	REQUIRE_FALSE(soundcloudAudio.media.has_original_dimensions);

	REQUIRE(soundcloudAudio.provider == "soundcloud");
	REQUIRE(soundcloudAudio.title == "Mouth Sounds");
	REQUIRE(soundcloudAudio.artist == "neilcic");
	REQUIRE(soundcloudAudio.album.empty());

	REQUIRE(soundcloudAudio.poster.type == "image/jpeg");
	REQUIRE(soundcloudAudio.poster.url == "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg");
	REQUIRE(soundcloudAudio.poster.width == 500);
	REQUIRE(soundcloudAudio.poster.height == 400);
	REQUIRE(soundcloudAudio.poster.original_dimensions_missing);
	REQUIRE_FALSE(soundcloudAudio.poster.cropped);
	REQUIRE_FALSE(tumblrAudio.poster.has_original_dimensions);

	REQUIRE(soundcloudAudio.embed_html == "<iframe width=\"100%\" height=\"450\" scrolling=\"no\" frameborder=\"no\" src=\"https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/146805680&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true\"></iframe>");
	REQUIRE(soundcloudAudio.embed_url == "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/146805680&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true");

	REQUIRE(soundcloudAudio.attribution.type == post);
	REQUIRE(soundcloudAudio.attribution.url.empty());
	REQUIRE(soundcloudAudio.attribution.postObject == nullptr);
	REQUIRE(soundcloudAudio.attribution.blogObject == nullptr);
	REQUIRE(soundcloudAudio.attribution.app_name.empty());
	REQUIRE(soundcloudAudio.attribution.display_text.empty());

	REQUIRE(soundcloudAudio.attribution.logo.type.empty());
	REQUIRE(soundcloudAudio.attribution.logo.url.empty());
	REQUIRE(soundcloudAudio.attribution.logo.width == 0);
	REQUIRE(soundcloudAudio.attribution.logo.height == 0);
	REQUIRE(soundcloudAudio.attribution.logo.original_dimensions_missing);
	REQUIRE_FALSE(soundcloudAudio.attribution.logo.cropped);
	REQUIRE_FALSE(soundcloudAudio.attribution.logo.has_original_dimensions);

}
