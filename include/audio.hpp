//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_AUDIO_HPP
#define TUMBLRAPI_AUDIO_HPP

#include "attribution.hpp"
#include "image.hpp"

/**
 * TODO Documentation
 */
class Audio {

private:

	/**
	 * TODO Documentation
	 * @param url
	 */
	Audio(std::string url): url(std::move(url)){};

	/**
	 * TODO Documentation
	 * @param media
	 */
	Audio(Media media): media(std::move(media)){};

public:

	//struct Audio;

	/**
	 * TODO Documentation
	 */
	std::string type;

	/**
	 * The URL to use for the audio content, if no media is present.
	 */
	std::string url;

	/**
	 * TODO Documentation
	 */
	Media media;

	/**
	 * The provider of the audio source, whether it's tumblr for native audio or a trusted third party.
	 */
	std::string provider;

	/**
	 * The title of the audio asset.
	 */
	std::string title;

	/**
	 * The artist of the audio asset.
	 */
	std::string artist;

	/**
	 * The album from which the audio asset originated.
	 */
	std::string album;

	/**
	 * An image to use as a "poster" for the audio track, usually album art.
	 */
	Image poster;

	/**
	 * HTML code that could be used to embed this audio track into a webpage.
	 */
	std::string embed_html;

	/**
	 * A URL to the embeddable content to use as an iframe.
	 */
	std::string embed_url;

	// TODO
	// auto metadata;

	/**
	 * Attribution about where the audio track came from.
	 */
	Attribution attribution = Attribution(Attribution::post);

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Audio generateAudio(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_AUDIO_HPP
