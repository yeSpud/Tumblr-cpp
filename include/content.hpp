//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include <string>
#include "npf.hpp"

/**
 * TODO Documentation
 */
class Content: NPF {

public:

	/**
	 * TODO Documentation
	 * @param type
	 */
	explicit Content(std::string type): type(std::move(type)) {};

	const std::string type;

};

#endif //TUMBLRAPI_CONTENT_HPP
