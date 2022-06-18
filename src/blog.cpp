//
// Created by Spud on 7/14/21.
//

#include "blog.hpp"
#include "npf/posts/text_post.hpp"

std::string Blog::getAvatar(const unsigned short int &size) {

	// Make sure the sizes are valid.
	if (size == 16 || size == 24 || size == 30 || size == 40 || size == 48 || size == 64 || size == 96 || size == 128 ||
	    size == 512) {

		cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/avatar/",
		                                                  false, std::to_string(size));

		if (response.status_code == 200 || response.status_code == 301 || response.status_code == 302 ||
		    response.status_code == 307 || response.status_code == 308) {
			return response.url.str();
			/*
			JSON_OBJECT jsonResponse = this->api.parseJsonResponse(response.text);
			const char* jsonKey = "avatar_url";
			if (jsonResponse.HasMember(jsonKey)) {
				if (jsonResponse[jsonKey].IsString()) {
					return jsonResponse[jsonKey].GetString();
				}
			}

			// At this point since we missed the primary return throw an error.
			std::string errorString = "Unable to find avatar url parameter in returned json";
			this->api.logger->error(errorString);
			throw std::runtime_error(errorString);*/
		} else {
			std::string errorString =
					"Response from API returned an error: " + response.error.message + '\n' + response.reason;
			this->api.logger->error(errorString);
			throw std::runtime_error(errorString);
		}
	} else {

		// Throw an error since the size is invalid.
		std::string errorString = "Size provided is not valid size: " + std::to_string(size);
		this->api.logger->error(errorString);
		throw std::invalid_argument(errorString);
	}
};

Blog::blogLikes
Blog::getLikes(const unsigned short int &limit, const unsigned short int &offset, const long long &before,
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
			if (response.status_code == 200 || response.status_code == 301 || response.status_code == 302 ||
			    response.status_code == 307 || response.status_code == 308) {
				JSON_OBJECT jsonResponse = this->api.parseJsonResponse(response.text);

				// TODO Format.

			} else {

				std::string errorString =
						"Response from API returned an error: " + response.error.message + '\n' + response.reason;
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

std::vector<Post>
Blog::getPosts(const Post::postType &type, const unsigned long long &id, const std::string &tag, unsigned short limit,
               const unsigned long long &offset, const bool &reblog_info, const bool &notes_info,
               const Post::postFormat &filter,
               const long long int &before) {

	std::string additionalOptions = "&npf=true";
	switch (type) {
		case Post::postType::text:
			additionalOptions += "&type=text";
			break;
		case Post::postType::quote:
			additionalOptions += "&type=quote";
			break;
		case Post::postType::link:
			additionalOptions += "&type=link";
			break;
		case Post::postType::answer:
			additionalOptions += "&type=answer";
			break;
		case Post::postType::video:
			additionalOptions += "&type=video";
			break;
		case Post::postType::audio:
			additionalOptions += "&type=audio";
			break;
		case Post::postType::photo:
			additionalOptions += "&type=photo";
			break;
		case Post::postType::chat:
			additionalOptions += "&type=chat";
			break;
		case Post::postType::all:
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

	cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/posts", true,
	                                                  additionalOptions);

	if (response.status_code == 200 || response.status_code == 301 || response.status_code == 302 ||
	    response.status_code == 307 || response.status_code == 308) {

		JSON_OBJECT jsonResponse = this->api.parseJsonResponse(response.text);

		jsonResponse.HasMember("posts");

		if (jsonResponse["posts"].IsArray()) {

			std::vector<Post> returnedPosts;
			unsigned short postIndex = 0;
			const rapidjson::GenericArray postsJsonArray = jsonResponse["posts"].GetArray();

			// https://github.com/Tencent/rapidjson/issues/459
			for (rapidjson::SizeType i = 0; i < postsJsonArray.Size(); i++) {

				if (postsJsonArray[i].IsObject()) {

					const rapidjson::GenericObject postJsonArrayEntry = postsJsonArray[i].GetObj();

					if (postJsonArrayEntry.HasMember("content")) {

						if (postJsonArrayEntry["content"].IsArray()) {

							rapidjson::GenericArray contentArray = postJsonArrayEntry["content"].GetArray();

							for (rapidjson::SizeType j = 0; j < contentArray.Size(); j++) {

								if (contentArray[j].IsObject()) {

									const rapidjson::GenericObject contentEntry = contentArray[j].GetObj();

									if (contentEntry.HasMember("type")) {

										std::string stringType = contentEntry["type"].GetString();

										if (stringType == "text") {
											returnedPosts.push_back(Text(postJsonArrayEntry, contentEntry));
										} else if (stringType == "quote") {
											// FIXME
										} else if (stringType == "link") {
											// FIXME
										} else if (stringType == "answer") {
											// FIXME
										} else if (stringType == "video") {
											// FIXME
										} else if (stringType == "audio") {
											// FIXME
										} else if (stringType == "photo") {
											// FIXME
										} else if (stringType == "chat") {
											// FIXME
										}

										postIndex++;
									}
								}
							}
						}
					}
				}
			}

			return returnedPosts;
		}
	}
}
