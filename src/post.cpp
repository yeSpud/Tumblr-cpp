//
// Created by Spud on 7/14/21.
//

#include "NPF.hpp"
#include "post.hpp"

/*
struct post::Post {

	std::string type;

	std::string original_type;

	std::string blog_name;

	// TODO
	// const auto blog;

	uint64_t id = 0;

	std::string id_string;

	std::string post_url;

	std::string slug;

	std::string date;

	uint64_t timestamp = 0;

	std::string state;

	std::string reblog_key;

	// const auto tags;

	std::string short_url;

	std::string summary;

	bool should_open_in_legacy;

	uint64_t note_count = 0;

	// std::vector<image::Image> content;

	// const auto layout;

	// const auto trail;

	bool can_like;

	bool can_reblog;

	bool can_send_in_message;

	bool can_reply;

	bool display_avatar;

};
*/

std::vector<Post> Post::generatePosts(const char *json) {
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

					entryHasValue(postjson, "type", post.type);
					entryHasValue(postjson, "original_type", post.original_type);
					entryHasValue(postjson, "blog_name", post.blog_name);

					entryHasValue(postjson, "id", post.id);
					entryHasValue(postjson, "id_string", post.id_string);
					entryHasValue(postjson, "post_url", post.post_url);
					entryHasValue(postjson, "slug", post.slug);
					entryHasValue(postjson, "date", post.date);
					entryHasValue(postjson, "timestamp", post.timestamp);
					entryHasValue(postjson, "state", post.state);
					entryHasValue(postjson, "reblog_key", post.reblog_key);

					entryHasValue(postjson, "short_url", post.short_url);
					entryHasValue(postjson, "summary", post.summary);
					entryHasValue(postjson, "should_open_in_legacy", post.should_open_in_legacy);
					entryHasValue(postjson, "note_count", post.note_count);

					// Image
					if (postjson.HasMember("content")) {
						for (const auto &contentEntry : postjson["content"].GetArray()) {
							if (contentEntry.HasMember("media")) {
								for (const auto &mediaEntry : contentEntry["media"].GetArray()) {
									//Image image; // FIXME

									//if (!image.media[0].url.empty()) {
										//post.content.push_back(image); // FIXME
									//}
								}
							}
						}
					}

					entryHasValue(postjson, "can_like", post.can_like);
					entryHasValue(postjson, "can_reblog", post.can_reblog);
					entryHasValue(postjson, "can_send_in_message", post.can_send_in_message);
					entryHasValue(postjson, "can_reply", post.can_reply);
					entryHasValue(postjson, "display_avatar", post.display_avatar);

					posts.push_back(post);
				}
			}
		}
	}

	return posts;
}
