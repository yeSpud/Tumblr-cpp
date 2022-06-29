//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_CAROUSEL_HPP
#define TUMBLRAPI_CAROUSEL_HPP

#include "rows.hpp"

class Carousel : public Rows {

public:

	explicit Carousel(const rapidjson::GenericObject<true, rapidjson::Value>& layoutJsonObject) : Rows(layoutJsonObject) {

		TumblrAPI::setIntFromJson(layoutJsonObject, "truncate_after", this->truncate_after);
	};

	/**
	 * The last block to display before the Read More signifier. Required if blocks is not supplied.
	 */
	int truncate_after = 0;

};

#endif //TUMBLRAPI_CAROUSEL_HPP
