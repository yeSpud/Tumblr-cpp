//
// Created by Spud on 7/24/21.
//

#ifndef TUMBLRAPI_BLOGTEST_HPP
#define TUMBLRAPI_BLOGTEST_HPP

#include "blog.hpp"

class BlogTest {

public:

	/**
	 * TODO Documentation
	 * @param blog
	 * @param ask
	 * @param ask_anon
	 * @param ask_page_title
	 * @param ask_allow_media
	 * @param can_chat
	 * @param can_subscribe
	 * @param description
	 * @param is_nsfw
	 * @param name
	 * @param posts
	 * @param likes
	 * @param shared_likes
	 * @param subscribed
	 * @param title
	 * @param total_posts
	 * @param updated
	 * @param tz
	 * @param timezone_offset
	 * @param url
	 * @param uuid
	 * @param is_blocked_from_primary
	 * @param is_optout_ads
	 */
	static void testBlog(const Blog &blog, const bool &ask, const bool &ask_anon, const std::string &ask_page_title,
	                     const bool &ask_allow_media, const bool &can_chat, const bool &can_subscribe,
	                     const std::string &description, const bool &is_nsfw, const std::string &name,
	                     const uint64_t &posts, const uint64_t &likes, const bool &shared_likes, const bool &subscribed,
	                     const std::string &title, const uint64_t &total_posts, const uint64_t &updated,
	                     const std::string &tz, const std::string &timezone_offset, const std::string &url,
	                     const std::string &uuid, const bool &is_blocked_from_primary, const bool &is_optout_ads);

};

#endif //TUMBLRAPI_BLOGTEST_HPP
