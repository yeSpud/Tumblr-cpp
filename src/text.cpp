//
// Created by Spud on 7/14/21.
//

#include <string>
#include "text.hpp"

struct text::Text {

	/**
	 * TODO Documentation
	 */
	std::string type;

	/**
	 * The text to use
	 */
	std::string text;

	/**
	 * The subtype of text block
	 */
	subtype subtype;

	/**
	 * TODO Documentation
	 */
	uint64_t indent_level;

	// TODO
	// auto formatting;
};
