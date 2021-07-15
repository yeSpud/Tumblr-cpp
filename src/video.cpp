//
// Created by Spud on 7/14/21.
//

#include <string>
#include <vector>
#include "image.hpp"
#include "attribution.hpp"
#include "video.hpp"

struct video::Video {

	/**
	 * TODO Documentation
	 */
	std::string type;

	/**
	 * The URL to use for the video content, if no media is present.
	 */
	std::string url;

	// TODO
	// auto media;

	/**
	 * The provider of the video, whether it's tumblr for native video or a trusted third party.
	 */
	std::string provider;

	/**
	 * HTML code that could be used to embed this video into a webpage.
	 */
	std::string embed_html;

	// TODO
	// auto embed_iframe;

	/**
	 * A URL to the embeddable content to use as an iframe.
	 */
	std::string embed_url;

	/**
	 * An image pointer to use as a "poster" for the video, usually a single frame.
	 */
	image::Image *poster;

	// TODO
	// auto metadata;

	/**
	 * TODO Documentation
	 */
	attribution::Attribution *attribution;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	std::vector<image::Image*> filmstrip;

	/**
	 * Whether this video can be played on a cellular connection.
	 */
	bool can_autoplay_on_cellular;

};
