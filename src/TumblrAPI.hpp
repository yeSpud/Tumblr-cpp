//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_TUMBLRAPI_HPP
#define TUMBLRAPI_TUMBLRAPI_HPP

#inclide "cpr/cpr.h"

class TumblrAPI {

private:

	/**
	 * TODO Documentation
	 */
	const std::string token;

	/**
	 * TODO Documentation
	 * @param endpoint
	 * @param authRequired
	 * @param optionalParams
	 * @return
	 */
	cpr::Response sendRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams = "");

public:

	/**
	 * TODO Documentation
	 */
	struct Blog {

		// TODO

	};

	/**
	 * TODO Documentation
	 */
	struct Post {

		// TODO

	};

};


#endif //TUMBLRAPI_TUMBLRAPI_HPP
