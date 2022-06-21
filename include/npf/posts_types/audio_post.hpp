//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_AUDIO_POST_HPP
#define TUMBLRAPI_AUDIO_POST_HPP

#include "content.hpp"
#include "npf/media.hpp"

class Audio : public Content {

public:

	explicit Audio(const rapidjson::Value &contentJson): Content(postType::audio) {

		TumblrAPI::setStringFromJson(contentJson, "url", this->url);

		// Media.
		Media::setMediaPointer(contentJson, this->media);

		TumblrAPI::setStringFromJson(contentJson, "provider", this->provider);
		TumblrAPI::setStringFromJson(contentJson, "title", this->title);
		TumblrAPI::setStringFromJson(contentJson, "artist", this->artist);
		TumblrAPI::setStringFromJson(contentJson, "album", this->album);

		// Poster.
		Media::setPosterPointer(contentJson, this->poster);

		TumblrAPI::setStringFromJson(contentJson, "embed_html", this->embed_html);
		TumblrAPI::setStringFromJson(contentJson, "embed_url", this->embed_url);

		// TODO Metadata

		// FIXME Attribution
	}

    /**
     * The URL to use for the audio block, if no media is present.
     */
    std::string url;

	/**
	 * The Media Object to use for the audio block, if no url is present.
	 */
    std::shared_ptr<Media> media;

    /**
     * The provider of the audio source, whether it's tumblr or native audio or a trusted third party.
     */
    std::string provider;

    /**
     * The title of the audio asset.
     */
    std::string title;

    /**
     * The artist of the audio asset.
     */
    std::string artist;

    /**
     * The album from which the audio asset originated.
     */
    std::string album;

	/**
	 * An image media object to use as a "poster" for the audio track, usually album art.
	 */
    std::shared_ptr<Media> poster;

    /**
     * HTML code that could be used to embed this audio track into a webpage.
     */
    std::string embed_html;

    /**
     * A URL to the embeddable content to use as an iframe.
     */
    std::string embed_url;

    // metadata; FIXME

	/*
	 * TODO Documentation
	 */
    // Attribution attribution;

};

#endif //TUMBLRAPI_AUDIO_POST_HPP
