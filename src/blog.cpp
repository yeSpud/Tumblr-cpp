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

			objectHasValue(blogjson, "ask", blog.ask);
			objectHasValue(blogjson, "ask_anon", blog.ask_anon);
			objectHasValue(blogjson, "ask_page_title", blog.ask_page_title);
			objectHasValue(blogjson, "asks_allow_media", blog.asks_allow_media);

			// Avatars
			if (blogjson.HasMember("avatar")) {
				for (const auto &avatarEntry : blogjson["avatar"].GetArray()) {
					Image avatar = (Image::generateImage(avatarEntry));
					if (!avatar.media[0].url.empty()) { // TODO Move me to media function
						blog.avatar.push_back(&avatar);
					}
				}
			}

			objectHasValue(blogjson, "can_chat", blog.can_chat);
			objectHasValue(blogjson, "can_subscribe", blog.can_subscribe);
			objectHasValue(blogjson, "description", blog.description);
			objectHasValue(blogjson, "is_nsfw", blog.is_nsfw);
			objectHasValue(blogjson, "name", blog.name);
			objectHasValue(blogjson, "posts", blog.posts);
			objectHasValue(blogjson, "shared_likes", blog.shared_likes);
			objectHasValue(blogjson, "subscribed", blog.subscribed);

			objectHasValue(blogjson, "title", blog.title);
			objectHasValue(blogjson, "total_posts", blog.total_posts);
			objectHasValue(blogjson, "updated", blog.updated);
			objectHasValue(blogjson, "url", blog.url);
			objectHasValue(blogjson, "uuid", blog.uuid);
			objectHasValue(blogjson, "is_optout_ads", blog.is_optout_ads);
		}
	}

	return blog;
}