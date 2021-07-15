//
// Created by Spud on 7/14/21.
//

#include <string>
#include "image.hpp"
#include "link.hpp"

struct link::Link {

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
	 * An image pointer to use as a "poster" for the link.
	 */
	image::Image *poster;

};
