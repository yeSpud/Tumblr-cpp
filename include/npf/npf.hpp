//
// Created by Spud on 7/15/21.
//

#ifndef TUMBLRAPI_NPF_HPP
#define TUMBLRAPI_NPF_HPP

#include <string>
#include <vector>
#include "rapidjson/document.h"

/*
 * Json shortcuts because I'm lazy
 */
#define JSON_OBJECT rapidjson::GenericObject<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>>
#define JSON_ARRAY rapidjson::GenericArray<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>>
#define JSON_ARRAY_ENTRY rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>

#define POPULATE_ARRAY(entry, value, code) if (entry.HasMember(value)) {if (entry[value].IsArray()) {code}}

class [[deprecated("To be removed")]] NPF {

public:

	/**
	 * TODO Documentation
	 */
	virtual ~NPF() = default;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	virtual void populateNPF(JSON_OBJECT entry) = 0;

};

/**
 * TODO Documentation & comments
 * @param object
 * @param value
 * @param buffer
 * @return
 */
static bool objectHasValue(const JSON_OBJECT &object, const char *value, int &buffer) {
	if (object.HasMember(value)) {
		if (object[value].GetType() == rapidjson::kNumberType) {
			buffer = object[value].GetInt();
			return true;
		}
	}

	return false;
}

#endif //TUMBLRAPI_NPF_HPP
