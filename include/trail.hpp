//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_TRAIL_HPP
#define TUMBLRAPI_TRAIL_HPP

#include "layout/layout.hpp"

class Trail {

public:

	explicit Trail(const rapidjson::GenericObject<true, rapidjson::Value>& trailJsonObject,
				   std::vector<std::shared_ptr<Content>> content, std::vector<std::shared_ptr<Layout>> layout):
				   content(std::move(content)), layout(std::move(layout)) {

		if (trailJsonObject.HasMember("post")) {
			if (trailJsonObject["post"].IsObject()) {
				const rapidjson::GenericObject<true, rapidjson::Value> postJsonObject = trailJsonObject["post"].GetObj();

				Post postEntry;

				const rapidjson::Value* idJsonPointer = TumblrAPI::getValuePointerFromJson(postJsonObject, "id");
				if (idJsonPointer != nullptr) {
					if (idJsonPointer->IsInt64()) {
						postEntry.id = idJsonPointer->GetInt64();
					} else if (idJsonPointer->IsString()) {
						postEntry.id = std::stoll(idJsonPointer->GetString());
					}
				}

				const rapidjson::Value* timestampJsonPointer = TumblrAPI::getValuePointerFromJson(postJsonObject, "timestamp");
				if (timestampJsonPointer != nullptr) {
					if (timestampJsonPointer->IsInt64()) {
						postEntry.timestamp = timestampJsonPointer->GetInt64();
					} else if (timestampJsonPointer->IsString()) {
						postEntry.timestamp = std::stoll(timestampJsonPointer->GetString());
					}
				}

				this->post = postEntry;
			}
		}

		if (trailJsonObject.HasMember("blog")) {
			if (trailJsonObject["blog"].IsObject()) {
				this->blog = MinimalBlog(trailJsonObject["blog"].GetObj());
			}
		}

		TumblrAPI::setStringFromJson(trailJsonObject, "broken_blog_name", this->broken_blog_name);

	};

	struct Post {

		/**
		 * The post's unique ID.
		 */
		long long id = 0;

		/**
		 * The time of the post, in seconds since the epoch.
		 */
		long long timestamp = 0;

	};

	/**
	 * An object with information about the Post in the reblog trail;
	 * contains at least an id field and possibly a timestamp field for when that post was created.
	 * That id won't be available for "broken" trail items.
	 */
	Post post;

	/**
	 * An object with information about the Post's blog in the reblog trail; contains at least a uuid field.
	 * This won't be available for "broken" trail items.
	 */
	MinimalBlog blog;

	/**
	 * The content of the Post in the trail.
	 */
	const std::vector<std::shared_ptr<Content>> content;

	/**
	 * The layout to use for the content of the Post in the trail.
	 */
	const std::vector<std::shared_ptr<Layout>> layout;

	/**
	 * The name of the blog from a broken trail item.
	 */
	std::string broken_blog_name;

};

#endif //TUMBLRAPI_TRAIL_HPP
