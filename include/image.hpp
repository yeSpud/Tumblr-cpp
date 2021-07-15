//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_IMAGE_HPP
#define TUMBLRAPI_IMAGE_HPP

#include "content.hpp"
#include "media.hpp"

/**
 * TODO Documentation
 */
class Image: Content {

private:

	/**
	 * TODO Documentation
	 * @param media
	 */
	Image(Media media): Content("image"), media(media){};

public:

	/*
	 * The MIME type of the image asset, or a best approximation will be made based on the given URL
	 */
	//std::string type;

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
	Attribution attribution;

	/**
	 * TODO Documentation
	 */
	std::string alt_text;

	//struct Image;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Image generateImage(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_IMAGE_HPP
