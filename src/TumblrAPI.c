//
// Created by Spud on 7/13/21.
//

#include "TumblrAPI.h"

cpr::Response
TumblrAPI::sendGetRequest(const std::string &endpoint, bool APIKeyRequired, const std::string &optionalParams) {

	// Format the URL to go to for retrieving data.
	std::string url = "api.tumblr.com/v2/" + endpoint;

	// If authorization is required add the api token.
	if (APIKeyRequired) {
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

