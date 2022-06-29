//
// Created by Spud on 6/20/22.
//

#ifndef TUMBLRAPI_POST_ATTRIBUTION_HPP
#define TUMBLRAPI_POST_ATTRIBUTION_HPP

#include "base_attribution.hpp"
#include "minimal_blog.hpp"

class PostAttribution: public BaseAttribution {

public:

	struct Post {

		/**
		 * The post's unique ID.
		 */
		long long id = 0;

	};

	PostAttribution(std::string url, const Post post, MinimalBlog blog):BaseAttribution(attributionType::post),
	url(std::move(url)), post(post), blog(std::move(blog)) {}

	/**
	 * The URL of the Post to be attributed.
	 */
	const std::string url;

	/**
	 * A Post object with at least an id field.
	 */
	const Post post;

	/**
	 * A Blog object with at least a uuid field.
	 */
	const MinimalBlog blog;

};

#endif //TUMBLRAPI_POST_ATTRIBUTION_HPP
