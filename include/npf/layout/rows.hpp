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

	/**
	 * TODO Documentation
	 */
	std::vector<std::vector<int>> display;

	/**
	 * The last block to display before the Read More signifier. Required if blocks is not supplied.
	 */
	int truncate_after = 0;

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
