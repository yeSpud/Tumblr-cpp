//
// Created by Spud on 7/16/21.
//

#include "npf/layout/rows.hpp"

void Rows::populateBlocks(const JSON_ARRAY &array) { // TODO Comments

	display = std::vector<std::vector<int>>(array.Size());

	for (JSON_ARRAY_ENTRY &entry : array) {
		if (entry.IsObject()) {
			JSON_OBJECT object = entry.GetObj();
			/*
			if (object.HasMember("blocks")) {
				if (object["blocks"].IsArray()) {
					JSON_ARRAY intArray = object["blocks"].GetArray();
					std::vector<int> block = std::vector<int>(intArray.Size());
					for (JSON_ARRAY_ENTRY &blockEntry : intArray) {
						if (blockEntry.IsInt()) {
							block.push_back(blockEntry.GetInt());
						}
					}
					display.push_back(block);
				}
			}
			 */
			POPULATE_ARRAY(object, "blocks", JSON_ARRAY intArray = object["blocks"].GetArray();
					std::vector<int> block = std::vector<int>(intArray.Size());
					for (JSON_ARRAY_ENTRY &blockEntry : intArray) {
						if (blockEntry.IsInt()) {
							block.push_back(blockEntry.GetInt());
						}
					}
					display.push_back(block);)
		}
	}

}

void Rows::populateNPF(JSON_OBJECT entry) { // TODO Comments

	/*
	if (entry.HasMember("display")) {
		if (entry["display"].IsArray()) {
			populateBlocks(entry["display"].GetArray());
		}
	}
	 */
	POPULATE_ARRAY(entry, "display", populateBlocks(entry["display"].GetArray());)

	// TODO Mode (when implemented)

}
