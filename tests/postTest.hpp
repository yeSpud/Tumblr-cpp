//
// Created by Spud on 7/24/21.
//

#ifndef TUMBLRAPI_POSTTEST_HPP
#define TUMBLRAPI_POSTTEST_HPP


#include <post.hpp>

class PostTest {

public:

	/**
	 * TODO Documentation
	 *
	 * @param post
	 * @param postType
	 * @param original_type
	 * @param blog_name
	 * @param id
	 * @param id_string
	 * @param genesis_post_id
	 * @param post_url
	 * @param slug
	 * @param date
	 * @param timestamp
	 * @param format
	 * @param state
	 * @param reblog_key
	 * @param tags
	 * @param bookmarklet
	 * @param mobile
	 * @param source_url
	 * @param source_title
	 * @param liked
	 * @param total_posts
	 * @param short_url
	 * @param post_author
	 * @param is_submission
	 * @param anonymous_name
	 * @param anonymous_email
	 * @param summary
	 * @param should_open_in_legacy
	 * @param note_count
	 * @param can_like
	 * @param can_reblog
	 * @param can_send_in_message
	 * @param can_reply
	 * @param display_avatar
	 */
	static void
	testPost(const Post &post, const Post::postType &postType, const std::string &original_type,
	         const std::string &blog_name, uint64_t id, const std::string &id_string,
	         const std::string &genesis_post_id, const std::string &post_url,
	         const std::string &slug, const std::string &date, uint64_t timestamp, const Post::postFormat &format,
	         const Post::postState &state, const std::string &reblog_key, std::vector<std::string> tags,
	         bool bookmarklet, bool mobile, const std::string &source_url, const std::string &source_title, bool liked,
	         uint64_t total_posts, const std::string &short_url, const std::string &post_author, bool is_submission,
	         const std::string &anonymous_name, const std::string &anonymous_email, const std::string &summary,
	         bool should_open_in_legacy, uint64_t note_count, bool can_like, bool can_reblog, bool can_send_in_message,
	         bool can_reply, bool display_avatar);

};


#endif //TUMBLRAPI_POSTTEST_HPP
