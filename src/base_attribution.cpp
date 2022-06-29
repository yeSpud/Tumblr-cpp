//
// Created by Spud on 6/26/22.
//

#include "attributes/base_attribution.hpp"
#include "attributes/post_attribution.hpp"
#include "attributes/link_attribution.hpp"
#include "attributes/blog_attribution.hpp"
#include "attributes/app_attribution.hpp"

MinimalBlog getBlog(const rapidjson::GenericObject<true, rapidjson::Value>& attributionJsonObject) {
	if (attributionJsonObject.HasMember("blog")) {
		if (attributionJsonObject["blog"].IsObject()) {
			const rapidjson::GenericObject<true, rapidjson::Value> blogJsonObjectPointer = attributionJsonObject["blog"].GetObj();
			return MinimalBlog(blogJsonObjectPointer);
		}
	}

	// TODO Log
	return {};
}

std::shared_ptr<BaseAttribution> BaseAttribution::getAttribution(const rapidjson::GenericObject<true, rapidjson::Value>& attributionJsonObject) {

	std::string typeString;
	TumblrAPI::setStringFromJson(attributionJsonObject, "type", typeString);

	if (typeString == "post") {

		std::string urlString;
		TumblrAPI::setStringFromJson(attributionJsonObject, "url", urlString);

		PostAttribution::Post miniPost;
		if (attributionJsonObject.HasMember("post")) {
			if (attributionJsonObject["post"].IsObject()) {
				const rapidjson::GenericObject<true, rapidjson::Value> postJsonObjectPointer = attributionJsonObject["post"].GetObj();
				TumblrAPI::setInt64FromJson(postJsonObjectPointer, "id", miniPost.id);
			}
		}

		MinimalBlog blog = getBlog(attributionJsonObject);
		PostAttribution postAttribution = PostAttribution(urlString, miniPost, blog);
		return std::make_shared<PostAttribution>(postAttribution);
	} else if (typeString == "link") {

		std::string urlString;
		TumblrAPI::setStringFromJson(attributionJsonObject, "url", urlString);

		LinkAttribution linkAttribution = LinkAttribution(urlString);
		return std::make_shared<LinkAttribution>(linkAttribution);
	} else if (typeString == "blog") {

		MinimalBlog blog = getBlog(attributionJsonObject);
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
