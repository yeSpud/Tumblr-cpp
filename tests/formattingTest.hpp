//
// Created by Spud on 7/24/21.
//

#ifndef TUMBLRAPI_FORMATTINGTEST_HPP
#define TUMBLRAPI_FORMATTINGTEST_HPP

#include "npf/content/formatting.hpp"

class FormattingTest {

public:

	/**
	 * TODO Documentation
	 * @param formatting
	 * @param type
	 * @param start
	 * @param end
	 * @param url
	 * @param hex
	 */
	static void testFormatting(const Formatting &formatting, const std::string &type, const int &start, const int &end,
	                           const std::string &url, const std::string &hex);

};

#endif //TUMBLRAPI_FORMATTINGTEST_HPP
