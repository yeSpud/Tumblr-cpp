//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_ROWS_HPP
#define TUMBLRAPI_ROWS_HPP

#include "layout.hpp"

/**
 * TODO Documentation
 */
class Rows : public Layout {

public:

	/**
	 * TODO Documentation
	 */
	Rows() : Layout(rows) {};

	// TODO
	// auto mode;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_ROWS_HPP
