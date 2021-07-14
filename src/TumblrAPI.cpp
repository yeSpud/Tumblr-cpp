//
// Created by Spud on 7/13/21.
//

#include "../include/TumblrAPI.hpp"

cpr::Response
TumblrAPI::sendRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams) { // TODO Comments

	// Format the URL to go to for retrieving data.
	std::string url = "api.tumblr.com/v2/" + endpoint;
	if (authRequired) {
		url += "?api_key=" + token;
	}
	url += optionalParams;

	cpr::Response response;
	response = cpr::Get(cpr::Url{url});

	return response;
}

TumblrAPI::Blog TumblrAPI::generateBlog(const char *json) {
	Blog blog;

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
					Content::Image avatar = Content::generateImage(avatarEntry);
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
