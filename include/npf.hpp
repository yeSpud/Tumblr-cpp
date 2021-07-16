//
// Created by Spud on 7/15/21.
//

#ifndef TUMBLRAPI_NPF_HPP
#define TUMBLRAPI_NPF_HPP

#include "rapidjson/document.h"

#define RAPIDJSON_HAS_STDSTRING 1 // Enable string support.
#define JSONOBJECT rapidjson::GenericObject<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>> // Json Object shortcut

class NPF {

public:

	/**
	 * TODO Documentation
	 * @param entry
	 */
	virtual void populateNPF(JSONOBJECT entry) = 0;

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
static bool objectHasValue(const rapidjson::GenericObject<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>> &object, const char *value, T &buffer) {
	if (object.HasMember(value)) {
		//if (typeid(buffer) == typeid(std::string)) {
		//	buffer = json[value].GetString();
		//} else {
		//buffer = json[value].Get<T>(); // FIXME
		//}
		return true;
	} else {
		return false;
	}
}

#endif //TUMBLRAPI_NPF_HPP
