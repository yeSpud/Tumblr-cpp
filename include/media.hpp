//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_MEDIA_HPP
#define TUMBLRAPI_MEDIA_HPP

#include "content.hpp"

/**
 * Media objects are used for image blocks, all kinds of posters (GIF, video, etc), native audio, native video,
 * and some trusted third-party content. All media objects returned from the API should contain type and url,
 * and any video and image media objects should always contain a width and height.
 */
class Media: Content {

	//using Content::Content;

private:

	/**
	 * TODO Documentation
	 * @param type
	 * @param url
	 */
	Media(std::string type, std::string url): Content(std::move(type)), url(std::move(url)){};

	/**
	 * TODO Documentation
	 * @param type
	 * @param url
	 * @param width
	 * @param height
	 */
	Media(std::string type, std::string url, int width, int height): Content(std::move(type)), url(std::move(url)), width(width), height(height){};

public:

	[[deprecated("Please use the `generateMedia` method instead - this is here as a placeholder")]]
	Media(): Content("empty media - someone used the deprecated method..."){};

	//struct MediaObject {

	/**
	 * The canonical URL of the media asset.
	 */
	const std::string url;

	/*
	 * The MIME type of the media asset, or a best approximation will be made based on the given URL.
	 */
	//const std::string type;

	/**
	 * The width of the media asset, if that makes sense (for images and videos, but not for audio).
	 */
	int width;

	/**
	 * The height of the media asset, if that makes sense (for images and videos, but not for audio).
	 */
	int height;

	/**
	 * For display purposes, this indicates whether the dimensions are defaults.
	 */
	bool original_dimensions_missing;

	/**
	 * This indicates whether this media object is a cropped version of the original media.
	 */
	bool cropped;

	/**
	 * This indicates whether this media object has the same dimensions as the original media.
	 */
	bool has_original_dimensions;

	//};

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Media generateMedia(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_MEDIA_HPP
