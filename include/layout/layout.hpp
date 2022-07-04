//
// Created by Spud on 7/17/21.
//

#ifndef TUMBLRAPI_LAYOUT_HPP
#define TUMBLRAPI_LAYOUT_HPP

#include "rapidjson/document.h"
#include <vector>

class Layout {

protected:

	enum layoutType {

		/**
		 * TODO Documentation
		 */
		rows,

		/**
		 * TODO Documentation
		 */
		ask,

		/**
		 * The condensed layout is deprecated. Please use the rows layout to get or set a recommended truncation index.
		 */
		condensed
	};

public:

	explicit Layout(layoutType type) : type(type) {};

	/**
	 * TODO Documentation
	 */
	const layoutType type;

	/**
	 * TODO Documentation
	 * @param layoutJsonObject
	 * @return
	 */
	static std::shared_ptr<Layout> getLayoutFromJsonObject(const rapidjson::GenericObject<true, rapidjson::Value>& layoutJsonObject);

	/**
	 * TODO Documentation
	 * @param jsonObject
	 * @param vectorBuffer
	 */
	static void setLayoutVectorFromJsonObject(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject,
											  std::vector<std::shared_ptr<Layout>>& vectorBuffer);

};

#endif //TUMBLRAPI_LAYOUT_HPP
