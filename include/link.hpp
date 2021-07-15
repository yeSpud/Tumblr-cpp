//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_LINK_HPP
#define TUMBLRAPI_LINK_HPP

#include "rapidjson/document.h"

class link {

public:

	/**
	 * TODO Documentation
	 */
	struct Link;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Link generateLink(const rapidjson::Value &entry);


};

#endif //TUMBLRAPI_LINK_HPP
