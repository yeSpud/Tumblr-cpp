//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_LINK_POSTS_HPP
#define TUMBLRAPI_LINK_POSTS_HPP

#include "content.hpp"
#include "npf/media.hpp"

class Link : public Content {

public:

	Link(const rapidjson::GenericObject<true, rapidjson::Value>& contentJsonObject, std::string url): Content(postType::link), url(std::move(url)) {

		TumblrAPI::setStringFromJson(contentJsonObject, "title", this->title);
		TumblrAPI::setStringFromJson(contentJsonObject, "description", this->description);
		TumblrAPI::setStringFromJson(contentJsonObject, "author", this->author);
		TumblrAPI::setStringFromJson(contentJsonObject, "site_name", this->site_name);
		TumblrAPI::setStringFromJson(contentJsonObject, "display_name", this->display_name);

		// Poster.
		Media::setPosterPointer(contentJsonObject, this->poster);
	};

    /**
     * The URL to use for the link block.
     */
    const std::string url;

    /**
     * The title of where the link goes.
     */
    std::string title;

    /**
     * The description of where the link goes.
     */
    std::string description;

    /**
     * The author of the link's post.
     */
    std::string author;

    /**
     * The name of the site being linked to.
     */
    std::string site_name;

    /**
     * Supplied on NPF Post consumption, ignored during NPF Post creation.
     */
    std::string display_name;

	/**
	 * An image media object to use as a "poster" for the link.
	 */
    std::shared_ptr<Media> poster;

};

#endif //TUMBLRAPI_LINK_POSTS_HPP
