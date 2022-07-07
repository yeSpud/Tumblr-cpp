//
// Created by Spud on 7/13/21.
//

#include "TumblrAPI.hpp"
#include <rapidjson/writer.h>
#include <iostream>

void TumblrAPI::printJson(const rapidjson::Value& json) {

	rapidjson::StringBuffer stringBuffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(stringBuffer);
	json.Accept(writer);

	std::cout << "Json: " << stringBuffer.GetString() << std::endl;
}

const rapidjson::Value* TumblrAPI::getValuePointerFromJson(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject, const char *key) {
	if (jsonObject.HasMember(key)) {
		return &jsonObject[key];
	} else {
		TUMBLR_LOGGER->warn("JsonObject is missing value for key {}", key);
		return nullptr;
	}
}

void TumblrAPI::setStringFromJson(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject, const char *key, std::string &stringBuffer) {
	const rapidjson::Value* jsonObjectValuePointer = TumblrAPI::getValuePointerFromJson(jsonObject, key);
	if (jsonObjectValuePointer != nullptr) {
		if (jsonObjectValuePointer->IsString()) {
			stringBuffer = jsonObjectValuePointer->GetString();
		} else {
			TUMBLR_LOGGER->warn("JsonObject has value for key {}, but that value is not a string!", key);
		}
	}
}

void TumblrAPI::setBooleanFromJson(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject, const char *key, bool &booleanBuffer) {
	const rapidjson::Value* jsonObjectValuePointer = TumblrAPI::getValuePointerFromJson(jsonObject, key);
	if (jsonObjectValuePointer != nullptr) {
		if (jsonObjectValuePointer->IsBool()) {
			booleanBuffer = jsonObjectValuePointer->GetBool();
		} else {
			TUMBLR_LOGGER->warn("JsonObject has value for key {}, but that value is not a boolean!", key);
		}
	}
}

void TumblrAPI::setUIntFromJson(const rapidjson::GenericObject<true, rapidjson::Value> &jsonObject, const char *key, unsigned int &uIntBuffer) {
	const rapidjson::Value* jsonValuePointer = TumblrAPI::getValuePointerFromJson(jsonObject, key);
	if (jsonValuePointer != nullptr) {
		if (jsonValuePointer->IsUint()) {
			uIntBuffer = jsonValuePointer->GetUint();
		} else {
			TUMBLR_LOGGER->warn("JsonObject has valye for key {}, but that value is not an unsigned int!", key);
		}
	}
}

void TumblrAPI::setIntFromJson(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject, const char *key, int &intBuffer) {
	const rapidjson::Value* jsonObjectValuePointer = TumblrAPI::getValuePointerFromJson(jsonObject, key);
	if (jsonObjectValuePointer != nullptr) {
		if (jsonObjectValuePointer->IsInt()) {
			intBuffer = jsonObjectValuePointer->GetInt();
		} else {
			TUMBLR_LOGGER->warn("JsonObject has value for key {}, but that value is not an int!", key);
		}
	}
}

void TumblrAPI::setUInt64FromJson(const rapidjson::GenericObject<true, rapidjson::Value>& jsonObject, const char *key, unsigned long long &numberBuffer) {
	const rapidjson::Value* jsonObjectValuePointer = TumblrAPI::getValuePointerFromJson(jsonObject, key);
	if (jsonObjectValuePointer != nullptr) {
		if (jsonObjectValuePointer->IsUint64()) {
			numberBuffer = jsonObjectValuePointer->GetUint64();
		} else {
			TUMBLR_LOGGER->warn("JsonObject has value for key {}, but that value is not an unsigned 64-bit int!", key);
		}
	}
}

void TumblrAPI::setInt64FromJson(const rapidjson::GenericObject<true, rapidjson::Value> &jsonObject, const char *key, long long &int64Buffer) {
	const rapidjson::Value* jsonValuePointer = TumblrAPI::getValuePointerFromJson(jsonObject, key);
	if (jsonValuePointer != nullptr) {
		if (jsonValuePointer->IsInt64()) {
			int64Buffer = jsonValuePointer->GetInt64();
		} else {
			TUMBLR_LOGGER->warn("JsonObject has value for key {}, but that value is not a 64-bit int!", key);
		}
	}
}

cpr::Response TumblrAPI::sendGetRequest(const std::string &endpoint, bool authRequired, const std::string &optionalParams) const {

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
	this->logger->debug("Returned json: " + response.text);

	// Return the response.
	return response;
}

rapidjson::GenericObject<true, rapidjson::Value> TumblrAPI::parseJsonResponse(const std::string &jsonString) const {

	rapidjson::Document document;
	document.Parse(jsonString.c_str());

	if (document.HasMember("response")) {
		const rapidjson::Value& responseValue = document["response"];

		if (responseValue.IsObject()) {
			return responseValue.GetObj();
		} else {
			std::string errorString = "Response is not a json object!";
			this->logger->error(errorString);
			throw std::runtime_error(errorString);
		}
	} else {
		std::string errorString = "Unable to find response object in json '"+ jsonString +"' object";
		this->logger->error(errorString);
		throw std::runtime_error(errorString);
	}
}

bool TumblrAPI::responseOk(long responseCode) {

	const std::vector<long> okCodes = {200, 301, 302, 307, 308};

	return std::binary_search(okCodes.begin(), okCodes.end(), responseCode);
}
