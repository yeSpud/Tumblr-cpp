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
	bool ask_anon = false;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	std::string ask_page_title;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool asks_allow_media;

	/**
	 * An array of avatar images, each a different size, which should each have a width, height, and URL.
	 */
	std::vector<Image*> avatar; // Pointer array to mitigate circular dependencies issues with attribution.hpp and image.hpp.

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool can_chat;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool can_subscribe;

	/**
	 * The blog's description.
	 */
	std::string description;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool is_nsfw;

	/**
	 * The short blog name that appears before tumblr.com in a standard blog hostname
	 */
	std::string name;

	/**
	 * The total number of posts to this blog.
	 */
	uint64_t posts;

	/**
	 * Number of likes for this user.
	 */
	uint64_t likes = 0;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool shared_likes;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool subscribed;

	/**
	 * The blog's general theme options, which may not be useful if the blog uses a custom theme.
	 */
	Theme theme;

	/**
	 * The display title of the blog.
	 */
	std::string title;

	/**
	 * The total number of post available for this request, useful for paginating through results.
	 */
	uint64_t total_posts; // TODO Only in posts?

	/**
	 * The time of the most recent post, in seconds since the epoch.
	 */
	uint64_t updated;

	/**
	 * The blog's configured timezone, such as "US/Eastern". Only viewable by blog member. Partial response field ONLY.
	 */
	std::string timezone;

	/**
	 * The blog's configured timezone as a GMT offset such as "GMT+0800". Only viewable by blog member.
	 * Partial response field ONLY.
	 */
	std::string timezone_offset;

	/**
	 * TODO Documentation
	 */
	std::string url;

	/**
	 * TODO Documentation
	 */
	std::string uuid;

	/**
	 * Indicates whether this blog has been blocked by the calling user's primary blog
	 */
	bool is_blocked_from_primary = false;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool is_optout_ads;

	/**
	 * TODO Documentation
	 * @param object
	 * @return
	 */
	void populateBlog(const JSON_OBJECT &object);

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static Blog generateBlog(const char *json);

};

#endif //TUMBLRAPI_BLOG_HPP
