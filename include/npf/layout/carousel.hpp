//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_CAROUSEL_HPP
#define TUMBLRAPI_CAROUSEL_HPP

#include "rows.hpp"

/**
 * TODO Documentation
 */
class Carousel : public Rows {

public:

	/**
	 * TODO Documentation
	 */
	Carousel() : Rows() {};

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_CAROUSEL_HPP
