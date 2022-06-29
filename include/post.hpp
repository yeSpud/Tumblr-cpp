//
// Created by Spud on 6/16/22.
//

#ifndef TUMBLRAPI_POST_HPP
#define TUMBLRAPI_POST_HPP

#include "posts/text_post.hpp"
#include "posts/image_post.hpp"
#include "posts/link_post.hpp"
#include "posts/video_post.hpp"
#include "posts/audio_post.hpp"
#include "minimal_blog.hpp"
#include "trail.hpp"

class Post {

protected:

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

public:

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

	explicit Post(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject) {

		TumblrAPI::setStringFromJson(jsonObject, "type", this->type);
		TumblrAPI::setStringFromJson(jsonObject, "original_type", this->original_type);
		TumblrAPI::setStringFromJson(jsonObject, "blog_name", this->blog_name);

		// Blog.
		if (jsonObject.HasMember("blog")) {
			if (jsonObject["blog"].IsObject()) {
				this->blog = MinimalBlog(jsonObject["blog"].GetObj());
			}
		}

		TumblrAPI::setInt64FromJson(jsonObject, "id", this->id);

		TumblrAPI::setStringFromJson(jsonObject, "id_string", this->id_string);
		TumblrAPI::setStringFromJson(jsonObject, "genesis_post_id", this->genesis_post_id);
		TumblrAPI::setStringFromJson(jsonObject, "post_url", this->post_url);

		TumblrAPI::setInt64FromJson(jsonObject, "timestamp", this->timestamp);

		TumblrAPI::setStringFromJson(jsonObject, "slug", this->slug);
		TumblrAPI::setStringFromJson(jsonObject, "date", this->date);

		std::string formatString;
		TumblrAPI::setStringFromJson(jsonObject, "format", formatString);
		if (formatString == "html") {
			this->format = postFormat::html;
		} else if (formatString == "markdown") {
			this->format = postFormat::markdown;
		} else {
			this->format = postFormat::none;
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

		std::string stateString;
		TumblrAPI::setStringFromJson(jsonObject, "state", stateString);
		if (stateString == "queued") {
			this->state = postState::queued;
		} else if (stateString == "draft") {
			this->state = postState::draft;
		} else if (stateString == "private") {
			this->state = postState::privat;
		} else {
			this->state = postState::published;
		}

		TumblrAPI::setUInt64FromJson(jsonObject, "total_posts", this->total_posts);
		TumblrAPI::setUInt64FromJson(jsonObject, "note_count", this->note_count);

		// Content
		// Make sure the post has a content array.
		Content::setContentVectorFromJsonObject(jsonObject, this->content);

		// Layout
		Layout::setLayoutVectorFromJsonObject(jsonObject, this->layout);

		// Trail
		const rapidjson::Value* postTrailJsonPointer = TumblrAPI::getValuePointerFromJson(jsonObject, "trail");
		if (postTrailJsonPointer != nullptr) {
			if (postTrailJsonPointer->IsArray()) {
				rapidjson::GenericArray postTrailArray = postTrailJsonPointer->GetArray();
				if (!postTrailArray.Empty()) {
					this->populateTrail(postTrailArray);
				}
			}
		}

		TumblrAPI::setBooleanFromJson(jsonObject, "can_like", this->can_like);
		TumblrAPI::setBooleanFromJson(jsonObject, "can_reblog", this->can_reblog);
		TumblrAPI::setBooleanFromJson(jsonObject, "can_send_in_message", this->can_send_in_message);
		TumblrAPI::setBooleanFromJson(jsonObject, "can_reply", this->can_reply);
		TumblrAPI::setBooleanFromJson(jsonObject, "display_avatar", this->display_avatar);
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
	 * Blog object that is the equivalent of an info response.
	 */
	MinimalBlog blog;

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
	 * The type of post. This is essentially always going to be "blocks" since we always get NPF type posts.
	 */
	std::string type;

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
	std::vector<Trail> trail;

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

private:

	void populateTrail(const rapidjson::GenericArray<true, rapidjson::Value>& trailJsonArray);

};

#endif //TUMBLRAPI_POST_HPP
