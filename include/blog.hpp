//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_BLOG_HPP
#define TUMBLRAPI_BLOG_HPP

#include "minimal_blog.hpp"
#include "theme.hpp"
#include "post.hpp"
#include "media.hpp"

class Blog : public MinimalBlog {

private:

	/**
	 * TODO Documentation
	 */
	const std::string blogIdentifier;

	/**
	 * TODO Documentation
	 */
	const TumblrAPI& api;

public:

	Blog(std::string blogIdentifier, const TumblrAPI& api): blogIdentifier(std::move(blogIdentifier)), api(api) {

		cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/info", true);

		if (response.status_code == 200 || response.status_code == 301 || response.status_code == 302 || response.status_code == 307 || response.status_code == 308) {

			rapidjson::GenericObject responseJsonObject = this->api.parseJsonResponse(response.text);

			const rapidjson::Value* blogJsonPointer = TumblrAPI::getValuePointerFromJson(responseJsonObject, "blog");

			if (blogJsonPointer != nullptr) {

				if (blogJsonPointer->IsObject()) {
					const rapidjson::GenericObject blogObject = blogJsonPointer->GetObj();

					TumblrAPI::setBooleanFromJson(blogObject, "ask", this->ask);
					TumblrAPI::setBooleanFromJson(blogObject, "ask_anon", this->ask_anon);

					TumblrAPI::setStringFromJson(blogObject, "ask_page_title", this->ask_page_title);

					TumblrAPI::setBooleanFromJson(blogObject, "asks_allow_media", this->asks_allow_media);

					// Avatars
					const rapidjson::Value* avatarJsonArrayPointer = TumblrAPI::getValuePointerFromJson(blogObject, "avatar");
					if (avatarJsonArrayPointer != nullptr) {
						if (avatarJsonArrayPointer->IsArray()) {
							rapidjson::GenericArray avatarArray = avatarJsonArrayPointer->GetArray();
							for (const rapidjson::Value &avatarEntry: avatarArray) {
								if (avatarEntry.IsObject()) {
									const rapidjson::GenericObject<true, rapidjson::Value>& avatarEntryObject = avatarEntry.GetObj();

									std::string avatarUrl;
									TumblrAPI::setStringFromJson(avatarEntryObject, "url", avatarUrl);

									Media avatar = Media(avatarUrl, avatarEntryObject);
									this->avatars.push_back(avatar);
								}
							}
						}
					}

					TumblrAPI::setBooleanFromJson(blogObject, "can_chat", this->can_chat);
					TumblrAPI::setBooleanFromJson(blogObject, "can_subscribe", this->can_subscribe);

					TumblrAPI::setStringFromJson(blogObject, "description", this->description);

					TumblrAPI::setBooleanFromJson(blogObject, "is_nsfw", this->is_nsfw);

					TumblrAPI::setStringFromJson(blogObject, "name", this->name);

					TumblrAPI::setUInt64FromJson(blogObject, "posts", this->posts);
					TumblrAPI::setUInt64FromJson(blogObject, "likes", this->likes);

					TumblrAPI::setBooleanFromJson(blogObject, "shared_likes", this->shared_likes);
					TumblrAPI::setBooleanFromJson(blogObject, "subscribed", this->subscribed);

					// Theme
					const rapidjson::Value* themeJsonPointer = TumblrAPI::getValuePointerFromJson(blogObject, "theme");
					if (themeJsonPointer != nullptr) {
						if (themeJsonPointer->IsObject()) {
							this->theme = std::make_unique<Theme>(Theme(themeJsonPointer->GetObj()));
						}
					}

					TumblrAPI::setStringFromJson(blogObject, "title", this->title);

					TumblrAPI::setUInt64FromJson(blogObject, "total_posts", this->total_posts);
					TumblrAPI::setUInt64FromJson(blogObject, "updated", this->updated);

					TumblrAPI::setStringFromJson(blogObject, "timezone", this->timezone);
					TumblrAPI::setStringFromJson(blogObject, "timezone_offset", this->timezone_offset);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
					TumblrAPI::setStringFromJson(blogObject, "url", this->url);
#pragma clang diagnostic pop

					TumblrAPI::setStringFromJson(blogObject, "uuid", this->uuid);

					TumblrAPI::setBooleanFromJson(blogObject, "is_blocked_from_primary", this->is_blocked_from_primary);
					TumblrAPI::setBooleanFromJson(blogObject, "is_optout_ads", this->is_optout_ads);
				}
			}
		} else  {
			std::string errorString = "Response from API returned an error: " + response.error.message + "\n" + response.reason;
			this->api.logger->error(errorString);
			throw std::runtime_error(errorString);
		}
	};

	~Blog() = default;

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
	 * Undocumented.
	 */
	std::string ask_page_title;

	/**
	 * TODO Documentation
	 * Undocumented.
	 */
	bool asks_allow_media = false;

	/**
	 * An array of avatar images, each a different size, which should each have a width, height, and URL.
	 */
	std::vector<Media> avatars;

	/**
	 * TODO Documentation
	 * Undocumented.
	 */
	bool can_chat = false;

	/**
	 * TODO Documentation
	 * Undocumented.
	 */
	bool can_subscribe = false;

	/**
	 * Undocumented.
	 * Assumed to mark whether the blog is NSFW (18+).
	 */
	bool is_nsfw = false;

	/**
	 * The total number of posts to this blog.
	 */
	unsigned long long posts = 0;

	/**
	 * Number of likes for this user, returned only if this is the user's primary blog and sharing of likes is enabled
	 */
	unsigned long long likes = 0;

	/**
	 * Undocumented.
	 * Indicates if the blog's likes are shared publicly.
	 * If this is false then getting likes from the blog will return an error (which should be caught and return 0 likes).
	 */
	bool shared_likes = false;

	/**
	 * TODO Documentation
	 * Undocumented.
	 */
	bool subscribed = false;

	/**
	 * The blog's general theme options, which may not be useful if the blog uses a custom theme.
	 */
	std::unique_ptr<Theme> theme;

	/**
	 * The total number of post available for this request, useful for paginating through results.
	 */
	unsigned long long total_posts = 0;

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
	 * Indicates whether this blog has been blocked by the calling user's primary blog
	 */
	bool is_blocked_from_primary = false;

	/**
	 * Undocumented.
	 * Assumed to mark whether the blog has opted out of advertisements,
	 */
	bool is_optout_ads = false;

	/**
	 * Retrieve a Blog Avatar in the form of a URL.
	 * You can get a blog's avatar in 9 different sizes. The default size is 64x64.
	 * @param size The size of the avatar (square, one value for both length and width). Must be one of the values: 16, 24, 30, 40, 48, 64, 96, 128, 512.
	 * @return The URL of the avatar image. This is also returned in the Location HTTP header field.
	 * An <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.30">HTTP Location</a> header field is returned — the response points to the avatar image. That means you can embed this method in an img tag in HTML.
	 */
	std::string getAvatar(const unsigned short int &size = 64);

	// TODO Blog blocks (both get, post, and delete)

	struct blogLikes {

		/**
		 * An array of post objects (posts liked by the user).
		 */
		std::vector<std::shared_ptr<Post>> liked_posts;

		/**
		 * Total number of liked posts.
		 */
		long long liked_count = 0;
	};

	/**
	 * This method can be used to retrieve the publicly exposed likes from a blog.
	 * @param limit The number of results to return: 1–20, inclusive. Optional, and defaults to 20.
	 * @param offset Liked post number to start at. Optional, and defaults to 0 (first post).
	 * @param before Retrieve posts liked before the specified timestamp. Optional.
	 * @param after Retrieve posts liked after the specified timestamp. Optional.
	 * @return blogLikes - contains an array of post objects, and liked posts.
	 */
	blogLikes getLikes(const unsigned short int &limit = 20, const unsigned short int &offset = 0, const long long &before = 0, const long long &after = 0);

	// TODO Blog following

	// TODO Blog followers

	// TODO Blog followed by


    /**
     * Retrieve Published Posts.
     * @param type The type of post to return. Specify one of the following: text, quote, link, answer, video, audio,
     * photo, or chat.
     * @param id A specific post ID. Returns the single post specified or (if not found) a 404 error.
     * @param tag Limits the response to posts with the specified tag(s), see note below.
     * @param limit The number of posts to return: 1–20, inclusive.
     * @param offset Post number to start at.
     * @param reblog_info Indicates whether to return reblog information (specify true or false). Returns the various reblogged_ fields.
     * @param notes_info Indicates whether to return notes information (specify true or false). Returns note count and note metadata.
     * @param filter Specifies the post format to return, other than HTML: text – Plain text, no HTML;
     * raw – As entered by the user (no post-processing); if the user writes in Markdown,
     * the Markdown will be returned rather than HTML
     * @param before Returns posts published earlier than a specified Unix timestamp, in seconds.
     * @return
     */
    std::vector<Post> getPosts(const Content::postType &type = Content::postType::all, const unsigned long long &id = 0, const std::string& tag = "", unsigned short limit = 20, const unsigned long long &offset = 0, const bool &reblog_info = false, const bool &notes_info = false, const Post::postFormat &filter = Post::postFormat::html, const long long &before = 0);

};

#endif //TUMBLRAPI_BLOG_HPP
