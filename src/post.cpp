//
// Created by Spud on 7/14/21.
//

#include "post.hpp"

Post::~Post() = default;

void Post::populatePost(const JSON_OBJECT &object) { // TODO Comments

	// Post type
	if (object.HasMember("type")) {
		if (object["type"].IsString()) {

			std::string stringType = object["type"].GetString();

			// Check if the type is a npf (will have a type of "blocks"
			if (stringType == "blocks") {

				// Try finding the content block.
				if (object.HasMember("content")) {

					JSON_ARRAY blockContent = object["content"].GetArray();

					// Check if we can get the type of the block content.
					if (blockContent[0].HasMember("type")) {
						stringType = blockContent[0]["type"].GetString();
					}
				}
			}

			std::vector<std::string> strings{"text", "text", "text", "text", "video", "audio", "image", "text"};
			std::vector<postType> types{text, quote, link, answer, video, audio, photo, chat};

			type = stringToEnum(stringType, strings, types, text);
		}
	}


	objectHasValue(object, "original_type", original_type);
	objectHasValue(object, "blog_name", blog_name);

	// Blog pointer
	POPULATE_OBJECT(object, "blog", blog = std::shared_ptr<Blog>(new Blog); blog->populateBlog(object["blog"].GetObj());)

	objectHasValue(object, "id", id);
	objectHasValue(object, "id_string", id_string);
	objectHasValue(object, "genesis_post_id", genesis_post_id);
	objectHasValue(object, "post_url", post_url);
	objectHasValue(object, "slug", slug);
	objectHasValue(object, "date", date);
	objectHasValue(object, "timestamp", timestamp);

	// Post format
	if (object.HasMember("format")) {
		if (object["format"].IsString()) {
			std::vector<std::string> strings{"html", "markdown"};
			std::vector<postFormat> formats{html, markdown};

			format = stringToEnum(object["format"].GetString(), strings, formats, none);
		}
	}


	// Post state
	if (object.HasMember("state")) {
		if (object["state"].IsString()) {
			std::vector<std::string> strings{"published", "queued", "draft", "private"};
			std::vector<postState> states{published, queued, draft, privat};

			state = stringToEnum(object["state"].GetString(), strings, states, published);
		}
	}


	objectHasValue(object, "reblog_key", reblog_key);

	// Tags
	POPULATE_ARRAY(object, "tags", for (JSON_ARRAY_ENTRY &tag: object["tags"].GetArray()) {
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

	// Layout
	Trail::populateLayoutPointerArray(object, layout);

	// Trail
	POPULATE_ARRAY(object, "trail", for (JSON_ARRAY_ENTRY &entry: object["trail"].GetArray()) {
		if (entry.IsObject()) {
			std::shared_ptr<Trail> trail = std::shared_ptr<Trail>(new Trail);
			trail->populateNPF(entry.GetObj());
			trails.push_back(trail);
		}
	})

	objectHasValue(object, "can_like", can_like);
	objectHasValue(object, "can_reblog", can_reblog);
	objectHasValue(object, "can_send_in_message", can_send_in_message);
	objectHasValue(object, "can_reply", can_reply);
	objectHasValue(object, "display_avatar", display_avatar);

}

std::vector<std::shared_ptr<Post>> Post::generatePosts(const char *json) { // TODO Comments

	std::vector<std::shared_ptr<Post>> posts;

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

					std::shared_ptr<Post> postPointer = std::shared_ptr<Post>(new Post);
					postPointer->populatePost(postjson);

					posts.push_back(postPointer);
				}
			}
		}
	}

	return posts;
}