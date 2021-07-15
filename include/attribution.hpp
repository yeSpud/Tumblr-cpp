//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_ATTRIBUTION_HPP
#define TUMBLRAPI_ATTRIBUTION_HPP

#include "post.hpp"
#include "blog.hpp"

class attribution {

public:

	/**
	 * TODO Documentation
	 */
		enum attributionType {
			link, blog, post, app
		};

	/**
	 * TODO Documentation
	 */
	struct Attribution {

		/**
		 * The type of the attribution.
		 * Current valid values are "link", "blog", "post", or "app".
		 */
		attributionType type;

		/**
		 * The URL to be attributed.
		 */
		std::string url;

		/**
		 * A Post with at least the id field.
		 */
		post::Post post;

		/**
		 * A Blog with at least the uuid field.
		 */
		blog::Blog blog;

		/**
		 * The name of the application to be attributed.
		 */
		std::string app_name;

		/**
		 * Any display text that the client should use with the attribution.
		 */
		std::string display_text;

		/**
		 * A specific logo that the client should use with the third-party app attribution.
		 */
		media::MediaObject logo;

		/**
		 * TODO Documentation
		 * @param entry
		 * @return
		 */
		static attribution::Attribution generateAttribution(const rapidjson::Value &entry);

	};

};


#endif //TUMBLRAPI_ATTRIBUTION_HPP
