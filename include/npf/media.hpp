//
// Created by Spud on 6/19/22.
//

#ifndef TUMBLRAPI_MEDIA_HPP
#define TUMBLRAPI_MEDIA_HPP

#include "TumblrAPI.hpp"

class Media {

public:

	Media(std::string url, const rapidjson::Value &jsonObject):url(std::move(url)) {

		TumblrAPI::setStringFromJson(jsonObject, "type", this->type);

		const rapidjson::Value* widthJsonPointer = TumblrAPI::getValuePointerFromJson(jsonObject, "width");
		if (widthJsonPointer != nullptr) {
			if (widthJsonPointer->IsUint()) {
				this->width = widthJsonPointer->GetUint();
			}
		}

		const rapidjson::Value* heightJsonPointer = TumblrAPI::getValuePointerFromJson(jsonObject, "height");
		if (heightJsonPointer != nullptr) {
			if (heightJsonPointer->IsUint()) {
				this->height = heightJsonPointer->GetUint();
			}
		}

		TumblrAPI::setBooleanFromJson(jsonObject, "original_dimensions_missing", this->original_dimensions_missing);
		TumblrAPI::setBooleanFromJson(jsonObject, "cropped", this->cropped);
		TumblrAPI::setBooleanFromJson(jsonObject, "has_original_dimensions", this->has_original_dimensions);
	}

	/**
	 * The canonical URL of the media asset
	 */
	const std::string url;

	/**
	 * The MIME type of the media asset, or a best approximation will be made based on the given URL
	 */
	std::string type;

	/**
	 * The width of the media asset, if that makes sense (for images and videos, but not for audio). Default is 540.
	 */
	unsigned int width = 540;

	/**
	 * The height of the media asset, if that makes sense (for images and videos, but not for audio). Default is 405.
	 */
	unsigned int height = 405;

	/**
	 * For display purposes, this indicates whether the dimensions are defaults.
	 */
	bool original_dimensions_missing = false;

	/**
	 * This indicates whether this media object is a cropped version of the original media.
	 */
	bool cropped = false;

	/**
	 * This indicates whether this media object has the same dimensions as the original media.
	 */
	bool has_original_dimensions = false;

};

#endif //TUMBLRAPI_MEDIA_HPP
