//
// Created by Spud on 7/15/21.
//

#ifndef TUMBLRAPI_NPF_HPP
#define TUMBLRAPI_NPF_HPP

#define RAPIDJSON_HAS_STDSTRING 1 // Enable string support.
#include "rapidjson/document.h"

class NPF {

public:

	/**
	 * TODO Document
	 * @tparam T
	 * @param entry
	 * @return
	 */
	//template<typename T>
	//virtual T generateNPF(const rapidjson::Value &entry) const = 0;

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
static bool entryHasValue(const rapidjson::Value &json, const char *value, T &buffer) {
	if (json.HasMember(value)) {
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
