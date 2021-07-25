//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include "npf/npf.hpp"

/**
 * TODO Documentation
 */
class Content : public NPF {

public:
	
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
