//
// Created by Spud on 7/14/21.
//

#include "blog.hpp"

void Blog::populateBlog(const JSON_OBJECT &object) { // TODO Comments

	objectHasValue(object, "ask", ask);
	objectHasValue(object, "ask_anon", ask_anon);
	objectHasValue(object, "ask_page_title", ask_page_title);
	objectHasValue(object, "asks_allow_media", asks_allow_media);

	// Avatars
	/*
	if (blogjson.HasMember("avatar")) {
		if (blogjson["avatar"].IsArray()) {
			for (auto& avatarEntry : blogjson["avatar"].GetArray()) {
				if (avatarEntry.IsObject()) {
					Image avatar;
					avatar.populateNPF(avatarEntry.GetObj());
					blog.avatar.push_back(&avatar);
				}
			}
		}
	}
	 */
	POPULATE_ARRAY(object, "avatar", for (JSON_ARRAY_ENTRY &entry : object["avatar"].GetArray()) {
		if (entry.IsObject()) {
			Image image;
			image.populateNPF(entry.GetObj());
			avatar.push_back(&image);
		}
	})

	objectHasValue(object, "can_chat", can_chat);
	objectHasValue(object, "can_subscribe", can_subscribe);
	objectHasValue(object, "description", description);
	objectHasValue(object, "is_nsfw", is_nsfw);
	objectHasValue(object, "name", name);
	objectHasValue(object, "posts", posts);
	objectHasValue(object, "likes", likes);
	objectHasValue(object, "shared_likes", shared_likes);
	objectHasValue(object, "subscribed", subscribed);

	// Theme
	POPULATE_OBJECT(object, "theme", theme = Theme::generateTheme(object["theme"].GetObj());)

	objectHasValue(object, "title", title);
	objectHasValue(object, "total_posts", total_posts);
	objectHasValue(object, "updated", updated);
	objectHasValue(object, "timezone", timezone);
	objectHasValue(object, "timezone_offset", timezone_offset);
	objectHasValue(object, "url", url);
	objectHasValue(object, "uuid", uuid);
	objectHasValue(object, "is_blocked_from_primary", is_blocked_from_primary);
	objectHasValue(object, "is_optout_ads", is_optout_ads);

}

Blog Blog::generateBlog(const char *json) { // TODO Comments

	Blog blog;

	rapidjson::Document document;
	document.Parse(json);

	if (document.HasMember("response")) {
		JSON_OBJECT response = document["response"].GetObj();

		if (response.HasMember("blog")) {

			JSON_OBJECT blogjson = response["blog"].GetObj();

			blog.populateBlog(blogjson);
		}
	}

	return blog;
}