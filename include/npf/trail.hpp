//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_TRAIL_HPP
#define TUMBLRAPI_TRAIL_HPP

#include "post.hpp"


/**
 * TODO Documentation
 */
class Trail : public NPF {

public:

	/**
	 * TODO Documentation
	 */
	Trail(): NPF(){};

	/**
	 * TODO Documentation
	 */
	Post post;

	/**
	 * TODO Documentation
	 */
	Blog blog;

	/**
	 * TODO Documentation
	 */
	std::vector<Content*> content;

	/**
	 * TODO Documentation
	 */
	std::vector<Layout*> layout;

	/**
	 * TODO Documentation
	 */
	std::string broken_blog_name;

	/**
	 * TODO Documentation
	 */
	void populateNPF(JSON_OBJECT) override;

};

#endif //TUMBLRAPI_TRAIL_HPP
