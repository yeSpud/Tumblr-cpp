//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_IMAGE_POST_HPP
#define TUMBLRAPI_IMAGE_POST_HPP

#include "media.hpp"
#include "content.hpp"
#include "attributes/base_attribution.hpp"

class Image : public Content {

private:

	/**
	 * TODO Documentation
	 * @param mediaJsonObject
	 */
	void setPoster(const rapidjson::GenericObject<true, rapidjson::Value>& mediaJsonObject);

public:

	explicit Image(const rapidjson::GenericObject<true, rapidjson::Value>& contentEntryJson): Content(postType::photo) {

		const rapidjson::Value* mediaValuePointer = TumblrAPI::getValuePointerFromJson(contentEntryJson, "media");
		if (mediaValuePointer != nullptr) {
			if (mediaValuePointer->IsArray()) {
				for (const rapidjson::Value &mediaArrayEntry: mediaValuePointer->GetArray()) {
					if (mediaArrayEntry.IsObject()) {
						rapidjson::GenericObject mediaJsonObject = mediaArrayEntry.GetObj();

						std::string mediaUrl;
						TumblrAPI::setStringFromJson(mediaJsonObject, "url", mediaUrl);
						Media mediaObject = Media(mediaUrl, mediaJsonObject);
						this->media.push_back(mediaObject);

						// Sometimes the poster is in the media object.
						this->setPoster(mediaJsonObject);
					}
				}
			}
		}

		// TODO Colors

		TumblrAPI::setStringFromJson(contentEntryJson, "feedback_token", this->feedback_token);

		// Image poster.
		this->setPoster(contentEntryJson);

		// Image attribution
		if (contentEntryJson.HasMember("attribution")) {
			if (contentEntryJson["attribution"].IsObject()) {
				this->attribution = BaseAttribution::getAttribution(contentEntryJson["attribution"].GetObj());
			}
		}

		std::string altTextInput;
		TumblrAPI::setStringFromJson(contentEntryJson, "alt_text", altTextInput);
		int altTextInputIndex = 0;
		for (char c : altTextInput) {
			this->alt_text[altTextInputIndex] = c;

			altTextInputIndex++;
			if (altTextInputIndex >= 4096) {
				break;
			}
		}

		// We set the last known character to null as well as the final character in the array to null to signal the end of the string is either before or at the 4096th place.
		this->alt_text[altTextInputIndex] = '\0';
		this->alt_text[4096] = '\0';

		std::string captionInput;
		TumblrAPI::setStringFromJson(contentEntryJson, "caption", captionInput);
		int captionInputIndex = 0;
		for (char c : captionInput) {
			this->caption[captionInputIndex] = c;

			captionInputIndex++;
			if (captionInputIndex >= 4096) {
				break;
			}
		}
		this->caption[captionInputIndex] = '\0';
		this->caption[4096] = '\0';
	};

    std::vector<Media> media;

    // colors; FIXME

    /**
     * A feedback token to use when this image block is a GIF result.
     */
    std::string feedback_token;

	/**
	 * For GIFs, this is a single-frame "poster".
	 */
    std::shared_ptr<Media> poster;

    /**
     * In the case of GIF search results and individual images with a content source,
     * the content block may include an attribution object with more fields for those cases.
     */
    std::shared_ptr<BaseAttribution> attribution;

    /**
     * Text used to describe the image, for screen readers. 4096 character maximum.
     */
    //std::string alt_text;
    char alt_text[4097] {};

    /**
     * A caption typically shown under the image. 4096 character maximum.
     */
    //std::string caption;
    char caption[4097] {};

};

#endif //TUMBLRAPI_IMAGE_POST_HPP
