//
// Created by Spud on 7/13/21.
//

#include "../include/TumblrAPI.hpp"

cpr::Response
TumblrAPI::sendGetRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams) { // TODO Comments

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

std::vector<TumblrAPI::Post> TumblrAPI::generatePosts(const char *json) {
	std::vector<Post> posts;
	rapidjson::Document document;

	document.Parse(json);

	// Get the response section of the request (if it has it).
	if (document.HasMember("response")) {
		auto response = document["response"].GetObj();

		// Gets the posts array from the response.
		if (response.HasMember("posts")) {

			for (const auto &entry : response["posts"].GetArray()) {
				if (entry.IsObject()) {

					auto postjson = entry.GetObj();
					Post post;

					Content::entryHasString(postjson, "type", post.type);
					Content::entryHasString(postjson, "original_type", post.original_type);
					Content::entryHasString(postjson, "blog_name", post.blog_name);

					Content::entryHasNumber(postjson, "id", post.id);
					Content::entryHasString(postjson, "id_string", post.id_string);
					Content::entryHasString(postjson, "post_url", post.post_url);
					Content::entryHasString(postjson, "slug", post.slug);
					Content::entryHasString(postjson, "date", post.date);
					Content::entryHasNumber(postjson, "timestamp", post.timestamp);
					Content::entryHasString(postjson, "state", post.state);
					Content::entryHasString(postjson, "reblog_key", post.reblog_key);

					Content::entryHasString(postjson, "short_url", post.short_url);
					Content::entryHasString(postjson, "summary", post.summary);
					Content::entryHasBool(postjson, "should_open_in_legacy", post.should_open_in_legacy);
					Content::entryHasNumber(postjson, "note_count", post.note_count);

					// Image
					if (postjson.HasMember("content")) {
						for (const auto &contentEntry : postjson["content"].GetArray()) {
							if (contentEntry.HasMember("media")) {
								for (const auto &mediaEntry : contentEntry["media"].GetArray()) {
									Content::Image image;

									if (!image.url.empty()) {
										post.content.push_back(image);
									}
								}
							}
						}
					}

					Content::entryHasBool(postjson, "can_like", post.can_like);
					Content::entryHasBool(postjson, "can_reblog", post.can_reblog);
					Content::entryHasBool(postjson, "can_send_in_message", post.can_send_in_message);
					Content::entryHasBool(postjson, "can_reply", post.can_reply);
					Content::entryHasBool(postjson, "display_avatar", post.display_avatar);

					posts.push_back(post);
				}
			}
		}
	}

	return posts;
}
