//
// Created by Spud on 7/14/21.
//

#include "blog.hpp"

std::string Blog::getAvatar(unsigned short int size) {

	// Make sure the sizes are valid.
	if (size == 16 || size == 24 || size == 30 || size == 40 || size == 48 || size == 64 || size == 96 || size == 128 || size == 512) {

		cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/avatar/",
		                                                  false, std::to_string(size));

		if (response.status_code == 200 || response.status_code == 301 || response.status_code == 302 || response.status_code == 307 || response.status_code == 308) {
			return response.url.str();
			/*
			JSON_OBJECT jsonResponse = this->api.parseJsonResponse(response.text);
			const char* jsonKey = "avatar_url";
			if (jsonResponse.HasMember(jsonKey)) {
				if (jsonResponse[jsonKey].IsString()) {
					return jsonResponse[jsonKey].GetString();
				}
			}

			// At this point since we missed the primary return throw an error.
			std::string errorString = "Unable to find avatar url parameter in returned json";
			this->api.logger->error(errorString);
			throw std::runtime_error(errorString);*/
		} else {
			std::string errorString = "Response from API returned an error: " + response.error.message + "\n" + response.reason;
			this->api.logger->error(errorString);
			throw std::runtime_error(errorString);
		}
	} else {

		// Throw an error since the size is invalid.
		std::string errorString = "Size provided is not valid size: " + std::to_string(size);
		this->api.logger->error(errorString);
		throw std::invalid_argument(errorString);
	}
};

Blog::blogLikes Blog::getLikes(unsigned short int limit, unsigned short int offset, long long before, long long after) {

	// Make sure limit and offset are valid.
	if (limit >= 1 && limit <= 20) {
		short int offsetMath = limit - offset;
		if (offsetMath > 0 && offset <= 20) {

			cpr::Response response = this->api.sendGetRequest("blog/" + this->blogIdentifier + "/likes", true); // TODO Implement options
			if (response.status_code == 200 || response.status_code == 301 || response.status_code == 302 || response.status_code == 307 || response.status_code == 308) {
				JSON_OBJECT jsonResponse = this->api.parseJsonResponse(response.text);
			}
		}
	}
}