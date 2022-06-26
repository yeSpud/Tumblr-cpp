//
// Created by Spud on 6/26/22.
//

#include "attributes/base_attribution.hpp"
#include "attributes/post_attribution.hpp"
#include "attributes/link_attribution.hpp"
#include "attributes/blog_attribution.hpp"
#include "attributes/app_attribution.hpp"

std::shared_ptr<BaseAttribution> BaseAttribution::getAttribution(const rapidjson::GenericObject<true, rapidjson::Value> attributionJsonObject) {

	std::string typeString;
	TumblrAPI::setStringFromJson(attributionJsonObject, "type", typeString);

	if (typeString == "post") {

		std::string urlString;
		TumblrAPI::setStringFromJson(attributionJsonObject, "url", urlString);

		PostAttribution::Post miniPost;
		if (attributionJsonObject["post"].IsObject()) {
			const rapidjson::GenericObject postJsonObject = attributionJsonObject["post"].GetObj();
			if (postJsonObject.HasMember("id")) {
				if (postJsonObject["id"].IsInt64()) {
					miniPost.id = postJsonObject["id"].GetInt64();
				}
			}
		}

		MinimalBlog blog;
		if (attributionJsonObject.HasMember("blog")) {
			if (attributionJsonObject["blog"].IsObject()) {
				blog = MinimalBlog(attributionJsonObject["blog"].GetObj());
			}
		}

		PostAttribution postAttribution = PostAttribution(urlString, miniPost, blog);
		return std::make_shared<PostAttribution>(postAttribution);
	} else if (typeString == "link") {

		std::string urlString;
		TumblrAPI::setStringFromJson(attributionJsonObject, "url", urlString);

		LinkAttribution linkAttribution = LinkAttribution(urlString);
		return std::make_shared<LinkAttribution>(linkAttribution);
	} else if (typeString == "blog") {

		MinimalBlog blog;
		if (attributionJsonObject.HasMember("blog")) {
			if (attributionJsonObject["blog"].IsObject()) {
				blog = MinimalBlog(attributionJsonObject["blog"].GetObj());
			}
		}


		BlogAttribution blogAttribution = BlogAttribution(attributionJsonObject, blog);
		return std::make_shared<BlogAttribution>(blogAttribution);
	} else if (typeString == "app") {

		std::string urlString;
		TumblrAPI::setStringFromJson(attributionJsonObject, "url", urlString);

		AppAttribution appAttribution = AppAttribution(attributionJsonObject, urlString);
		return std::make_shared<AppAttribution>(appAttribution);
	} else {
		spdlog::get("TumblrAPI Logger")->warn("Unable to determine attribution based on type {}", typeString);
		return nullptr;
	}
}
