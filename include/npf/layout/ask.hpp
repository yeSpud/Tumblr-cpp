//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_ASK_HPP
#define TUMBLRAPI_ASK_HPP

#include "layout.hpp"
#include "npf/attribution.hpp"

class Ask : public Layout {

public:

	Ask() : Layout(layoutType::ask) {};

	/**
	 * If the ask is not anonymous, this will include information about the blog that submitted the ask.
	 */
	Attribution attribution;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_ASK_HPP
