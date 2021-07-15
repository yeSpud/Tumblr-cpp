//
// Created by Spud on 7/14/21.
//

#include <string>
#include "media.hpp"

struct media::MediaObject {

	/**
	 * The canonical URL of the media asset.
	 */
	std::string url;

	/**
	 * The MIME type of the media asset, or a best approximation will be made based on the given URL.
	 */
	std::string type;

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

};
