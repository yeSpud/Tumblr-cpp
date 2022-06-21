//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_VIDEO_POST_HPP
#define TUMBLRAPI_VIDEO_POST_HPP

#include "content.hpp"
#include "npf/media.hpp"

class Video : public Content {

public:

	explicit Video(const rapidjson::Value &contentJson): Content(postType::video) {

		TumblrAPI::setStringFromJson(contentJson, "url", this->url);

		// Media.
		Media::setMediaPointer(contentJson, this->media);

		TumblrAPI::setStringFromJson(contentJson, "provider", this->provider);
		TumblrAPI::setStringFromJson(contentJson, "embed_html", this->embed_html);

		// iFrame.
		const rapidjson::Value* iFrameJsonPointer = TumblrAPI::getValuePointerFromJson(contentJson, "embed_iframe");
		if (iFrameJsonPointer != nullptr) {
			if (iFrameJsonPointer->IsObject()) {
				rapidjson::GenericObject iFrameJsonObject = iFrameJsonPointer->GetObj();

				iFrame iframeObject;
				TumblrAPI::setStringFromJson(iFrameJsonObject, "url", iframeObject.url);
				if (iFrameJsonObject.HasMember("width")) {
					if (iFrameJsonObject["width"].IsInt()) {
						iframeObject.width = iFrameJsonObject["width"].GetInt();
					}
				}
				if (iFrameJsonObject.HasMember("height")) {
					if (iFrameJsonObject["height"].IsInt()) {
						iframeObject.height = iFrameJsonObject["height"].GetInt();
					}
				}

				this->iframe = iframeObject;
			}
		}

		TumblrAPI::setStringFromJson(contentJson, "embed_url", this->embed_url);

		// Poster.
		Media::setPosterPointer(contentJson, this->poster);

		// TODO Metadata

		// FIXME Attribution

		TumblrAPI::setBooleanFromJson(contentJson, "can_autoplay_on_cellular", this->can_autoplay_on_cellular);
	}

    /**
     * The URL to use for the video block, if no media is present.
     */
    std::string url;

	/**
	 * The Media Object to use for the video block, if no url is present.
	 */
    std::shared_ptr<Media> media;

    /**
     * The provider of the video, whether it's tumblr for native video or a trusted third party.
     */
    std::string provider;

    /**
     * HTML code that could be used to embed this video into a webpage.
     */
    std::string embed_html;

	struct iFrame {

		/**
		 * A URL used for constructing and embeddable video iframe.
		 */
		std::string url;

		/**
		 * The width of the video iframe. Default is 540.
		 */
		int width = 540;

		/**
		 * The height of the video iframe. Default is 405.
		 */
		int height = 405;

	};

	/**
	 * An embed iframe object used for constructing video iframes.
	 */
    iFrame iframe;

    /**
     * A URL to the embeddable content to use as an iframe.
     */
    std::string embed_url;

	/**
	 * An image media object to use as a "poster" for the video, usually a single frame.
	 */
    std::shared_ptr<Media> poster;

    // metadata; FIXME

	/*
	 * TODO Documentation
	 */
    // Attribution attribution;

    bool can_autoplay_on_cellular = false;

};

#endif //TUMBLRAPI_VIDEO_POST_HPP
