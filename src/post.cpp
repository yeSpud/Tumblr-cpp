//
// Created by Spud on 7/14/21.
//

#include <vector>
#include "Content.hpp"
#include "image.hpp"
#include "post.hpp"

struct post::Post {

	/**
	 * TODO Documentation
	 */
	std::string type;

	/**
	 * TODO Documentation
	 */
	std::string original_type;

	/**
	 * TODO Documentation
	 */
	std::string blog_name;

	// TODO
	// const auto blog;

	/**
	 * TODO Documentation
	 */
	uint64_t id = 0;

	/**
	 * TODO Documentation
	 */
	std::string id_string;

	/**
	 * TODO Documentation
	 */
	std::string post_url;

	/**
	 * TODO Documentation
	 */
	std::string slug;

	/**
	 * TODO Documentation
	 */
	std::string date;

	/**
	 * TODO Documentation
	 */
	uint64_t timestamp = 0;

	/**
	 * TODO Documentation
	 */
	std::string state;

	/**
	 * TODO Documentation
	 */
	std::string reblog_key;

	// const auto tags;

	/**
	 * TODO Documentation
	 */
	std::string short_url;

	/**
	 * TODO Documentation
	 */
	std::string summary;

	/**
	 * TODO Documentation
	 */
	bool should_open_in_legacy;

	/**
	 * TODO Documentation
	 */
	uint64_t note_count = 0;

	/**
	 * TODO Documentation
	 */
	// std::vector<image::Image> content; // FIXME

	// const auto layout;

	// const auto trail;

	/**
	 * TODO Documentation
	 */
	bool can_like;

	/**
	 * TODO Documentation
	 */
	bool can_reblog;

	/**
	 * TODO Documentation
	 */
	bool can_send_in_message;

	/**
	 * TODO Documentation
	 */
	bool can_reply;

	/**
	 * TODO Documentation
	 */
	bool display_avatar;

};

std::vector<post::Post> post::generatePosts(const char *json) {
	std::vector<post::Post> posts;
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
									image::Image *image;

									if (!image->url.empty()) {
										//post.content.push_back(image); // FIXME
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
