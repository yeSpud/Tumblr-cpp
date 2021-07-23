//
// Created by Spud on 7/14/21.
//

#include "npf/npf.hpp"
#include "npf/trail.hpp"

Post::~Post() { // TODO Comments

	DELETE_NPF(blog)

	for (Content *c : content) {
		DELETE_NPF(c)
	}

	for (Layout *l : layout) {
		DELETE_NPF(l)
	}

}

void Post::populatePost(const JSON_OBJECT &object) {

	objectHasValue(object, "type", type);
	objectHasValue(object, "original_type", original_type);
	objectHasValue(object, "blog_name", blog_name);

	// Blog pointer
	POPULATE_OBJECT(object, "blog", blog = new Blog(); blog->populateBlog(object["blog"].GetObj());)

	objectHasValue(object, "id", id);
	objectHasValue(object, "id_string", id_string);
	objectHasValue(object, "genesis_post_id", genesis_post_id);
	objectHasValue(object, "post_url", post_url);
	objectHasValue(object, "slug", slug);
	objectHasValue(object, "date", date);
	objectHasValue(object, "timestamp", timestamp);
	objectHasValue(object, "state", state);
	objectHasValue(object, "reblog_key", reblog_key);

	// Tags
	POPULATE_ARRAY(object, "tags", for (JSON_ARRAY_ENTRY &tag : object["tags"].GetArray()) {
		if (tag.IsString()) {
			tags.emplace_back(tag.GetString());
		}
	})

	objectHasValue(object, "bookmarklet", bookmarklet);
	objectHasValue(object, "mobile", mobile);
	objectHasValue(object, "source_url", source_url);
	objectHasValue(object, "source_title", source_title);
	objectHasValue(object, "liked", liked);
	objectHasValue(object, "total_posts", total_posts);
	objectHasValue(object, "short_url", short_url);
	objectHasValue(object, "post_author", post_author);
	objectHasValue(object, "is_submission", is_submission);
	objectHasValue(object, "anonymous_name", anonymous_name);
	objectHasValue(object, "anonymous_email", anonymous_email);
	objectHasValue(object, "summary", summary);
	objectHasValue(object, "should_open_in_legacy", should_open_in_legacy);
	objectHasValue(object, "note_count", note_count);

	// Content
	Trail::populateContentPointerArray(object, content);

	/*
	if (object.HasMember("content")) {
		if (object["content"].IsArray()){
			for (const auto &contentEntry : object["content"].GetArray()) {
				if (contentEntry.HasMember("media")) {
					if (contentEntry["media"].IsArray()) {
						for (auto& mediaEntry : contentEntry["media"].GetArray()) {
							if (mediaEntry.IsObject()) {
								rapidjson::Document objectDocument(rapidjson::kObjectType);
								objectDocument.CopyFrom(mediaEntry, objectDocument.GetAllocator());
								Media media;
								media.populateNPF(objectDocument.GetObj());
								content.push_back(media);
							}
						}
					}
				}
			}
		}
	}
	 */

	// Layout
	Trail::populateLayoutPointerArray(object, layout);

	// Trail
	POPULATE_ARRAY(object, "trail", for (JSON_ARRAY_ENTRY &entry : object["trail"].GetArray()) {
		if (entry.IsObject()) {
			Trail t;
			t.populateNPF(entry.GetObj());
			trail.push_back(t);
		}
	})

	objectHasValue(object, "can_like", can_like);
	objectHasValue(object, "can_reblog", can_reblog);
	objectHasValue(object, "can_send_in_message", can_send_in_message);
	objectHasValue(object, "can_reply", can_reply);
	objectHasValue(object, "display_avatar", display_avatar);

}

std::vector<Post> Post::generatePosts(const char *json) { // TODO Comments

	std::vector<Post> posts;

	rapidjson::Document document;
	document.Parse(json);

	// Get the response section of the request (if it has it).
	if (document.HasMember("response")) {
		JSON_OBJECT response = document["response"].GetObj();

		// Gets the posts array from the response.
		if (response.HasMember("posts")) {

			for (JSON_ARRAY_ENTRY &entry : response["posts"].GetArray()) {
				if (entry.IsObject()) {

					JSON_OBJECT postjson = entry.GetObj();

					Post post;

					posts.push_back(post);
				}
			}
		}
	}

	return posts;
}
