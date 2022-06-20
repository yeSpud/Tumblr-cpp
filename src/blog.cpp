//
// Created by Spud on 7/14/21.
//

#include "blog.hpp"
#include "npf/posts/text_post.hpp"
#include "npf/posts/image_post.hpp"

std::string Blog::getAvatar(const unsigned short int &size) {

	// Make sure the sizes are valid.
	if (size == 16 || size == 24 || size == 30 || size == 40 || size == 48 || size == 64 || size == 96 || size == 128 ||
	    size == 512) {

		cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/avatar/",
														  false, std::to_string(size));

		if (response.status_code == 200 || response.status_code == 301 || response.status_code == 302 ||
		    response.status_code == 307 || response.status_code == 308) {
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
			if (response.status_code == 200 || response.status_code == 301 || response.status_code == 302 ||
			    response.status_code == 307 || response.status_code == 308) {
				rapidjson::GenericObject<false, rapidjson::Value> jsonResponse = this->api.parseJsonResponse(response.text);

				// FIXME Format.

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

std::vector<Post>Blog::getPosts(const Post::postType &type, const unsigned long long &id, const std::string &tag, unsigned short limit,
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

		const rapidjson::GenericObject<false, rapidjson::Value> jsonResponse = this->api.parseJsonResponse(response.text);

		const rapidjson::Value* postsJsonPointer = TumblrAPI::setValueFromJson(jsonResponse, "posts");

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

			// Make sure the post has a content array.
			const rapidjson::Value* postContentJsonPointer = TumblrAPI::setValueFromJson(postJsonArrayEntryObject, "content");
			if (postContentJsonPointer == nullptr) {
				this->api.logger->warn("Post is missing content array.");
				continue;
			}
			if (!postContentJsonPointer->IsArray()) {
				this->api.logger->warn("Post content isn't an array.");
				continue;
			}

			rapidjson::GenericArray postContentJsonArray = postContentJsonPointer->GetArray();
			for (const rapidjson::Value &postContentJsonEntry : postContentJsonArray) {

				if (!postContentJsonEntry.IsObject()) {
					this->api.logger->warn("Post content entry isn't an object");
					continue;
				}

				rapidjson::GenericObject postContentEntryObject = postContentJsonEntry.GetObj();

				std::string contentTypeString;
				TumblrAPI::setStringFromJson(postContentEntryObject, "type", contentTypeString);

				if (contentTypeString == "text" || contentTypeString == "answer" || contentTypeString == "chat" || contentTypeString == "quote") { // TODO Change each of the post class types.

					std::string text;
					TumblrAPI::setStringFromJson(postContentEntryObject, "text", text);

					Text textPost = Text(postJsonArrayEntryObject, postContentEntryObject, text);
					returnedPosts.push_back(textPost);
				} else if (contentTypeString == "link") {
					// FIXME
				} else if (contentTypeString == "video") {
					// FIXME
				} else if (contentTypeString == "audio") {
					// FIXME
				} else if (contentTypeString == "image") {
					Image imagePost = Image(postJsonArrayEntryObject, postContentEntryObject);
					returnedPosts.push_back(imagePost);
				} else { // TODO Add paywall post
					this->api.logger->warn("Post content type unaccounted for: {}", contentTypeString);
				}
			}
		}

		return returnedPosts;

	} else {

		this->api.logger->warn("Unable to get posts from blog ({0}): {1}", response.status_code, response.reason);
		return {};
	}
}
