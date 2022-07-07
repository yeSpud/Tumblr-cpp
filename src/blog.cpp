//
// Created by Spud on 7/14/21.
//

#include "blog.hpp"

std::string Blog::getAvatar(const unsigned short int &size) {

	// Make sure the sizes are valid.
	if (size == 16 || size == 24 || size == 30 || size == 40 || size == 48 || size == 64 || size == 96 || size == 128 ||
	    size == 512) {

		cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/avatar/",
														  false, std::to_string(size));

		if (TumblrAPI::responseOk(response.status_code)) {
			return response.url.str();
		} else {
			std::string errorString ="Response from API returned an error: " + response.error.message + '\n' + response.reason;
			this->api.logger->error(errorString);
			throw std::runtime_error(errorString);
		}
	} else {

		// Throw an error since the size is invalid.
		std::string errorString = "Size provided is not valid size: " + std::to_string(size);
		this->api.logger->error(errorString);
		throw std::invalid_argument(errorString);
	}
}

Blog::blogLikes Blog::getLikes(const unsigned short int &limit, const unsigned short int &offset, const long long &before,
               const long long &after) {

	// Make sure that the blog allows for retrieving likes (shared_likes must be true).
	if (!this->shared_likes) {
		this->api.logger->warn("Blog likes are not shared publicly. Returning 0 likes");
		Blog::blogLikes emptyBlogLikes;
		emptyBlogLikes.liked_count = 0;
		emptyBlogLikes.liked_posts = std::vector<std::shared_ptr<Post>>(0);
		return emptyBlogLikes;
	}

	// Make sure limit and offset are valid.
	if (limit >= 1 && limit <= 20) {
		short int offsetMath = limit - offset;
		if (offsetMath > 0 && offset <= 20) {

			cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/likes",
															  true); // TODO Implement options
			if (TumblrAPI::responseOk(response.status_code)) {
				rapidjson::GenericObject jsonResponse = this->api.parseJsonResponse(response.text);

				// FIXME parse likes.

			} else {

				std::string errorString = "Response from API returned an error: " + response.error.message + '\n' + response.reason;
				this->api.logger->error(errorString);
				throw std::runtime_error(errorString);
			}
		}
	} else {

		// Throw an error since the limit in invalid.
		std::string errorString = "Limit provided is not a valid limit: " + std::to_string(limit);
		this->api.logger->error(errorString);
		throw std::invalid_argument(errorString);
	}
}

std::vector<Post>Blog::getPosts(const Content::postType &type, const unsigned long long &id, const std::string &tag,
								unsigned short limit, const unsigned long long &offset, const bool &reblog_info,
								const bool &notes_info, const Post::postFormat &filter, const long long int &before) {

	std::string additionalOptions = "&npf=true";
	switch (type) {
		case Content::postType::text:
			additionalOptions += "&type=text";
			break;
		case Content::postType::quote:
			additionalOptions += "&type=quote";
			break;
		case Content::postType::link:
			additionalOptions += "&type=link";
			break;
		case Content::postType::answer:
			additionalOptions += "&type=answer";
			break;
		case Content::postType::video:
			additionalOptions += "&type=video";
			break;
		case Content::postType::audio:
			additionalOptions += "&type=audio";
			break;
		case Content::postType::photo:
			additionalOptions += "&type=photo";
			break;
		case Content::postType::chat:
			additionalOptions += "&type=chat";
			break;
		case Content::postType::all:
			this->api.logger->debug("Getting all post types");
			break;
	}

	if (id != 0) {
		additionalOptions += "&id=" + std::to_string(id);
	}

	if (!tag.empty()) {
		additionalOptions += "&tag=" + tag;
	}

	if (limit < 1 || limit >= 20) {
		this->api.logger->warn("Invalid limit provided: {}", limit);
		limit = 20;
	} else {
		additionalOptions += "&limit=" + std::to_string(limit);
	}

	if (offset != 0) {
		additionalOptions += "&offset=" + std::to_string(offset);
	}

	if (reblog_info) {
		additionalOptions += "&reblog_info=" + std::to_string(reblog_info);
	}

	if (notes_info) {
		additionalOptions += "&notes_info=" + std::to_string(notes_info);
	}

	if (filter == Post::postFormat::markdown) {
		additionalOptions += "&filter=markdown";
	}

	if (before != 0) {
		additionalOptions += "&before=" + std::to_string(before);
	}

	cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/posts",true,
													  additionalOptions);

	if (TumblrAPI::responseOk(response.status_code)) {

		const rapidjson::GenericObject jsonResponse = this->api.parseJsonResponse(response.text);

		const rapidjson::Value* postsJsonPointer = TumblrAPI::getValuePointerFromJson(jsonResponse, "posts");

		// Make sure the posts' pointer isn't null.
		if (postsJsonPointer == nullptr) {
			this->api.logger->warn("No posts were returned.");
			return {};
		}

		// Make sure the posts' pointer is an array.
		if (!postsJsonPointer->IsArray()) {
			this->api.logger->error("Posts json is no an array type!");
			return {};
		}

		rapidjson::GenericArray postsJsonArray = postsJsonPointer->GetArray();
		std::vector<Post> returnedPosts;

		for (const rapidjson::Value &postsJsonArrayEntry : postsJsonArray) {

			// Make sure the entry is an object.
			if (!postsJsonArrayEntry.IsObject()) {
				this->api.logger->warn("Post entry isn't an object.");
				continue;
			}

			const rapidjson::GenericObject postJsonArrayEntryObject = postsJsonArrayEntry.GetObj();

			Post post = Post(postJsonArrayEntryObject);
			returnedPosts.push_back(post);
		}

		return returnedPosts;

	} else {

		this->api.logger->warn("Unable to get posts from blog ({0}): {1}", response.status_code, response.reason);
		return {};
	}
}

NoteResponse Blog::getNotes(long long id, unsigned long long before_timestamp, Note::mode mode) {

	std::string additionalOptions = "&id=" + std::to_string(id);

	if (before_timestamp != 0) {
		additionalOptions += "&before_timestamp=" + std::to_string(before_timestamp);
	}

	switch (mode) {

		case Note::all:
			additionalOptions += "&mode=all";
			break;
		case Note::likes:
			additionalOptions += "&mode=likes";
			break;
		case Note::conversation:
			additionalOptions += "&mode=conversation";
			break;
		case Note::rollup:
			additionalOptions += "&mode=rollup";
			break;
		case Note::reblogs_with_tags:
			additionalOptions += "&mode=reblog_with_tags";
			break;
	}

	cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/notes", true,
									additionalOptions);

	if (TumblrAPI::responseOk(response.status_code)) {

		const rapidjson::GenericObject jsonResponse = this->api.parseJsonResponse(response.text);

		NoteResponse noteResponse;

		// Populate notes field.
		if (jsonResponse.HasMember("notes")) {
			if (jsonResponse["notes"].IsArray()) {
				for (const rapidjson::Value& arrayEntry : jsonResponse["notes"].GetArray()) {
					if (arrayEntry.IsObject()) {

						Note note = Note(arrayEntry.GetObj());
						noteResponse.notes.push_back(note);
					}
				}
			}
		}

		// Populate rollup notes field.
		if (jsonResponse.HasMember("rollup_notes")) {
			if (jsonResponse["rollup_notes"].IsArray()) {
				for (const rapidjson::Value& arrayEntry : jsonResponse["rollup_notes"].GetArray()) {
					if (arrayEntry.IsObject()) {

						Note rollupNote = Note(arrayEntry.GetObj());
						noteResponse.rollup_notes.push_back(rollupNote);
					}
				}
			}
		}

		TumblrAPI::setUInt64FromJson(jsonResponse, "total_notes", noteResponse.total_notes);
		TumblrAPI::setUInt64FromJson(jsonResponse, "total_likes", noteResponse.total_likes);
		TumblrAPI::setUInt64FromJson(jsonResponse, "total_reblogs", noteResponse.total_reblogs);

		// TODO _links

		return noteResponse;

	} else {

		this->api.logger->warn("Unable to get notes from post ({0}): {1}", response.status_code, response.reason);
		return {};
	}

}
