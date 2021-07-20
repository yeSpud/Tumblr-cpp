//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_BLOG_HPP
#define TUMBLRAPI_BLOG_HPP

#include "theme.hpp"
#include "npf/content/image.hpp"

// Forward declaration to mitigate circular dependencies issues with attribution.hpp and image.hpp.
class Image; // Actual image class is located in image.hpp.

/**
 * TODO Documentation
 */
class Blog {

public:

	/**
	 * Indicates whether the blog allows questions.
	 */
	bool ask;

	/**
	* Indicates whether the blog allows anonymous questions.
	*/
	bool ask_anon;

	/**
	 * TODO Documentation
	 */
	std::string ask_page_title;

	/**
	 * TODO Documentation
	 */
	bool asks_allow_media;

	/**
	 * An array of avatar images, each a different size, which should each have a width, height, and URL.
	 */
	std::vector<Image*> avatar; // Pointer array to mitigate circular dependencies issues with attribution.hpp and image.hpp.

	/**
	 * TODO Documentation
	 */
	bool can_chat;

	/**
	 * TODO Documentation
	 */
	bool can_subscribe;

	/**
	 * TODO Documentation
	 */
	std::string description;

	/**
	 * TODO Documentation
	 */
	bool is_nsfw;

	/**
	 * The short blog name that appears before tumblr.com in a standard blog hostname
	 */
	std::string name;

	/**
	 * TODO Documentation
	 */
	uint64_t posts;

	/**
	 * TODO Documentation
	 */
	bool shared_likes;

	/**
	 * TODO Documentation
	 */
	bool subscribed;

	/**
	 * The blog's general theme options, which may not be useful if the blog uses a custom theme.
	 */
	Theme theme;

	/**
	 * TODO Documentation
	 */
	std::string title;

	/**
	 * TODO Documentation
	 */
	uint64_t total_posts;

	/**
	 * TODO Documentation
	 */
	uint64_t updated;

	/**
	 * TODO Documentation
	 */
	std::string url;

	/**
	 * TODO Documentation
	 */
	std::string uuid;

	/**
	 * TODO Documentation
	 */
	bool is_optout_ads;

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static Blog generateBlog(const char *json);

};

#endif //TUMBLRAPI_BLOG_HPP
