//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_POST_HPP
#define TUMBLRAPI_POST_HPP

#include "image.hpp"

class Post {

public:

	//struct Post;

	/**
	 * TODO Documentation
	 */
	std::string type;

	/**
	 * TODO Documentation
	 */
	std::string original_type;

	/**
	 * TODO Documentation
	 */
	std::string blog_name;

	// TODO
	// const auto blog;

	/**
	 * TODO Documentation
	 */
	uint64_t id = 0;

	/**
	 * TODO Documentation
	 */
	std::string id_string;

	/**
	 * TODO Documentation
	 */
	std::string post_url;

	/**
	 * TODO Documentation
	 */
	std::string slug;

	/**
	 * TODO Documentation
	 */
	std::string date;

	/**
	 * TODO Documentation
	 */
	uint64_t timestamp = 0;

	/**
	 * TODO Documentation
	 */
	std::string state;

	/**
	 * TODO Documentation
	 */
	std::string reblog_key;

	// const auto tags;

	/**
	 * TODO Documentation
	 */
	std::string short_url;

	/**
	 * TODO Documentation
	 */
	std::string summary;

	/**
	 * TODO Documentation
	 */
	bool should_open_in_legacy;

	/**
	 * TODO Documentation
	 */
	uint64_t note_count = 0;

	/**
	 * TODO Documentation
	 */
	std::vector<Image> content;

	// const auto layout;

	// const auto trail;

	/**
	 * TODO Documentation
	 */
	bool can_like;

	/**
	 * TODO Documentation
	 */
	bool can_reblog;

	/**
	 * TODO Documentation
	 */
	bool can_send_in_message;

	/**
	 * TODO Documentation
	 */
	bool can_reply;

	/**
	 * TODO Documentation
	 */
	bool display_avatar;

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static std::vector<Post> generatePosts(const char *json);

};

#endif //TUMBLRAPI_POST_HPP
