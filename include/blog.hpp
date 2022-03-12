//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_BLOG_HPP
#define TUMBLRAPI_BLOG_HPP

#include "theme.hpp"
#include "npf/content/media.hpp"

/**
 * TODO Documentation
 */
class Blog {

public:

	~Blog();

	/**
	 * Indicates whether the blog allows questions.
	 */
	bool ask = false;

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
	bool asks_allow_media = false;

	/**
	 * An array of avatar images, each a different size, which should each have a width, height, and URL.
	 */
	std::vector<Media> avatars;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool can_chat = false;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool can_subscribe = false;

	/**
	 * The blog's description.
	 */
	std::string description;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool is_nsfw = false;

	/**
	 * The short blog name that appears before tumblr.com in a standard blog hostname
	 */
	std::string name;

	/**
	 * The total number of posts to this blog.
	 */
	unsigned long long posts = 0;

	/**
	 * Number of likes for this user.
	 */
	unsigned long long likes = 0;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool shared_likes = false;

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	bool subscribed = false;

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
	unsigned long long total_posts = 0; // TODO Only in posts?

	/**
	 * The time of the most recent post, in seconds since the epoch.
	 */
	unsigned long long updated = 0;

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
	bool is_optout_ads = false;

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
