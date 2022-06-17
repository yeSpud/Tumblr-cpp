//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_VIDEO_POST_HPP
#define TUMBLRAPI_VIDEO_POST_HPP

#include "npf/abstract_post.hpp"
#include "npf/attribution.hpp"

class Video : Post {

public:

    /**
     * The URL to use for the video block, if no media is present.
     */
    std::string url;

    // media; FIXME

    /**
     * The provider of the video, whether it's tumblr for native video or a trusted third party.
     */
    std::string provider;

    /**
     * HTML code that could be used to embed this video into a webpage.
     */
    std::string embed_html;

    // iframe; FIXME

    /**
     * A URL to the embeddable content to use as an iframe.
     */
    std::string embed_url;

    // poster; FIXME

    // metadata; FIXME

    Attribution attribution;

    bool can_autoplay_on_cellular = false;

};

#endif //TUMBLRAPI_VIDEO_POST_HPP
