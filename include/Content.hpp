//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include <vector>
#include <string>
#include "rapidjson/document.h"

/**
 * Neue Post Format stuff
 * TODO Documentation
 */
class[[deprecated("Content is being moved to their own standalone files")]] Content {


public:

	/**
	 * TODO Documentation
	 * @param entry
	 * @param value
	 * @param buffer
	 * @return
	 */
	static bool entryHasString(const rapidjson::Value &entry, const char *value, std::string &buffer);

	/**
	 * TODO Documentation
	 * @param entry
	 * @param value
	 * @param buffer
	 * @return
	 */
	static bool entryHasNumber(const rapidjson::Value &entry, const char *value, uint64_t &buffer);

	/**
	 * TODO Documentation
	 * @param entry
	 * @param value
	 * @param buffer
	 * @return
	 */
	static bool entryHasBool(const rapidjson::Value &entry, const char *value, bool &buffer);

};

#endif //TUMBLRAPI_CONTENT_HPP
