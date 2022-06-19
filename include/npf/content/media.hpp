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
class [[deprecated("Use stand alone media class")]]Media : public Content {

public:

	/**
	 * TODO Documentation
	 */
	Media() : Content() {};

	/**
	 * The canonical URL of the media asset.
	 */
	std::string url;

	/**
	 * The width of the media asset, if that makes sense (for images and videos, but not for audio).
	 */
	int width = 0;

	/**
	 * The height of the media asset, if that makes sense (for images and videos, but not for audio).
	 */
	int height = 0;

	/**
	 * For display purposes, this indicates whether the dimensions are defaults.
	 */
	bool original_dimensions_missing = true;

	/**
	 * This indicates whether this media object is a cropped version of the original media.
	 */
	bool cropped = false;

	/**
	 * This indicates whether this media object has the same dimensions as the original media.
	 */
	bool has_original_dimensions = false;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_MEDIA_HPP
