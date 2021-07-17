//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_ROWS_HPP
#define TUMBLRAPI_ROWS_HPP

#include "layout.hpp"

class Rows : public Layout {

public:

	Rows(): Layout(rows) {};

	// TODO
	// auto mode;

	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_ROWS_HPP
