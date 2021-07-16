//
// Created by Spud on 7/14/21.
//

#include "npf.hpp"
#include "post.hpp"

std::vector<Post> Post::generatePosts(const char *json) { // TODO Comments
	std::vector<Post> posts;
	rapidjson::Document document;

	document.Parse(json);

	// Get the response section of the request (if it has it).
	if (document.HasMember("response")) {
		auto response = document["response"].GetObj();

		// Gets the posts array from the response.
		if (response.HasMember("posts")) {

			for (auto &entry : response["posts"].GetArray()) {
				if (entry.IsObject()) {

					JSONOBJECT postjson = entry.GetObj();
					Post post;

					objectHasValue(postjson, "type", post.type);
					objectHasValue(postjson, "original_type", post.original_type);
					objectHasValue(postjson, "blog_name", post.blog_name);

					objectHasValue(postjson, "id", post.id);
					objectHasValue(postjson, "id_string", post.id_string);
					objectHasValue(postjson, "post_url", post.post_url);
					objectHasValue(postjson, "slug", post.slug);
					objectHasValue(postjson, "date", post.date);
					objectHasValue(postjson, "timestamp", post.timestamp);
					objectHasValue(postjson, "state", post.state);
					objectHasValue(postjson, "reblog_key", post.reblog_key);

					objectHasValue(postjson, "short_url", post.short_url);
					objectHasValue(postjson, "summary", post.summary);
					objectHasValue(postjson, "should_open_in_legacy", post.should_open_in_legacy);
					objectHasValue(postjson, "note_count", post.note_count);

					// Media
					if (postjson.HasMember("content")) {
						for (const auto &contentEntry : postjson["content"].GetArray()) {
							if (contentEntry.HasMember("media")) {
								for (const auto &mediaEntry : contentEntry["media"].GetArray()) {

									if (mediaEntry.IsObject()) {

										Media media;
										media.populateNPF(mediaEntry.Get<JSONOBJECT>());
										post.content.push_back(media);
									}
								}
							}
						}
					}

					objectHasValue(postjson, "can_like", post.can_like);
					objectHasValue(postjson, "can_reblog", post.can_reblog);
					objectHasValue(postjson, "can_send_in_message", post.can_send_in_message);
					objectHasValue(postjson, "can_reply", post.can_reply);
					objectHasValue(postjson, "display_avatar", post.display_avatar);

					posts.push_back(post);
				}
			}
		}
	}

	return posts;
}
