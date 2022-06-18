//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_ATTRIBUTION_HPP
#define TUMBLRAPI_ATTRIBUTION_HPP

#include "npf.hpp"

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

	//~Attribution() override;

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
	//std::shared_ptr<Post> post;

	/**
	 * A Blog pointer with at least the uuid field.
	 */
	//std::shared_ptr<Blog> blog;

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
	//Media logo;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_ATTRIBUTION_HPP
