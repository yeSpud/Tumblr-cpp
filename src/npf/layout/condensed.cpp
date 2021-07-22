//
// Created by Spud on 7/16/21.
//

#include "npf/layout/condensed.hpp"

void Condensed::populateBlocks(const JSON_ARRAY &array) { // TODO Comments
	blocks = std::vector<int>(array.Size());
	for (JSON_ARRAY_ENTRY &entry : array) {
		if (entry.IsInt()) {
			blocks.push_back(entry.GetInt());
		}
	}
}

void Condensed::populateNPF(JSON_OBJECT entry) { // TODO Comments

	POPULATE_ARRAY(entry, "blocks", populateBlocks(entry["blocks"].GetArray());)

	objectHasValue(entry, "truncate_after", truncate_after);

}
