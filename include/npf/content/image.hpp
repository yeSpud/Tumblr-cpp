//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_IMAGE_HPP
#define TUMBLRAPI_IMAGE_HPP

#include "npf/attribution.hpp"

/**
 * TODO Documentation
 */
class Image : public Content {

public:

	~Image() override;

	Image() : Content("image") {};

	/**
	 * An array of Media objects which represent different available sizes of this image asset.
	 */
	std::vector<Media> media;

	// TODO
	// auto colors;

	/**
	 * A feedback token to use when this image is a GIF search result.
	 */
	std::string feedback_token;

	/**
	 * For GIFs, this is a single-frame "poster".
	 */
	Media poster;

	/**
	 * TODO Documentation
	 */
	std::shared_ptr<Attribution> attribution;

	/**
	 * Text used to describe the image, for screen readers. 200 character maximum.
	 */
	std::string alt_text;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_IMAGE_HPP
