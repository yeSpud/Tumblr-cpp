//
// Created by Spud on 7/15/21.
//

#ifndef TUMBLRAPI_IFRAME_HPP
#define TUMBLRAPI_IFRAME_HPP

#include "npf/content/content.hpp"

/**
 * TODO Documentation
 */
class iFrame: Content {

public:

	iFrame() = default;;

	/**
	 * A URL used for constructing and embeddable video iframe.
	 */
	std::string url;

	/**
	 * The width of the video iframe. Default is 540.
	 */
	int width = 540;

	/**
	 * The height of the video iframe. Default is 405.
	 */
	int height = 405;

	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_IFRAME_HPP
