//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_VIDEO_HPP
#define TUMBLRAPI_VIDEO_HPP

#include "rapidjson/document.h"

class video {

public:

	/**
	 * TODO Documentation
	 */
	struct Video;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Video generateVideo(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_VIDEO_HPP
