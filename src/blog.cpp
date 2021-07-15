//
// Created by Spud on 7/14/21.
//

#include "npf.hpp"
#include "blog.hpp"

/*
struct blog::Blog {

	**
	 * Indicates whether the blog allows questions.
	 *
	bool ask;

	**
	 * Indicates whether the blog allows anonymous questions.
	 *
	bool ask_anon;

	std::string ask_page_title;

	bool asks_allow_media;

	**
	 * An array of avatar images, each a different size, which should each have a width, height, and URL.
	 *
	std::vector<image::Image*> avatar;

	bool can_chat;

	bool can_subscribe;

	std::string description;

	bool is_nsfw;

	**
	 * The short blog name that appears before tumblr.com in a standard blog hostname
	 *
	std::string name;

	uint64_t posts;

	bool shared_likes;

	bool subscribed;

	**
	 * The blog's general theme options, which may not be useful if the blog uses a custom theme.
	 *
	Theme theme;

	std::string title;

	uint64_t total_posts;

	uint64_t updated;

	std::string url;

	std::string uuid;

	bool is_optout_ads;

};
*/

Blog Blog::generateBlog(const char *json) {

	Blog blog;

	rapidjson::Document document;

	document.Parse(json);

	if (document.HasMember("response")) {
		auto response = document["response"].GetObj();

		if (response.HasMember("blog")) {

			auto blogjson = response["blog"].GetObj();

			entryHasValue(blogjson, "ask", blog.ask);
			entryHasValue(blogjson, "ask_anon", blog.ask_anon);
			entryHasValue(blogjson, "ask_page_title", blog.ask_page_title);
			entryHasValue(blogjson, "asks_allow_media", blog.asks_allow_media);

			// Avatars
			if (blogjson.HasMember("avatar")) {
				for (const auto &avatarEntry : blogjson["avatar"].GetArray()) {
					Image avatar = Image::generateImage(avatarEntry);
					if (!avatar.media[0].url.empty()) { // TODO Move me to media function
						blog.avatar.push_back(avatar);
					}
				}
			}

			entryHasValue(blogjson, "can_chat", blog.can_chat);
			entryHasValue(blogjson, "can_subscribe", blog.can_subscribe);
			entryHasValue(blogjson, "description", blog.description);
			entryHasValue(blogjson, "is_nsfw", blog.is_nsfw);
			entryHasValue(blogjson, "name", blog.name);
			entryHasValue(blogjson, "posts", blog.posts);
			entryHasValue(blogjson, "shared_likes", blog.shared_likes);
			entryHasValue(blogjson, "subscribed", blog.subscribed);

			entryHasValue(blogjson, "title", blog.title);
			entryHasValue(blogjson, "total_posts", blog.total_posts);
			entryHasValue(blogjson, "updated", blog.updated);
			entryHasValue(blogjson, "url", blog.url);
			entryHasValue(blogjson, "uuid", blog.uuid);
			entryHasValue(blogjson, "is_optout_ads", blog.is_optout_ads);
		}
	}

	return blog;
}