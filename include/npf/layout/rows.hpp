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

	std::vector<std::vector<int>> display;

	// TODO
	// auto mode;

	/**
	 * TODO Documentation
	 * @param array
	 */
	void populateBlocks(const JSON_ARRAY &array) override;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_ROWS_HPP
