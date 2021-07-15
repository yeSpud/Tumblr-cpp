//
// Created by Spud on 7/14/21.
//

#include "audio.hpp"

/*
struct audio::Audio {

	std::string type;

	**
	 * The URL to use for the audio content, if no media is present.
	 *
	std::string url;

	// TODO
	// auto media;

	**
	 * The provider of the audio source, whether it's tumblr for native audio or a trusted third party.
	 *
	std::string provider;

	**
	 * The title of the audio asset.
	 *
	std::string title;

	**
	 * The artist of the audio asset.
	 *
	std::string artist;

	**
	 * The album from which the audio asset originated.
	 *
	std::string album;

	**
	 * An image pointer to use as a "poster" for the audio track, usually album art.
	 *
	image::Image *poster;

	**
	 * HTML code that could be used to embed this audio track into a webpage.
	 *
	std::string embed_html;

	**
	 * A URL to the embeddable content to use as an iframe.
	 *
	std::string embed_url;

	// TODO
	// auto metadata;

	**
	 * Attribution about where the audio track came from.
	 *
	Attribution attribution;
};
*/

Audio Audio::generateAudio(const rapidjson::Value &entry) {
	// TODO
}
