//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_ASK_HPP
#define TUMBLRAPI_ASK_HPP

#include "layout.hpp"
#include "npf/attribution.hpp"

/**
 * TODO Documentation
 */
class Ask : public Layout {

public:

	/**
	 * TODO Documentation
	 */
	Ask() : Layout(layoutType::ask) {};

	/**
	 * If the ask is not anonymous, this will include information about the blog that submitted the ask.
	 */
	Attribution attribution;

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

#endif //TUMBLRAPI_ASK_HPP
