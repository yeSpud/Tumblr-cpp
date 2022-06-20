//
// Created by Spud on 6/16/22.
//

#ifndef TUMBLRAPI_ABSTRACT_POST_HPP
#define TUMBLRAPI_ABSTRACT_POST_HPP

#include "TumblrAPI.hpp"

class Post {

public:

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
		chat,

		/**
		 * TODO Documentation
		 */
		all
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
	 * Undocumented.
	 * TODO Documentation
	 */
	std::string original_type;

	/**
	 * The short name used to uniquely identify a blog.
	 */
	std::string blog_name;

	/**
	 * The post's unique ID.
	 */
	long long id = 0;

	/**
	 * The post's unique ID as a string.
	 * For clients that don't support 64-bit integers.
	 */
	std::string id_string;

	/**
	 * The post's unique "genesis" ID as a string. Only available to the post owner in certain circumstances.
	 * <br>
	 * The "genesis" ID for a post is only available and different than its current ID if that post had been drafted,
	 * queued, or scheduled, and is now published.
	 * In which case, the "genesis" ID will be the original post ID generated when drafting, queuing, or scheduling that post.
	 * You cannot use this ID to look up the post after it has been published,
	 * but it can be useful for tracking a post from its pre- to post-published state.
	 */
	std::string genesis_post_id;

	/**
	 * The location of the post.
	 */
	std::string post_url;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	std::string slug;

	/**
	 * The type of post.
	 */
	const postType type;

	/**
	 * The time of the post, in seconds since the epoch.
	 */
	long long timestamp = 0;

	/**
	 * The GMT date and time of the post, as a string.
	 */
	std::string date;

	/**
	 * The post format: html or markdown.
	 */
	Post::postFormat format;

	/**
	 * The key used to reblog this post.
	 */
	std::string reblog_key;

	/**
	 * Tags applied to the post.
	 */
	std::string tags;

	/**
	 * Indicates whether the post was created via the Tumblr bookmark. Exists only if true.
	 */
	bool bookmarklet = false;

	/**
	 * Indicates whether the post was created via mobile/email publishing. Exists only if true.
	 */
	bool mobile = false;

	/**
	 * The URL for the source of the content (for quotes, reblogs, etc.). Exists only of there's a content source.
	 */
	std::string source_url;

	/**
	 * The title of the source site. Exists only if there's a content source.
	 */
	std::string source_title;

	/**
	 * Indicates if a user has already liked a post or not. Exists nly if the request is fully authenticated with OAuth.
	 */
	bool liked = false;

	/**
	 * Indicates the current state of the post. States are published, queued, draft and private.
	 */
	postState state;

	/**
	 * The total number of post available for this request, useful for paginating though results.
	 */
	unsigned long long total_posts = 0;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	std::string short_url;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	std::string summary;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool should_open_in_legacy = false;

	/**
	 * Undocumented.
	 * TODO Documentation.
	 */
	unsigned long long note_count = 0;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool can_like = false;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool can_reblog = false;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool can_send_in_message = false;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool can_reply = false;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool display_avatar = false;

	// auto content; FIXME

	// auto layout; FIXME

	// auto trail; FIXME

	/**
	 * TODO Documentation
	 * @param post
	 * @return
	 */
	bool operator==(const Post &post) const;

	/**
	 * TODO Documentation
	 * @param post
	 * @return
	 */
	bool operator!=(const Post &post) const;

protected:

	Post(postType postType, const rapidjson::Value &jsonObject) : type(postType) {

		TumblrAPI::setStringFromJson(jsonObject, "original_type", this->original_type);
		TumblrAPI::setStringFromJson(jsonObject, "blog_name", this->blog_name);


		if (jsonObject.HasMember("id")) {
			const rapidjson::Value &jsonObjectValue = jsonObject["id"];
			if (jsonObjectValue.IsInt64()) {
				this->id = jsonObjectValue.GetInt64();
			}
		}

		TumblrAPI::setStringFromJson(jsonObject, "id_string", this->id_string);
		TumblrAPI::setStringFromJson(jsonObject, "genesis_post_id", this->genesis_post_id);
		TumblrAPI::setStringFromJson(jsonObject, "post_url", this->post_url);

		if (jsonObject.HasMember("timestamp")) {
			const rapidjson::Value &jsonObjectValue = jsonObject["timestamp"];
			if (jsonObjectValue.IsInt64()) {
				this->timestamp = jsonObjectValue.GetInt64();
			}
		}

		TumblrAPI::setStringFromJson(jsonObject, "slug", this->slug);
		TumblrAPI::setStringFromJson(jsonObject, "date", this->date);

		if (jsonObject.HasMember("format")) {
			const rapidjson::Value &jsonObjectValue = jsonObject["format"];
			if (jsonObjectValue.IsString()) {
				std::string formatString = jsonObjectValue.GetString();
				if (formatString == "html") {
					this->format = postFormat::html;
				} else if (formatString == "markdown") {
					this->format = postFormat::markdown;
				} else {
					this->format = postFormat::none;
				}
			}
		}

		TumblrAPI::setStringFromJson(jsonObject, "reblog_key", this->reblog_key);
		TumblrAPI::setStringFromJson(jsonObject, "tags", this->tags);
		TumblrAPI::setStringFromJson(jsonObject, "short_url", this->short_url);
		TumblrAPI::setStringFromJson(jsonObject, "summary", this->summary);

		TumblrAPI::setBooleanFromJson(jsonObject, "should_open_in_legacy", this->should_open_in_legacy);
		TumblrAPI::setBooleanFromJson(jsonObject, "bookmarklet", this->bookmarklet);
		TumblrAPI::setBooleanFromJson(jsonObject, "mobile", this->mobile);

		TumblrAPI::setStringFromJson(jsonObject, "source_url", this->source_url);
		TumblrAPI::setStringFromJson(jsonObject, "source_title", this->source_title);

		TumblrAPI::setBooleanFromJson(jsonObject, "liked", this->liked);

		if (jsonObject.HasMember("state")) {
			const rapidjson::Value &jsonObjectValue = jsonObject["state"];
			std::string stateString = jsonObjectValue.GetString();
			if (stateString == "queued") {
				this->state = postState::queued;
			} else if (stateString == "draft") {
				this->state = postState::draft;
			} else if (stateString == "private") {
				this->state = postState::privat;
			} else {
				this->state = postState::published;
			}
		}

		TumblrAPI::setUInt64FromJson(jsonObject, "total_posts", this->total_posts);
		TumblrAPI::setUInt64FromJson(jsonObject, "note_count", this->note_count);

		TumblrAPI::setBooleanFromJson(jsonObject, "can_like", this->can_like);
		TumblrAPI::setBooleanFromJson(jsonObject, "can_reblog", this->can_reblog);
		TumblrAPI::setBooleanFromJson(jsonObject, "can_send_in_message", this->can_send_in_message);
		TumblrAPI::setBooleanFromJson(jsonObject, "can_reply", this->can_reply);
		TumblrAPI::setBooleanFromJson(jsonObject, "display_avatar", this->display_avatar);
	};

};

#endif //TUMBLRAPI_ABSTRACT_POST_HPP
