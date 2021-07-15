//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_ATTRIBUTION_HPP
#define TUMBLRAPI_ATTRIBUTION_HPP

#include "post.hpp"
#include "blog.hpp"
#include "media.hpp"

/**
 * TODO Documentation
 */
class Attribution {

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
	Attribution(const attributionType type) : type(type) {};

	//struct Attribution;
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
	 * A Post pointer with at least the id field.
	 */
	post::Post *postObject;

	/**
	 * A Blog pointer with at least the uuid field.
	 */
	Blog blogObject;

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
	 * @return
	 */
	static Attribution generateAttribution(const rapidjson::Value &entry);

private:

	/**
	 * TODO Documentation
	 * @param type
	 * @param url
	 * @param post
	 * @param blog
	 */
	Attribution(const attributionType type, std::string url, post::Post *post, Blog blog) : type(type),
	                                                                                               url(std::move(url)),
	                                                                                               postObject(post),
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
	Attribution(const attributionType type, Blog blog) : type(type), blogObject(std::move(blog)) {};

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
