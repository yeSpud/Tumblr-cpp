//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_BLOG_HPP
#define TUMBLRAPI_BLOG_HPP

#include <vector>
#include "image.hpp"
#include "theme.hpp"

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

	std::string ask_page_title;

	bool asks_allow_media;

	/**
	 * An array of avatar images, each a different size, which should each have a width, height, and URL.
	 */
	std::vector<image::Image *> avatar;

	bool can_chat;

	bool can_subscribe;

	std::string description;

	bool is_nsfw;

	/**
	 * The short blog name that appears before tumblr.com in a standard blog hostname
	 */
	std::string name;

	uint64_t posts;

	bool shared_likes;

	bool subscribed;

	/**
	 * The blog's general theme options, which may not be useful if the blog uses a custom theme.
	 */
	Theme theme;

	std::string title;

	uint64_t total_posts;

	uint64_t updated;

	std::string url;

	std::string uuid;

	bool is_optout_ads;

	//struct Blog;

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static Blog generateBlog(const char *json);

};

#endif //TUMBLRAPI_BLOG_HPP
