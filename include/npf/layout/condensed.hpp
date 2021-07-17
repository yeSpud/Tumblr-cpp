//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_CONDENSED_HPP
#define TUMBLRAPI_CONDENSED_HPP

#include "layout.hpp"

/**
 * The condensed layout is deprecated and replaced by the truncate_after property in the rows layout.
 * Please use the rows layout to get or set a recommended truncation index. If a post is created with a condensed layout,
 * it will be ignored by the backend. In other words, a read-more will not show up in the post.
 *
 * TODO Documentation
 *
 */
class [[deprecated("The condensed layout is deprecated and replaced by the truncate_after property in the rows layout. "
				   "Please use the rows layout to get or set a recommended truncation index.")]] Condensed : public Layout {

public:

	/**
	 * TODO Documentation
	 */
	Condensed(): Layout(condensed){};

	/**
	 * The last block to display before the Read More signifier. Required if blocks is not supplied.
	 */
	int truncate_after;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_CONDENSED_HPP
