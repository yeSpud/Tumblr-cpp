//
// Created by Spud on 6/20/22.
//

#ifndef TUMBLRAPI_BLOG_HPP
#define TUMBLRAPI_BLOG_HPP

#include "base_attribution.hpp"
#include "minimal_blog.hpp"

class BlogAttribution: public BaseAttribution {

public:

	explicit BlogAttribution(const rapidjson::GenericObject<true, rapidjson::Value>& attributionJsonObject, MinimalBlog blog):
	BaseAttribution(attributionType::blog), blog(std::move(blog)) {

		TumblrAPI::setStringFromJson(attributionJsonObject, "url", this->url);
	}

	/**
	 * A Blog object with at least a uuid field.
	 */
	const MinimalBlog blog;

	/**
	 * TODO Documentation
	 */
	std::string url;

};

#endif //TUMBLRAPI_BLOG_HPP
