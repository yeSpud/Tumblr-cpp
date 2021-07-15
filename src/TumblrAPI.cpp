//
// Created by Spud on 7/13/21.
//

#include "TumblrAPI.hpp"

cpr::Response
TumblrAPI::sendGetRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams) { // TODO Comments

	// Format the URL to go to for retrieving data.
	std::string url = "api.tumblr.com/v2/" + endpoint;
	if (authRequired) {
		url += "?api_key=" + token;
	}
	url += optionalParams;

	cpr::Response response;
	response = cpr::Get(cpr::Url{url});

	return response;
}

