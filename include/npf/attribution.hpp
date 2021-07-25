//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_ATTRIBUTION_HPP
#define TUMBLRAPI_ATTRIBUTION_HPP

#include "post.hpp"

// This is where we run into circular dependencies issues. Especially with image.hpp, post.hpp, and blog.hpp.
// Forward declaration to prevent major errors with image.hpp. Image is actually initialized in image.hpp and image.cpp.
class Image; // Actual class is located in image.hpp. // TODO Remove / Replace with Media?
class Blog; // Actual class is located in blog.hpp.
class Post; // Actual class is located in post.hpp.

/**
 * TODO Documentation
 */
enum attributionType {

	/**
	 * TODO Documentation
	 */
	attribution_link,

	/**
	 * TODO Documentation
	 */
	attribution_blog,

	/**
	 * TODO Documentation
	 */
	attribution_post,

	/**
	 * TODO Documentation
	 */
	attribution_app
};

/**
 * TODO Documentation
 */
class Attribution : NPF {

public:

	/**
	 * TODO Documentation & comments
	 */
	~Attribution() {

		DELETE_NPF(postObject)

		DELETE_NPF(blogObject)
	}

	/**
	 * The type of the attribution.
	 * Current valid values are "link", "blog", "post", or "app".
	 */
	attributionType type = attribution_post;

	/**
	 * The URL to be attributed.
	 */
	std::string url;

	/**
	 * A post pointer with at least the id field.
	 */
	Post *postObject = nullptr; // Post is a pointer to mitigate circular dependencies issues with attribution.hpp and image.hpp.

	/**
	 * A Blog pointer with at least the uuid field.
	 */
	Blog *blogObject = nullptr; // Blog is a pointer to mitigate circular dependencies issues with attribution.hpp and image.hpp.

	/**
	 * The name of the application to be attributed.
	 */
	std::string app_name;

	/**
	 * Any display text that the client should use with the attribution.
	 */
	std::string display_text;

	/**
	 * A specific logo that the client should use with the third-party app attribution.
	 */
	Media logo; // TODO Convert to image?

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_ATTRIBUTION_HPP
