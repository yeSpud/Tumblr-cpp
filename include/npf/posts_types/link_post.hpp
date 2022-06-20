//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_LINK_POSTS_HPP
#define TUMBLRAPI_LINK_POSTS_HPP

#include "content.hpp"
#include "npf/media.hpp"

class Link : public Content {

public:

	Link(const rapidjson::Value &contentJson, std::string url): Content(postType::link), url(std::move(url)) {

		TumblrAPI::setStringFromJson(contentJson, "title", this->title);
		TumblrAPI::setStringFromJson(contentJson, "description", this->description);
		TumblrAPI::setStringFromJson(contentJson, "author", this->author);
		TumblrAPI::setStringFromJson(contentJson, "site_name", this->site_name);
		TumblrAPI::setStringFromJson(contentJson, "display_name", this->display_name);

		// Poster.
		const rapidjson::Value* posterPointer = TumblrAPI::getValuePointerFromJson(contentJson, "poster");
		if (posterPointer != nullptr) {
			if (posterPointer->IsArray()) {
				rapidjson::GenericArray posterJsonArray = posterPointer->GetArray();
				for (const rapidjson::Value &posterEntry : posterJsonArray) {
					if (posterEntry.IsObject()) {
						rapidjson::GenericObject posterJsonObject = posterEntry.GetObj();
						std::string urlString;
						TumblrAPI::setStringFromJson(posterJsonObject, "url", urlString);
						Media media = Media(urlString, posterJsonObject);
						this->poster = std::make_shared<Media>(media);
					}
				}
			}
		}
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
