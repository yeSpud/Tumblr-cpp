//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include <string>
#include "npf/npf.hpp"

/**
 * TODO Documentation
 */
class Content : public NPF {

public:

	[[deprecated("Use the constructor with the type name.")]]
	Content() : NPF() {};

	/**
	 * TODO Documentation
	 * @param type
	 */
	explicit Content(std::string type) : type(std::move(type)), NPF() {};

	/**
	 * TODO Documentation
	 */
	std::string type;

};

#endif //TUMBLRAPI_CONTENT_HPP
