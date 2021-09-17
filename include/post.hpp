//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_POST_HPP
#define TUMBLRAPI_POST_HPP

#include "blog.hpp"
#include "npf/layout/layout.hpp"
#include "npf/trail.hpp"

// Forward declarations to mitigate circular dependencies issues with attribution.hpp.
class Trail; // Forward declaration to mitigate circular dependencies.


/**
 * TODO Documentation
 */
class Post {

public:

	~Post();

	/**
	 * TODO Documentation
	 */
	enum postType {

		/**
		 * TODO Documentation
		 */
		text,

		/**
		 * TODO Documentation
		 */
		quote,

		/**
		 * TODO Documentation
		 */
		link,

		/**
		 * TODO Documentation
		 */
		answer,

		/**
		 * TODO Documentation
		 */
		video,

		/**
		 * TODO Documentation
		 */
		audio,

		/**
		 * TODO Documentation
		 */
		photo,

		/**
		 * TODO Documentation
		 */
		chat
	};

	/**
	 * TODO Documentation
	 */
	enum postFormat {

		/**
		 * TODO Documentation
		 */
		html,

		/**
		 * TODO Documentation
		 */
		markdown,

		/**
		 * Used if there is no post format provided.
		 */
		none

	};

	/**
	 * TODO Documentation
	 */
	enum postState {

		/**
		 * TODO Documentation
		 */
		published,

		/**
		 * TODO Documentation
		 */
		queued,

		/**
		 * TODO Documentation
		 */
		draft,

		/**
		 * TODO Documentation
		 */
		privat
	};

	/**
	 * The type of post.
	 */
	postType type = text;

	/**
	 * TODO Documentation
	 */
	std::string original_type;

	/**
	 * The short name used to uniquely identify a blog.
	 */
	std::string blog_name;

	/**
	 * TODO Documentation
	 */
	std::shared_ptr<Blog> blog;

	/**
	 * The post's unique ID.
	 */
	uint64_t id = 0;

	/**
	 * The post's unique ID as a String (For clients that don't support 64-bit integers).
	 */
	std::string id_string;

	/**
	 * The post's unique "genesis" ID as a string (only available to the post owner in certain circumstances).
	 */
	std::string genesis_post_id;

	/**
	 * The location of the post.
	 */
	std::string post_url;

	/**
	 * Short text summary to the end of the post URL.
	 */
	std::string slug;

	/**
	 * The GMT date and time of the post, as a string.
	 */
	std::string date;

	/**
	 * The time of the post, in seconds since the epoch.
	 */
	uint64_t timestamp = 0;

	/**
	 * The post format: html or markdown
	 */
	postFormat format = none;

	/**
	 * Indicates the current state of the post.
	 */
	postState state = published;

	/**
	 * The key used to reblog this post.
	 */
	std::string reblog_key;

	/**
	 * Tags applied to the post.
	 */
	std::vector<std::string> tags;

	/**
	 * Indicates whether the post was created via the Tumblr bookmarklet.
	 */
	bool bookmarklet = false;

	/**
	 * Indicates whether the post was created via mobile/email publishing.
	 */
	bool mobile = false;

	/**
	 * The URL for the source of the content (for quotes, reblogs, etc.).
	 */
	std::string source_url;

	/**
	 * The title of the source site.
	 */
	std::string source_title;

	/**
	 * Indicates if a user has already liked a post or not. Requires OAuth.
	 */
	bool liked = false;

	/**
	 * The total number of post available for this request, useful for paginating through results.
	 */
	uint64_t total_posts = 0;

	/**
	 * Short url for the post.
	 */
	std::string short_url;

	/**
	 * Author of post, only available when submission is not anonymous.
	 */
	std::string post_author;

	/**
	 * Indicates post is a submission.
	 */
	bool is_submission = false;

	/**
	 * Name on an anonymous submission.
	 */
	std::string anonymous_name;

	/**
	 * Email on an anonymous submission.
	 */
	std::string anonymous_email;

	/**
	 * TODO Documentation
	 */
	std::string summary;

	/**
	 * TODO Documentation
	 */
	bool should_open_in_legacy = false;

	/**
	 * TODO Documentation
	 */
	uint64_t note_count = 0;

	/**
	 * TODO Documentation
	 */
	std::vector<std::shared_ptr<Content>> content;

	/**
	 * TODO Documentation
	 */
	std::vector<std::shared_ptr<Layout>> layout;

	/**
	 * TODO Documentation
	 */
	std::vector<std::shared_ptr<Trail>> trails;

	/**
	 * TODO Documentation
	 */
	bool can_like = false;

	/**
	 * TODO Documentation
	 */
	bool can_reblog = false;

	/**
	 * TODO Documentation
	 */
	bool can_send_in_message = false;

	/**
	 * TODO Documentation
	 */
	bool can_reply = false;

	/**
	 * TODO Documentation
	 */
	bool display_avatar = false;

	// TODO Add post comparison (== and !=)

	/**
	 * TODO Documentation
	 * @param object
	 * @return
	 */
	void populatePost(const JSON_OBJECT &object);

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static std::vector<std::shared_ptr<Post>> generatePosts(const char *json);

};

#endif //TUMBLRAPI_POST_HPP
