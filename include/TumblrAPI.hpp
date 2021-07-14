//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_TUMBLRAPI_HPP
#define TUMBLRAPI_TUMBLRAPI_HPP

#include <string>
#include <utility>
#include "Content.hpp"
#include "cpr/cpr.h"

class Content;

/**
 * TODO Documentation
 */
class TumblrAPI {

private:

	/**
	 * TODO Documentation
	 */
	const std::string token;

	/**
	 * TODO Documentation
	 * @param endpoint
	 * @param authRequired
	 * @param optionalParams
	 * @return
	 */
	cpr::Response sendRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams = "");

public:

	/**
	 * TODO Documentation
	 */
	struct Blog {

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
		std::vector<Content::Image> avatar;

		/**
		 * TODO Documentation
		 */
		bool can_chat;

		/**
		 * TODO Documentation
		 */
		bool can_subscribe;

		/**
		 * The blog's description
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
		Content::Theme theme;

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

	};

	/**
	 * TODO Documentation
	 */
	struct Post {

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
		std::vector<Content::Image> content;

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

	};

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static Blog generateBlog(const char *json);

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static std::vector<Post> generatePosts(const char *json);

	/**
	 * TODO TODO Documentation
	 * @param token
	 */
	TumblrAPI(std::string &token):token(std::move(token)){};

	/**
	 * This method returns general information about the blog, such as the title, number of posts,
	 * and other high-level data as a JSON object.
	 * @param blogURL
	 * @return
	 */
	cpr::Response getBlogInfoJson(const std::string& blogURL) { return sendRequest("blog/" + blogURL + "/info", true); };

	/**
	 * You can get a blog's avatar in 9 different sizes. The default size is 64x64.
	 * @param blogURL
	 * @return
	 */
	cpr::Response getBlogAvatarJson(const std::string& blogURL) { return sendRequest("blog/" + blogURL + "/avatar", false); };

	// TODO Blog blocks (both get, post, and delete)

	/**
	 * This method can be used to retrieve the publicly exposed likes from a blog.
	 * @param blogURL
	 * @return
	 */
	cpr::Response getBlogLikesJson(const std::string& blogURL) { return sendRequest("blog/" + blogURL + "/likes", true); };

	// TODO Blog following

	// TODO Blog followers

	// TODO Blog followed by

	/**
	 * TODO Documentation
	 * @param blogURL
	 * @param number
	 * @return
	 */
	cpr::Response getPostsJson(const std::string& blogURL, const unsigned int number) {return sendRequest("blog/" + blogURL + "/posts", true, "&npf=true&limit=" + std::to_string(number));};

	// TODO Post queue

	// TODO Reorder post queue

	// TODO Shuffle queued posts

	// TODO Draft posts

	// TODO Post submissions

	// TODO Notifications

	// TODO Create new posts

	// TODO Fetching and editing posts

	// TODO Deleting posts

	/**
	 * Get notes for a specific Post.
	 * @param blogURL
	 * @return
	 */
	cpr::Response getNotesJson(const std::string& blogURL) { return sendRequest("blog/" + blogURL + "/notes", true); };

	// TODO User info

	// TODO User dashboard

	// TODO User likes

	// TODO User following and follow

	// TODO Unfollow user

	// TODO Like a users post

	// TODO Unlike a users post

	// TODO Filtered content

	// TODO Tagged method

};


#endif //TUMBLRAPI_TUMBLRAPI_HPP
