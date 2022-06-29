//
// Created by Spud on 6/28/22.
//

#include "posts/image_post.hpp"

void Image::setPoster(const rapidjson::GenericObject<true, rapidjson::Value>& mediaJsonObject) {

	if (mediaJsonObject.HasMember("poster")) {
		if (mediaJsonObject["poster"].IsObject()) {
			const rapidjson::GenericObject<true, rapidjson::Value> posterValueObject = mediaJsonObject["poster"].GetObj();

			std::string posterUrl;
			TumblrAPI::setStringFromJson(posterValueObject, "url", posterUrl);
			Media posterObject = Media(posterUrl, posterValueObject);
			this->poster = std::make_shared<Media>(posterObject);
		}
	}
}
