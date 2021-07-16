//
// Created by Spud on 7/15/21.
//

#ifndef TUMBLRAPI_NPF_HPP
#define TUMBLRAPI_NPF_HPP

#include <string>
#include "rapidjson/document.h"

/**
 * Json Object shortcut because I'm lazy
 */
#define JSON_OBJECT rapidjson::GenericObject<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>>

class NPF {

public:

	/**
	 * TODO Documentation
	 * @param entry
	 */
	virtual void populateNPF(JSON_OBJECT entry) = 0;

};

/**
 * TODO Documentation & comments
 * @tparam T
 * @param json
 * @param value
 * @param buffer
 * @return
 */
template<typename T>
static bool objectHasValue(const JSON_OBJECT &object, const char *value, T &buffer) {
	if (object.HasMember(value)) {
		buffer = object[value].Get<T>();
		return true;
	} else {
		return false;
	}
}

/**
 * TODO Documentation
 * @param object
 * @param value
 * @param buffer
 * @return
 */
static bool objectHasValue(const JSON_OBJECT &object, const char *value, std::string &buffer) {
	if (object.HasMember(value)) {
		const char* tempstr = object[value].GetString();
		buffer = std::string(tempstr);
		return true;
	} else {
		return false;
	}
}

/**
 * TOOD Documentation
 * @param constObject
 * @return
 */
static JSON_OBJECT unConstlifyJsonObject(const rapidjson::GenericObject<true, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>> &constObject) {
	// TODO
}

#endif //TUMBLRAPI_NPF_HPP
