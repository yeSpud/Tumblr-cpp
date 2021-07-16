//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_LINK_HPP
#define TUMBLRAPI_LINK_HPP

#include "npf/content/content.hpp"
#include "image.hpp"

/**
 * TODO Documentation
 */
class Link : Content {

public:

	/**
	 * TODO Documentation
	 */
	Link() : Content("link") {};

	/**
	 * The URL to use for the link content.
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
	 * Supplied on NPF Post consumption, ignored during NPF Post creation.
	 */
	std::string display_url;

	/**
	 * An image to use as a "poster" for the link.
	 */
	Image poster;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_LINK_HPP
