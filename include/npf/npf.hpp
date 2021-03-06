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
 * @param object
 * @param value
 * @param buffer
 * @return
 */
static bool objectHasValue(const JSON_OBJECT &object, const char *value, bool &buffer) {
	if (object.HasMember(value)) {
		if (object[value].GetType() == rapidjson::kTrueType || object[value].GetType() == rapidjson::kTrueType) {
			buffer = object[value].GetBool();
			return true;
		}
	}

	return false;
}

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

/**
 * TODO Documentation & comments
 * @param object
 * @param value
 * @param buffer
 * @return
 */
static bool objectHasValue(const JSON_OBJECT &object, const char *value, unsigned long long &buffer) {
	if (object.HasMember(value)) {
		if (object[value].GetType() == rapidjson::kNumberType) {
			buffer = object[value].GetUint64();
			return true;
		}
	}

	return false;
}

/**
 * TODO Documentation & comments
 * @param object
 * @param value
 * @param buffer
 * @return
 */
static bool objectHasValue(const JSON_OBJECT &object, const char *value, unsigned int &buffer) {
	if (object.HasMember(value)) {
		if (object[value].GetType() == rapidjson::kNumberType) {
			buffer = object[value].GetUint();
			return true;
		}
	}

	return false;
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
		if (object[value].GetType() == rapidjson::kStringType) {
			const char *str = object[value].GetString();
			buffer = std::string(str);
			return true;
		}
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

/**
 * TODO Documentation & comments
 * @tparam E
 * @param inputString
 * @param strings
 * @param enums
 * @param defaultEnum
 * @return
 */
template <typename E>
static E stringToEnum(const std::string& inputString, const std::vector<std::string>& strings, const std::vector<E>& enums,
					  const E &defaultEnum) {
	for (int i = 0; i < strings.size(); i++) {
		if (inputString == strings[i]) {
			return enums[i];
		}
	}

	return defaultEnum;
}

#endif //TUMBLRAPI_NPF_HPP
