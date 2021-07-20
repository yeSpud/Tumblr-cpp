//
// Created by Spud on 7/17/21.
//

#ifndef TUMBLRAPI_LAYOUT_HPP
#define TUMBLRAPI_LAYOUT_HPP

#include "npf/npf.hpp"

/**
 * TODO Documentation
 */
class Layout : public NPF {

protected:

	/**
	 * TODO Documentation
	 */
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

	/**
	 * TODO Documentation
	 * @param type
	 */
	explicit Layout(layoutType type) : type(type), NPF() {};

	/**
	 * TODO Documentation
	 */
	const layoutType type;

	/**
	 * TODO Documentation
	 */
	std::vector<int> blocks;

};

#endif //TUMBLRAPI_LAYOUT_HPP
