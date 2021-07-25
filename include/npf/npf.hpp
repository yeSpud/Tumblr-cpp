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

#define POPULATE_OBJECT(entry, value, code) if (entry.HasMember(value)) {if (entry[value].IsObject()) {code}}
#define POPULATE_ARRAY(entry, value, code) if (entry.HasMember(value)) {if (entry[value].IsArray()) {code}}

#define DELETE_NPF(NPF) if (NPF != nullptr) { delete NPF; NPF = nullptr; }

class NPF {

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
 * TODO Documentation & comments
 * @param object
 * @param value
 * @param buffer
 * @return
 */
static bool objectHasValue(const JSON_OBJECT &object, const char *value, std::string &buffer) {
	if (object.HasMember(value)) {
		const char *str = object[value].GetString();
		buffer = std::string(str);
		return true;
	}
	return false;
}

/**
 * TODO Documentation & comments
 * @tparam T
 * @param object
 * @param value
 * @param bufferVector
 * @return
 */
template<typename T>
static bool populateVectorObject(const JSON_OBJECT &object, const char *value, std::vector<T> &bufferVector) {
	if (object.HasMember(value)) {
		if (object[value].IsArray()) {
			for (JSON_ARRAY_ENTRY &objectEntry : object[value].GetArray()) {
				if (objectEntry.IsObject()) {
					T entry;
					entry.populateNPF(objectEntry.GetObj());
					bufferVector.push_back(entry);
				}
			}
			return true;
		} else if (object[value].IsObject()) {
			T entry;
			entry.populateNPF(object[value].GetObj());
			bufferVector.push_back(entry);
			return true;
		}
	}

	return false;

}

#endif //TUMBLRAPI_NPF_HPP
