//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_LINK_HPP
#define TUMBLRAPI_LINK_HPP

#include "content.hpp"
#include "image.hpp"

/**
 * TODO Documentation
 */
class Link:Content {

private:

	/**
	 * TODO Documentation
	 * @param url
	 */
	explicit Link(std::string url): Content("link"), url(std::move(url)){};

public:

	/**
	 * The URL to use
	 */
	std::string url;

	/**
	 * The title of where the link goes.
	 */
	std::string title;

	/**
	 * The description of where the link goes.
	 */
	std::string description;

	/**
	 * The author of the link's content.
	 */
	std::string author;

	/**
	 * The name of the site being linked to.
	 */
	std::string site_name;

	/**
	 * TODO Documentation
	 */
	std::string display_url;

	/**
	 * An image to use as a "poster" for the link.
	 */
	Image poster;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Link generateLink(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_LINK_HPP
