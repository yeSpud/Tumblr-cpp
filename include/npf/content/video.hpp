//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_VIDEO_HPP
#define TUMBLRAPI_VIDEO_HPP

#include "image.hpp"
#include "iframe.hpp"

/**
 * TODO Documentation
 */
class Video: Content {

public:

	Video(): Content("video") {};

	/**
	 * The URL to use for the video content, if no media is present.
	 */
	std::string url;

	/**
	 * TODO Documentation
	 */
	Media media;

	/**
	 * The provider of the video, whether it's tumblr for native video or a trusted third party.
	 */
	std::string provider;

	/**
	 * HTML code that could be used to embed this video into a webpage.
	 */
	std::string embed_html;

	/**
	 * An embed iframe object used for constructing video iframes.
	 */
	iFrame embed_iframe;

	/**
	 * A URL to the embeddable content to use as an iframe.
	 */
	std::string embed_url;

	/**
	 * An image pointer to use as a "poster" for the video, usually a single frame.
	 */
	Image poster;

	// TODO
	// auto metadata;

	/**
	 * TODO Documentation
	 */
	Attribution attribution;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	std::vector<Image> filmstrip;

	/**
	 * Whether this video can be played on a cellular connection.
	 */
	bool can_autoplay_on_cellular;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_VIDEO_HPP
