//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_IMAGE_HPP
#define TUMBLRAPI_IMAGE_HPP

#include <vector>
#include "content.hpp"
#include "media.hpp"

// This is where we run into circular dependencies issues. Especially with attribution.hpp.
#include "attribution.hpp" // Maybe use this as a pointer or reference instead?
// Forward declaration to mitigate circular dependencies issues with attribution.hpp and image.hpp.
class Attribution; // Actual class is located in attribution.hpp.

/**
 * TODO Documentation
 */
class Image: Content {

private:

	/**
	 * TODO Documentation
	 * @param media
	 */
	Image(Media media): Content("image"), media{std::move(media)}{};

	/**
	 * TODO Documentation
	 * @param media
	 */
	Image(std::vector<Media> media): Content("image"), media{std::move(media)}{};

public:

	[[deprecated("Please use the `generateImage` method when possible - this is here as a placeholder / for debugging")]]
	Image() :Content("Image"){};

	/**
	 * TODO Documentation
	 * Undocumented?
	 */
	std::string media_key;

	/**
	 * TODO Documentation
	 */
	std::vector<Media> media;

	// TODO
	// auto colors;

	/**
	 * TODO Documentation
	 */
	std::string feedback_token;

	/**
	 * TODO Documentation
	 */
	Media poster;

	/**
	 * TODO Documentation
	 */
	Attribution *attribution; // Attribution reference to mitigate circular dependencies issues with attribution.hpp and image.hpp.

	/**
	 * TODO Documentation
	 */
	std::string alt_text;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Image generateImage(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_IMAGE_HPP
