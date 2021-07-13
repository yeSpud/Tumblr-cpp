//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include <string>

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
		 * TODO Documentaiton
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

};


#endif //TUMBLRAPI_CONTENT_HPP
