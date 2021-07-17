//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_CAROUSEL_HPP
#define TUMBLRAPI_CAROUSEL_HPP

#include "rows.hpp"

class Carousel : public Rows {

public:

	Carousel()= default;;

	/**
	 * The last block to display before the Read More signifier. Required if blocks is not supplied.
	 */
	int truncate_after;

	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_CAROUSEL_HPP
