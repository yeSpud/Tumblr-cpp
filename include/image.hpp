//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_IMAGE_HPP
#define TUMBLRAPI_IMAGE_HPP

#include "rapidjson/document.h"

/**
 * TODO Documentation
 */
class image {

public:

	/**
	 * TODO Documentation
	 */
	struct Image;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Image generateImage(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_IMAGE_HPP
