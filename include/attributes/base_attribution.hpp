//
// Created by Spud on 6/20/22.
//

#ifndef TUMBLRAPI_BASE_ATTRIBUTION_HPP
#define TUMBLRAPI_BASE_ATTRIBUTION_HPP

#include <rapidjson/document.h>

class BaseAttribution {

public:

	enum attributionType {

		/**
		 * TODO Documentation
		 */
		link,

		/**
		 * TODO Documentation
		 */
		blog,

		/**
		 * TODO Documentation
		 */
		post,

		/**
		 * TODO Documentation
		 */
		app
	};

	explicit BaseAttribution(const attributionType type):type(type) {}

	/**
	 * TODO Documentation
	 */
	const attributionType type;

	/**
	 * TODO Documentation
	 * @param attributionJsonObject
	 * @return
	 */
	static std::shared_ptr<BaseAttribution> getAttribution(const rapidjson::GenericObject<true, rapidjson::Value> attributionJsonObject);

};

#endif //TUMBLRAPI_BASE_ATTRIBUTION_HPP
