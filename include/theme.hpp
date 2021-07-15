//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_THEME_HPP
#define TUMBLRAPI_THEME_HPP

#include "rapidjson/document.h"

class theme {

public:

	/**
	* The blog's general theme options, which may not be useful if the blog uses a custom theme.
	* Used by blog info.
	*/
	struct Theme;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Theme generateTheme(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_THEME_HPP
