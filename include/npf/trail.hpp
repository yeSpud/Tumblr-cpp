//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_TRAIL_HPP
#define TUMBLRAPI_TRAIL_HPP

#include "post.hpp"

class Post; // Forward declaration to mitigate circular dependencies.

/**
 * TODO Documentation
 */
class Trail : public NPF {

public:

	~Trail() override;

	/**
	 * TODO Documentation
	 */
	Trail() : NPF() {};

	/**
	 * TODO Documentation
	 */
	std::shared_ptr<Post> post;

	/**
	 * TODO Documentation
	 */
	std::shared_ptr<Blog> blog;

	/**
	 * TODO Documentation
	 */
	std::vector<std::shared_ptr<Content>> content;

	/**
	 * TODO Documentation
	 */
	std::vector<std::shared_ptr<Layout>> layout;

	/**
	 * TODO Documentation
	 */
	std::string broken_blog_name;

	/**
	 * TODO Documentation
	 * @param object
	 * @param vector
	 */
	static void populateContentPointerArray(const JSON_OBJECT &object, std::vector<std::shared_ptr<Content>> &array);

	/**
	 * TODO Documentation
	 * @param object
	 * @param array
	 */
	static void populateLayoutPointerArray(const JSON_OBJECT &object, std::vector<std::shared_ptr<Layout>> &array);

	/**
	 * TODO Documentation
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_TRAIL_HPP
