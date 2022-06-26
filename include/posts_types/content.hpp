//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include <rapidjson/document.h>

/**
 * TODO Documentation
 */
class Content {

public:

	/**
	 * TODO Documentation
	 */
	enum postType {

		/**
		 * TODO Documentation
		 */
		text,

		/**
		 * TODO Documentation
		 */
		quote,

		/**
		 * TODO Documentation
		 */
		link,

		/**
		 * TODO Documentation
		 */
		answer,

		/**
		 * TODO Documentation
		 */
		video,

		/**
		 * TODO Documentation
		 */
		audio,

		/**
		 * TODO Documentation
		 */
		photo,

		/**
		 * TODO Documentation
		 */
		chat,

		/**
		 * TODO Documentation
		 */
		all
	};

	/**
	 * TODO Documentation
	 * @param type
	 */
	explicit Content(const Content::postType &type) : type(type){};

	/**
	 * TODO Documentation
	 */
	const Content::postType type;

	/**
	 * TODO Documentation
	 * @param contentJsonArray
	 * @return
	 */
	static std::shared_ptr<Content> getContentFromJsonObject(const rapidjson::GenericObject<true, rapidjson::Value>& contentJsonObject);

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param vectorBuffer
	 */
	static void setContentVectorFromJsonObject(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject,
											   std::vector<std::shared_ptr<Content>>& vectorBuffer);

};

#endif //TUMBLRAPI_CONTENT_HPP
