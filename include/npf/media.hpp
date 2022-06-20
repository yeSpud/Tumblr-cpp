//
// Created by Spud on 6/19/22.
//

#ifndef TUMBLRAPI_MEDIA_HPP
#define TUMBLRAPI_MEDIA_HPP

#include "TumblrAPI.hpp"

class Media {

public:

	Media(const std::string& url, const rapidjson::Value &jsonObject):url(url) {

		// TODO

	}

	/**
	 * The canonical URL of the media asset
	 */
	const std::string& url;

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
