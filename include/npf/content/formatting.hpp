//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_FORMATTING_HPP
#define TUMBLRAPI_FORMATTING_HPP

#include "blog.hpp"

/**
* TODO Documentation
*/
class Formatting : public Content {

public:

	/**
	 * TODO Documentation
	 */
	Formatting() : Content() {};

	/**
	 * The starting index of the formatting range (inclusive).
	 */
	int start = 0;

	/**
	 * The ending index of the formatting range (exclusive).
	 */
	int end = 0;

	/**
	 * The link's URL!
	 */
	std::string url;

	/**
	 * A blog with the uuid field.
	 */
	Blog blog;

	/**
	 * The color to use, in standard hex format, with leading #.
	 */
	std::string hex;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_FORMATTING_HPP
