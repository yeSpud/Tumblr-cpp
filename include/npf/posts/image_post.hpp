//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_IMAGE_POST_HPP
#define TUMBLRAPI_IMAGE_POST_HPP

#include "npf/abstract_post.hpp"
#include "npf/attribution.hpp"

class Image : Post {

public:

    // media; FIXME

    // colors; FIXME

    /**
     * A feedback token to use when this image block is a GIF result.
     */
    std::string feedback_token;

    // poster; FIXME

    /**
     * TODO Documentation
     */
    Attribution attribution;

    /**
     * Text used to describe the image, for screen readers. 4096 character maximum.
     */
    //std::string alt_text;
    char alt_text[4096];

    /**
     * A caption typically shown under the image. 4096 character maximum.
     */
    //std::string caption;
    char caption[4096];

};

#endif //TUMBLRAPI_IMAGE_POST_HPP
