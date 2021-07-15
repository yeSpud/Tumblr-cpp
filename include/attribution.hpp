//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_ATTRIBUTION_HPP
#define TUMBLRAPI_ATTRIBUTION_HPP

class attribution {

public:

	/**
	 * TODO Documentation
	 */
	enum attributionType {
		link, blog, post, app
	};

	/**
	 * TODO Documentation
	 */
	struct Attribution;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Attribution generateAttribution(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_ATTRIBUTION_HPP
