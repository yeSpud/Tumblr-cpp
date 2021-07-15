//
// Created by Spud on 7/13/21.
//

#include "Content.hpp"

// TODO Convert the bottom 3 into 1 with templating?
bool Content::entryHasString(const rapidjson::Value &entry, const char *value, std::string &buffer) { // TODO Comments
	if (entry.HasMember(value)) {
		buffer = entry[value].GetString();
		return true;
	} else {
		return false;
	}
}

bool Content::entryHasNumber(const rapidjson::Value &entry, const char *value, uint64_t &buffer) { // TODO Comments
	if (entry.HasMember(value)) {
		buffer = entry[value].GetUint();
		return true;
	} else {
		return false;
	}
}

bool Content::entryHasBool(const rapidjson::Value &entry, const char *value, bool &buffer) { // TODO Comments
	if (entry.HasMember(value)) {
		buffer = entry[value].GetBool();
		return true;
	} else {
		return false;
	}
}
