//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_AUDIO_POST_HPP
#define TUMBLRAPI_AUDIO_POST_HPP

#include "npf/abstract_post.hpp"
#include "npf/attribution.hpp"

class Audio : Post {

public:

    /**
     * The URL to use for the audio block, if no media is present.
     */
    std::string url;

    // media; FIXME

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

    // poster; FIXME

    /**
     * HTML code that could be used to embed this audio track into a webpage.
     */
    std::string embed_html;

    /**
     * A URL to the embeddable content to use as an iframe.
     */
    std::string embed_url;

    // metadata; FIXME

    Attribution attribution;

};

#endif //TUMBLRAPI_AUDIO_POST_HPP
