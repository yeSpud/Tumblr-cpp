//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_ATTRIBUTION_HPP
#define TUMBLRAPI_ATTRIBUTION_HPP

#include "post.hpp"

// This is where we run into circular dependencies issues. Especially with image.hpp, post.hpp, and blog.hpp.
// Forward declaration to prevent major errors with image.hpp. Image is actually initialized in image.hpp and image.cpp.
class Image; // Actual class is located in image.hpp.
class Blog; // Actual class is located in blog.hpp.
class Post; // Actual class is located in post.hpp.

/**
 * TODO Documentation
 */
class Attribution : NPF {

public:

	/**
	 * TODO Documentation
	 */
	enum attributionType {
		link, blog, post, app
	};

	/**
	 * TODO Documentation
	 * @param type
	 */
	[[deprecated("Use the generateAttribution method as this is just here as a placeholder")]]
	explicit Attribution(const attributionType type) : type(type) {};

	/**
	 * The type of the attribution.
	 * Current valid values are "link", "blog", "post", or "app".
	 */
	const attributionType type;

	/**
	 * The URL to be attributed.
	 */
	std::string url;

	/**
	 * A post pointer with at least the id field.
	 */
	Post* postObject; // Post is a pointer to mitigate circular dependencies issues with attribution.hpp and image.hpp.

	/**
	 * A Blog pointer with at least the uuid field.
	 */
	Blog* blogObject; // Blog is a pointer to mitigate circular dependencies issues with attribution.hpp and image.hpp.

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
	Media logo = Media();

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSONOBJECT entry) override;

private:

	/**
	 * TODO Documentation
	 * @param type
	 * @param url
	 * @param post
	 * @param blog
	 */
	Attribution(const attributionType type, std::string url, Post *post, Blog *blog) : type(type), url(std::move(url)),
	                                                                                 postObject(std::move(post)),
	                                                                                 blogObject(std::move(blog)) {};

	/**
	 * TODO Documentation
	 * @param type
	 * @param url
	 */
	Attribution(const attributionType type, std::string url) : type(type), url(std::move(url)) {};

	/**
	 * TODO Documentation
	 * @param type
	 * @param blog
	 */
	Attribution(const attributionType type, Blog* blog) : type(type), blogObject(std::move(blog)) {};

	/**
	 * TODO Documentation
	 * @param type
	 * @param url
	 * @param app_name
	 * @param display_text
	 * @param logo
	 */
	Attribution(const attributionType type, std::string url, std::string app_name = "", std::string display_text = "",
	            Media logo = Media()) : type(type), url(std::move(url)), app_name(std::move(app_name)),
	                                    display_text(std::move(display_text)),
	                                    logo(std::move(logo)) {};

};

#endif //TUMBLRAPI_ATTRIBUTION_HPP
