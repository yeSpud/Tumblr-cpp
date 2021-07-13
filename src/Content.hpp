//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include <string>
#include "rapidjson/document.h"

class Content {

public:

	struct Theme {
		// TODO Used by blog info
	};

	struct Text {
		// TODO
	};

	struct Image {

		/**
		 * TODO Documentation
		 */
		std::string type;

		/**
		 * TODO Documentation
		 */
		std::string media_key;

		/**
		 * TODO Documentation
		 */
		unsigned int width;

		/**
		 * TODO Documentation
		 */
		unsigned int height;

		/**
		 * TODO Documentation
		 */
		std::string url;

		/**
		 * TODO Documentation
		 */
		bool has_original_dimensions = false;

	};

	struct Link {
		// TODO
	};

	struct Audio {
		// TODO
	};

	struct Video {
		// TODO
	};

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
	static bool entryHasInt(const rapidjson::Value &entry, const char *value, unsigned int &buffer);

};

#endif //TUMBLRAPI_CONTENT_HPP
