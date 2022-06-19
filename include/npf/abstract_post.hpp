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
	long long id;

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
	long long timestamp;

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
	unsigned long long total_posts;

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
	bool should_open_in_legacy;

	/**
	 * Undocumented.
	 * TODO Documentation.
	 */
	unsigned long long note_count;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool can_like;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool can_reblog;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool can_send_in_message;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool can_reply;

	/**
	 * Undocumented.
	 * TODO Documentation
	 */
	bool display_avatar;

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

		Post::setStringFromJson(jsonObject, "original_type", this->original_type);
		Post::setStringFromJson(jsonObject, "blog_name", this->blog_name);


		if (jsonObject.HasMember("id")) {
			const rapidjson::Value &jsonObjectValue = jsonObject["id"];
			if (jsonObjectValue.IsUint64()) {
				this->id = jsonObjectValue.GetInt64();
			}
		}

		Post::setStringFromJson(jsonObject, "id_string", this->id_string);
		Post::setStringFromJson(jsonObject, "genesis_post_id", this->genesis_post_id);
		Post::setStringFromJson(jsonObject, "post_url", this->post_url);

		if (jsonObject.HasMember("timestamp")) {
			const rapidjson::Value &jsonObjectValue = jsonObject["timestamp"];
			if (jsonObjectValue.IsInt64()) {
				this->timestamp = jsonObjectValue.GetInt64();
			}
		}

		Post::setStringFromJson(jsonObject, "slug", this->slug);
		Post::setStringFromJson(jsonObject, "date", this->date);

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

		Post::setStringFromJson(jsonObject, "reblog_key", this->reblog_key);
		Post::setStringFromJson(jsonObject, "tags", this->tags);
		Post::setStringFromJson(jsonObject, "short_url", this->short_url);
		Post::setStringFromJson(jsonObject, "summary", this->summary);

		Post::setBooleanFromJson(jsonObject, "should_open_in_legacy", this->should_open_in_legacy);
		Post::setBooleanFromJson(jsonObject, "bookmarklet", this->bookmarklet);
		Post::setBooleanFromJson(jsonObject, "mobile", this->mobile);

		Post::setStringFromJson(jsonObject, "source_url", this->source_url);
		Post::setStringFromJson(jsonObject, "source_title", this->source_title);

		Post::setBooleanFromJson(jsonObject, "liked", this->liked);

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

		if (jsonObject.HasMember("total_posts")) {
			const rapidjson::Value &jsonObjectValue = jsonObject["total_posts"];
			if (jsonObjectValue.IsUint64()) {
				this->total_posts = jsonObjectValue.GetUint64();
			}
		}

		if (jsonObject.HasMember("note_count")) {
			const rapidjson::Value &jsonObjectValue = jsonObject["note_count"];
			if (jsonObjectValue.IsUint64()) {
				this->note_count = jsonObjectValue.GetUint64();
			}
		}

		Post::setBooleanFromJson(jsonObject, "can_like", this->can_like);
		Post::setBooleanFromJson(jsonObject, "can_reblog", this->can_reblog);
		Post::setBooleanFromJson(jsonObject, "can_send_in_message", this->can_send_in_message);
		Post::setBooleanFromJson(jsonObject, "can_reply", this->can_reply);
		Post::setBooleanFromJson(jsonObject, "display_avatar", this->display_avatar);
	};

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param key
	 * @return
	 */
	static const rapidjson::Value* setValueFromJson(const rapidjson::Value &jsonObject, const char *key);

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param key
	 * @param stringBuffer
	 */
	static void setStringFromJson(const rapidjson::Value &jsonObject, const char* key, std::string &stringBuffer);

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param key
	 * @param booleanBuffer
	 */
	static void setBooleanFromJson(const rapidjson::Value &jsonObject, const char* key, bool &booleanBuffer);

};

#endif //TUMBLRAPI_ABSTRACT_POST_HPP
