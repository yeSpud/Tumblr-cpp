//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_IMAGE_HPP
#define TUMBLRAPI_IMAGE_HPP

#include "media.hpp"

// This is where we run into circular dependencies issues. Especially with attribution.hpp.
#include "npf/attribution.hpp" // Maybe use this as a pointer or reference instead?

// Forward declaration to mitigate circular dependencies issues with attribution.hpp and image.hpp.
class Attribution; // Actual class is located in attribution.hpp.

/**
 * TODO Documentation
 */
class Image : public Content {

public:

	Image() : Content("image") {};

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	std::string media_key;

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
	Attribution *attribution = nullptr; // Attribution reference to mitigate circular dependencies issues with attribution.hpp and image.hpp.

	/**
	 * Text used to describe the image, for screen readers. 200 character maximum.
	 */
	std::string alt_text;

	/**
	 * TODO Documentation
	 */
	~Image() override { DELETE_NPF(attribution)};

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_IMAGE_HPP
