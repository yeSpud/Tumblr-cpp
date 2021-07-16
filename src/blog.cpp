//
// Created by Spud on 7/14/21.
//

#include "blog.hpp"

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
					Image avatar = (Image::generateImage(avatarEntry));
					if (!avatar.media[0].url.empty()) { // TODO Move me to media function
						blog.avatar.push_back(&avatar);
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