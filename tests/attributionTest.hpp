//
// Created by Spud on 7/24/21.
//

#ifndef TUMBLRAPI_ATTRIBUTIONTEST_HPP
#define TUMBLRAPI_ATTRIBUTIONTEST_HPP

#include "npf/attribution.hpp"

/**
 * TODO Documentation
 */
class AttributionTest {

public:

	/**
	 * TODO Documentation
	 * @param attribution
	 * @param type
	 * @param url
	 * @param app_name
	 * @param display_text
	 */
	static void testAttribution(const Attribution &attribution, const attributionType &type, const std::string &url, const std::string &app_name,
	                            const std::string &display_text);
};


#endif //TUMBLRAPI_ATTRIBUTIONTEST_HPP
