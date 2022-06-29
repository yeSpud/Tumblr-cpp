//
// Created by spud on 6/20/22.
//

#ifndef TUMBLRAPI_APP_ATTRIBUTION_HPP
#define TUMBLRAPI_APP_ATTRIBUTION_HPP

#include "base_attribution.hpp"
#include "media.hpp"

class AppAttribution : public BaseAttribution {

public:

	AppAttribution(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject, std::string url): BaseAttribution(attributionType::app), url(std::move(url)) {

		TumblrAPI::setStringFromJson(jsonObject, "app_name", this->app_name);
		TumblrAPI::setStringFromJson(jsonObject, "display_name", this->display_name);

		if (jsonObject.HasMember("logo")) {
			if (jsonObject["logo"].IsObject()) {
				const rapidjson::GenericObject<true, rapidjson::Value> logoJsonObject = jsonObject["logo"].GetObj();

				std::string urlString;
				TumblrAPI::setStringFromJson(logoJsonObject, "url", urlString);

				Media media = Media(urlString, logoJsonObject);
				this->logo = std::make_shared<Media>(media);
			}
		}
	}

	/**
	 * The canonical URL to the source content in the third-party app.
	 */
	const std::string url;

	/**
	 * The name of the application to be attributed.
	 */
	std::string app_name;

	/**
	 * Any display text that the client should use with the attribution.
	 */
	std::string display_name;

	/**
	 * A specific logo Media Object that the client should use with the third-party app attribution.
	 */
	std::shared_ptr<Media> logo;

};

#endif //TUMBLRAPI_APP_ATTRIBUTION_HPP
