//
// Created by Spud on 6/17/22.
//

#ifndef TUMBLRAPI_LINK_POSTS_HPP
#define TUMBLRAPI_LINK_POSTS_HPP

#include "content.hpp"
#include <string>

class Link : public Content {

public:

    /**
     * The URL to use for the link block.
     */
    std::string url;

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

    // poster; FIXME

};

#endif //TUMBLRAPI_LINK_POSTS_HPP
