//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_AUDIO_HPP
#define TUMBLRAPI_AUDIO_HPP

#include "content.hpp"
#include "image.hpp"
#include "npf/attribution.hpp" // Circular dependency with image.hpp

/**
 * An audio block represents a playable track. At a minimum, the provider field must be present,
 * and either the media field or url field must be present.
 * The provider field will indicate which embed provider is being used,
 * whether it's tumblr for Tumblr native audio content, or a trusted third party like spotify or bandcamp.
 * Optionally, an audio block may include the track's title, artist, and/or album.
 */
class Audio : public Content {

public:

	/**
	 * TODO Documentation
	 */
	Audio() : Content("audio") {};

	/**
	 * The URL to use for the audio content, if no media is present.
	 */
	std::string url;

	/**
	 * The Media object to use for the audio content, if no url is present.
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
	Attribution attribution;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_AUDIO_HPP
