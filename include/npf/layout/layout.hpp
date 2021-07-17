//
// Created by Spud on 7/17/21.
//

#ifndef TUMBLRAPI_LAYOUT_HPP
#define TUMBLRAPI_LAYOUT_HPP

/**
 * TODO Documentation
 */
class Layout : public NPF {

public:

	/**
	 * TODO Documentation
	 * @param type
	 */
	Layout(layoutType type) : type(type) {};

	/**
	 * TODO Documentation
	 */
	enum layoutType {
		rows, ask, condensed
	};

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
