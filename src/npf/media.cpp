//
// Created by Spud on 6/20/22.
//
#include "npf/media.hpp"

void setPointer(const rapidjson::Value &json, std::shared_ptr<Media> &buffer) {
	if (json.IsObject()) {
		rapidjson::GenericObject jsonObject = json.GetObj();

		std::string urlString;
		TumblrAPI::setStringFromJson(jsonObject, "url", urlString);
		Media mediaObject = Media(urlString, jsonObject);
		buffer = std::make_shared<Media>(mediaObject);
		return;
	}
}

void Media::setMediaPointer(const rapidjson::GenericObject<true, rapidjson::Value>& contentJsonObject, std::shared_ptr<Media> &mediaBuffer) {

	const rapidjson::Value* mediaValuePointer = TumblrAPI::getValuePointerFromJson(contentJsonObject, "media");
	if (mediaValuePointer != nullptr) {
		setPointer(*mediaValuePointer, mediaBuffer);
		return;
	}
	// TODO Log warning
}

void Media::setPosterPointer(const rapidjson::GenericObject<true, rapidjson::Value>& contentJsonObject, std::shared_ptr<Media> &posterBuffer) {

	const rapidjson::Value* posterValuePointer = TumblrAPI::getValuePointerFromJson(contentJsonObject, "poster");
	if (posterValuePointer != nullptr) {
		if (posterValuePointer->IsArray()) {
			rapidjson::GenericArray posterJsonArray = posterValuePointer->GetArray();

			setPointer(posterJsonArray[0], posterBuffer);
			return;
		}
	}
	// TODO Log warning
}
