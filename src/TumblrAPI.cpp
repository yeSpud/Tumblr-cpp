//
// Created by Spud on 7/13/21.
//

#include "TumblrAPI.hpp"

cpr::Response TumblrAPI::sendGetRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams) const { // TODO Comments

	// Format the URL to go to for retrieving data.
	std::string url = "https://api.tumblr.com/v2/" + endpoint;

	// If authorization is required add the api token.
	if (authRequired) {
		url += "?api_key=" + this->APIKey;
	}

	// Add any optional parameters to the end of the url.
	url += optionalParams;

	// Send off the get request.
	cpr::Response response;
	response = cpr::Get(cpr::Url{url});

	// Log the returned json.
	TumblrAPI::logger->debug("Returned json: " + response.text);

	// Return the response.
	return response;
}

rapidjson::GenericObject<false, rapidjson::Value> TumblrAPI::parseJsonResponse(const std::string &jsonString) const {

	rapidjson::Document document;
	document.Parse(jsonString.c_str());

	if (document.HasMember("response")) {
		return document["response"].GetObj();
	} else {
		std::string errorString = "Unable to find response object in json '"+ jsonString +"' object";
		TumblrAPI::logger->error(errorString);
		throw std::runtime_error(errorString);
	}
}