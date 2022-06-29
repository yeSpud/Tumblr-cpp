//
// Created by Spud on 6/25/22.
//

#include "posts/text_post.hpp"
#include "posts/link_post.hpp"
#include "posts/video_post.hpp"
#include "posts/audio_post.hpp"
#include "posts/image_post.hpp"

std::shared_ptr<Content> Content::getContentFromJsonObject(const rapidjson::GenericObject<true, rapidjson::Value>& contentJsonObject) {

	std::string contentTypeString;
	TumblrAPI::setStringFromJson(contentJsonObject, "type", contentTypeString);

	// TODO Change each of the post class types.
	if (contentTypeString == "text" || contentTypeString == "answer" || contentTypeString == "chat" || contentTypeString == "quote") {

		std::string text;
		TumblrAPI::setStringFromJson(contentJsonObject, "text", text);

		Text textPost = Text(contentJsonObject, text);
		return std::make_shared<Text>(textPost);
	} else if (contentTypeString == "link") {

		std::string urlString;
		TumblrAPI::setStringFromJson(contentJsonObject, "url", urlString);

		Link linkPost = Link(contentJsonObject, urlString);
		return std::make_shared<Link>(linkPost);
	} else if (contentTypeString == "video") {

		Video videoPost = Video(contentJsonObject);
		return std::make_shared<Video>(videoPost);
	} else if (contentTypeString == "audio") {

		Audio audioPost = Audio(contentJsonObject);
		return std::make_shared<Audio>(audioPost);
	} else if (contentTypeString == "image") {
		Image imagePost = Image(contentJsonObject);
		return std::make_shared<Image>(imagePost);
	} else { // TODO Add paywall post
		spdlog::get("TumblrAPI Logger")->warn("Unable to recognize content type {}", contentTypeString);
		return nullptr;
	}
}

void Content::setContentVectorFromJsonObject(const rapidjson::GenericObject<true, rapidjson::Value> &jsonObject,
                                          std::vector<std::shared_ptr<Content>> &vectorBuffer) {

	const rapidjson::Value* postContentJsonPointer = TumblrAPI::getValuePointerFromJson(jsonObject, "content");
	if (postContentJsonPointer != nullptr) {
		if (postContentJsonPointer->IsArray()) {
			rapidjson::GenericArray postContentArray = postContentJsonPointer->GetArray();
			if (!postContentArray.Empty()) {
				for (const rapidjson::Value &contentEntry : postContentArray) {
					if (contentEntry.IsObject()) {
						rapidjson::GenericObject entryObject = contentEntry.GetObj();
						auto content = Content::getContentFromJsonObject(entryObject);
						vectorBuffer.push_back(content);
					}
				}
			}
		}
	}
}