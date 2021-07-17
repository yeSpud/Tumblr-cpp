//
// Created by Spud on 7/17/21.
//

#ifndef TUMBLRAPI_LAYOUT_HPP
#define TUMBLRAPI_LAYOUT_HPP

#include <vector>
#include "npf/npf.hpp"

/**
 * TODO Documentation
 */
enum layoutType {
	rows, ask, condensed
};

/**
 * TODO Documentation
 */
class Layout : public NPF {

public:

	/**
	 * TODO Documentation
	 * @param type
	 */
	explicit Layout(layoutType type) : type(type) {};

	/**
	 * TODO Documentation
	 */
	layoutType type;

	/**
	 * TODO Documentation
	 */
	std::vector<int> blocks;

};

#endif //TUMBLRAPI_LAYOUT_HPP
