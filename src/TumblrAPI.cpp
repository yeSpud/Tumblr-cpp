//
// Created by Spud on 7/13/21.
//

#include "TumblrAPI.hpp"

cpr::Response
TumblrAPI::sendGetRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams) { // TODO Comments

	// Format the URL to go to for retrieving data.
	std::string url = "api.tumblr.com/v2/" + endpoint;

	// If authorization is required add the api token.
	if (authRequired) {
		url += "?api_key=" + APIKey;
	}

	// Add any optional parameters to the end of the url.
	url += optionalParams;

	// Send off the get request.
	cpr::Response response;
	response = cpr::Get(cpr::Url{url});

	// Return the response.
	return response;
}

