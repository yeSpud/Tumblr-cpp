//
// Created by Spud on 7/15/21.
//

#ifndef TUMBLRAPI_NPF_HPP
#define TUMBLRAPI_NPF_HPP

#include <string>
#include <vector>
#include "rapidjson/document.h"
//#include "rapidjson/writer.h"

/*
 * Json Object shortcuts because I'm lazy
 */
#define JSON_OBJECT rapidjson::GenericObject<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>>
#define JSON_ARRAY rapidjson::GenericArray<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>>
#define JSON_ARRAY_ENTRY rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>

// TODO Turn into function
#define POPULATE_SUBGROUP(entry, value, code) if (entry.HasMember(value)) {\
if (entry[value].IsObject()) {\
code\
}} //else if (entry[value].IsArray()) {\
//POPULATE_SUBGROUP(entry[value].GetArray()[0], value, code)\
//}\
//}

class NPF {

public:

	/**
	 * TODO Documentation
	 * @param entry
	 */
	virtual void populateNPF(JSON_OBJECT entry) = 0;

};

/* Experimenting with lambdas to help populate objects with json array or nested objects
static void populateSubgroup(JSON_OBJECT entry, const char *value, std::function<void()> function) {

	if (entry.HasMember(value)) {
		if (entry[value].IsArray()) {
			for (auto& arrayEntry : entry[value].GetArray()) {
				if (arrayEntry.IsObject()) {
					function;
				}
			}
		} else if (entry[value].IsObject()) {
			function;
		}
	}
}
 */

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

/*
 * TODO Documentation & comments
 * @param json
 * @return
 */
/*
static const char* jsonToString(const rapidjson::Document &json) {
   rapidjson::StringBuffer stringBuffer;
   rapidjson::Writer<rapidjson::StringBuffer> writer(stringBuffer);
   json.Accept(writer);
   return stringBuffer.GetString();
}
 */

#endif //TUMBLRAPI_NPF_HPP
