//
// Created by Spuds on 7/24/21.
//

#include "catch2/catch.hpp"
#include "audioTest.hpp"
#include <iostream>
#include "mediaTest.hpp"
#include "attributionTest.hpp"
#include "blogTest.hpp"

void
AudioTest::testAudio(const Audio &audio, const std::string &url, const std::string &provider, const std::string &title,
                     const std::string &artist, const std::string &album, const std::string &embed_html,
                     const std::string &embed_url) { // TODO Comments

	std::cout << "\nTesting audio..." << std::endl;

	REQUIRE(audio.type == "audio");
	REQUIRE(audio.url == url);
	REQUIRE(audio.provider == provider);
	REQUIRE(audio.title == title);
	REQUIRE(audio.artist == artist);
	REQUIRE(audio.album == album);
	REQUIRE(audio.embed_html == embed_html);
	REQUIRE(audio.embed_url == embed_url);

	std::cout << "Tested audio successfully!\n" << std::endl;

}

TEST_CASE("Blank Audio Test", "[Audio]") {

	// Test an empty audio object.
	Audio audio;
	AudioTest::testAudio(audio, "", "", "", "", "", "", "");

	// Test the media.
	MediaTest::testMedia(audio.media, "", "", 0, 0, true, false, false);

	// Test the poster.
	MediaTest::testMedia(audio.poster, "", "", 0, 0, true, false, false);

	// Test the attributions.
	AttributionTest::testAttribution(audio.attribution, attribution_post, "", "", "");

	// TODO Create own tests for these in separate files.
	REQUIRE(audio.attribution.postObject == nullptr);
	REQUIRE(audio.attribution.blogObject == nullptr);

	// Test the attribution logo.
	MediaTest::testMedia(audio.attribution.logo, "", "", 0, 0, true, false, false);

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
	AudioTest::testAudio(tumblrAudio, "", "tumblr", "Track Title", "Track Artist", "Track Album", "", "");
	MediaTest::testMedia(tumblrAudio.media, "audio/mp3",
	                     "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1.mp3",
	                     0, 0, true, false, false);
	MediaTest::testMedia(tumblrAudio.poster, "image/jpeg",
	                     "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg",
	                     500, 400, true, false, false);
	AttributionTest::testAttribution(tumblrAudio.attribution, attribution_post, "", "", "");

	// TODO Move this to its own separate file.
	REQUIRE(tumblrAudio.attribution.postObject == nullptr);

	BlogTest::testBlog(tumblrAudio.attribution.blogObject, false, false, "", false, false, false, "", false, "", 0, 0,
	                   false, false, "", 0, 0, "", "", "", "", false, false);
	MediaTest::testMedia(tumblrAudio.attribution.logo, "", "", 0, 0, true, false, false);

	/*
	 * Soundcloud audio
	 */
	AudioTest::testAudio(soundcloudAudio, "https://soundcloud.com/neilcic/mouth-sounds", "soundcloud", "Mouth Sounds",
	                     "neilcic", "",
	                     R"(<iframe width="100%" height="450" scrolling="no" frameborder="no" src="https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/146805680&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true"></iframe>)",
	                     "https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/146805680&amp;auto_play=false&amp;hide_related=false&amp;show_comments=true&amp;show_user=true&amp;show_reposts=false&amp;visual=true");
	MediaTest::testMedia(soundcloudAudio.media, "audio/mp3", "https://soundcloud.com/neilcic/mouth-sounds.mp3", 0, 0,
	                     true, false, false);
	MediaTest::testMedia(soundcloudAudio.poster, "image/jpeg",
	                     "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg",
	                     500, 400, true, false, false);
	AttributionTest::testAttribution(soundcloudAudio.attribution, attribution_post, "", "", "");

	// TODO Move this to its own separate file.
	REQUIRE(soundcloudAudio.attribution.postObject == nullptr);

	BlogTest::testBlog(soundcloudAudio.attribution.blogObject, false, false, "", false, false, false, "", false, "", 0,
	                   0, false, false, "", 0, 0, "", "", "", "", false, false);
	MediaTest::testMedia(soundcloudAudio.attribution.logo, "", "", 0, 0, true, false, false);
}
