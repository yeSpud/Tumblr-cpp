//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_IMAGE_POST_HPP
#define TUMBLRAPI_IMAGE_POST_HPP

#include "npf/abstract_post.hpp"
#include "npf/media.hpp"

class Image : public Post {

public:

	Image(const rapidjson::Value &postJsonArrayEntry, const rapidjson::Value &contentArrayEntry): Post(Post::postType::photo, postJsonArrayEntry) {

		const rapidjson::Value* mediaValuePointer = TumblrAPI::setValueFromJson(contentArrayEntry, "media");
		if (mediaValuePointer != nullptr) {
			if (mediaValuePointer->IsArray()) {
				for (const rapidjson::Value &mediaArrayEntry: mediaValuePointer->GetArray()) {
					std::string mediaUrl;
					TumblrAPI::setStringFromJson(mediaArrayEntry, "url", mediaUrl);
					Media mediaObject = Media(mediaUrl, mediaArrayEntry);
					this->media.push_back(mediaObject);
				}
			}
		}

		// TODO Colors

		TumblrAPI::setStringFromJson(contentArrayEntry, "feedback_token", this->feedback_token);

		// TODO Image poster

		// TODO Image attribution

		std::string altTextInput;
		TumblrAPI::setStringFromJson(contentArrayEntry, "alt_text", altTextInput);
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
		TumblrAPI::setStringFromJson(contentArrayEntry, "caption", captionInput);
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

    // poster; FIXME

    /*
     * TODO Documentation
     */
    //Attribution attribution; FIXME

    /**
     * Text used to describe the image, for screen readers. 4096 character maximum.
     */
    //std::string alt_text;
    char alt_text[4097];

    /**
     * A caption typically shown under the image. 4096 character maximum.
     */
    //std::string caption;
    char caption[4097];

};

#endif //TUMBLRAPI_IMAGE_POST_HPP
