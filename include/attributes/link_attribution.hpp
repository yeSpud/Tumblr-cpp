//
// Created by Spud on 6/20/22.
//

#ifndef TUMBLRAPI_LINK_ATTRIBUTION_HPP
#define TUMBLRAPI_LINK_ATTRIBUTION_HPP

#include "base_attribution.hpp"
#include <string>

class LinkAttribution : public BaseAttribution {

public:

	explicit LinkAttribution(std::string url): BaseAttribution(attributionType::link), url(std::move(url)) {}

	const std::string url;

};

#endif //TUMBLRAPI_LINK_ATTRIBUTION_HPP
