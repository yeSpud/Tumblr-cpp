//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_VIDEO_POST_HPP
#define TUMBLRAPI_VIDEO_POST_HPP

#include "content.hpp"
#include "media.hpp"
#include "attributes/base_attribution.hpp"

class Video : public Content {

public:

	explicit Video(const rapidjson::GenericObject<true, rapidjson::Value>& contentJsonObject): Content(postType::video) {

		TumblrAPI::setStringFromJson(contentJsonObject, "url", this->url);

		// Media.
		Media::setMediaPointer(contentJsonObject, this->media);

		TumblrAPI::setStringFromJson(contentJsonObject, "provider", this->provider);
		TumblrAPI::setStringFromJson(contentJsonObject, "embed_html", this->embed_html);

		// iFrame.
		const rapidjson::Value* iFrameJsonPointer = TumblrAPI::getValuePointerFromJson(contentJsonObject, "embed_iframe");
		if (iFrameJsonPointer != nullptr) {
			if (iFrameJsonPointer->IsObject()) {
				rapidjson::GenericObject iFrameJsonObject = iFrameJsonPointer->GetObj();

				iFrame iframeObject;

				TumblrAPI::setStringFromJson(iFrameJsonObject, "url", iframeObject.url);

				TumblrAPI::setIntFromJson(iFrameJsonObject, "width", iframeObject.width);
				TumblrAPI::setIntFromJson(iFrameJsonObject, "height", iframeObject.height);

				this->iframe = iframeObject;
			}
		}

		TumblrAPI::setStringFromJson(contentJsonObject, "embed_url", this->embed_url);

		// Poster.
		Media::setPosterPointer(contentJsonObject, this->poster);

		// TODO Metadata

		// Attribution
		if (contentJsonObject.HasMember("attribution")) {
			if (contentJsonObject["attribution"].IsObject()) {
				this->attribution = BaseAttribution::getAttribution(contentJsonObject["attribution"].GetObj());
			}
		}

		TumblrAPI::setBooleanFromJson(contentJsonObject, "can_autoplay_on_cellular", this->can_autoplay_on_cellular);
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
		int width = 540; // TODO Change to unsigned int

		/**
		 * The height of the video iframe. Default is 405.
		 */
		int height = 405; // TODO Change to unsigned int

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

	/**
	 * Optional attribution information about where the video came from.
	 */
    std::shared_ptr<BaseAttribution> attribution;

    bool can_autoplay_on_cellular = false;

};

#endif //TUMBLRAPI_VIDEO_POST_HPP
