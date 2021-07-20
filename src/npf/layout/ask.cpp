//
// Created by Spud on 7/16/21.
//

#include "npf/layout/ask.hpp"

void Ask::populateBlocks(const JSON_ARRAY &array) { // TODO Comments
	blocks = std::vector<int>(array.Size());
	for (JSON_ARRAY_ENTRY &entry : array) {
		if (entry.IsInt()) {
			blocks.push_back(entry.GetInt());
		}
	}
}

void Ask::populateNPF(JSON_OBJECT entry) { // TODO Comments

	/*
	if (entry.HasMember("blocks")) {
		if (entry["blocks"].IsArray()) {
			populateBlocks(entry["blocks"].GetArray());
		}
	}
	 */
	POPULATE_ARRAY(entry, "blocks", populateBlocks(entry["blocks"].GetArray());)

	POPULATE_OBJECT(entry, "attribution",
	                Attribution attr; attr.populateNPF(entry["attribution"].GetObj()); attribution = attr;)

}
