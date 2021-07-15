//
// Created by Spud on 7/14/21.
//

#include <string>
#include "rapidjson/document.h"
#include "image.hpp"
#include "theme.hpp"
#include "Content.hpp"
#include "blog.hpp"

struct blog::Blog {

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
	std::vector<image::Image> avatar;

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
	theme::Theme theme;

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

blog::Blog blog::generateBlog(const char *json) {

	blog::Blog blog;

	rapidjson::Document document;

	document.Parse(json);

	if (document.HasMember("response")) {
		auto response = document["response"].GetObj();

		if (response.HasMember("blog")) {

			auto blogjson = response["blog"].GetObj();

			Content::entryHasBool(blogjson, "ask", blog.ask);
			Content::entryHasBool(blogjson, "ask_anon", blog.ask_anon);
			Content::entryHasString(blogjson, "ask_page_title", blog.ask_page_title);
			Content::entryHasBool(blogjson, "asks_allow_media", blog.asks_allow_media);

			// Avatars
			if (blogjson.HasMember("avatar")) {
				for (const auto &avatarEntry : blogjson["avatar"].GetArray()) {
					image::Image avatar = image::generateImage(avatarEntry);
					if (!avatar.url.empty()) {
						blog.avatar.push_back(avatar);
					}
				}
			}

			Content::entryHasBool(blogjson, "can_chat", blog.can_chat);
			Content::entryHasBool(blogjson, "can_subscribe", blog.can_subscribe);
			Content::entryHasString(blogjson, "description", blog.description);
			Content::entryHasBool(blogjson, "is_nsfw", blog.is_nsfw);
			Content::entryHasString(blogjson, "name", blog.name);
			Content::entryHasNumber(blogjson, "posts", blog.posts);
			Content::entryHasBool(blogjson, "shared_likes", blog.shared_likes);
			Content::entryHasBool(blogjson, "subscribed", blog.subscribed);

			Content::entryHasString(blogjson, "title", blog.title);
			Content::entryHasNumber(blogjson, "total_posts", blog.total_posts);
			Content::entryHasNumber(blogjson, "updated", blog.updated);
			Content::entryHasString(blogjson, "url", blog.url);
			Content::entryHasString(blogjson, "uuid", blog.uuid);
			Content::entryHasBool(blogjson, "is_optout_ads", blog.is_optout_ads);
		}
	}

	return blog;
}