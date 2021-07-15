//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_VIDEO_HPP
#define TUMBLRAPI_VIDEO_HPP

#include "content.hpp"

/**
 * TODO Documentation
 */
class Video: Content {

private:

	explicit Video(std::string url): url(std::move(url)){};

	explicit Video(Media media): media(std::move(media)){};

public:

	//struct Video;

	/*
	 * TODO Documentation
	 */
	//std::string type;

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

	// TODO
	// auto embed_iframe;

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
	 * @return
	 */
	static Video generateVideo(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_VIDEO_HPP
