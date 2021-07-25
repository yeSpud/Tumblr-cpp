//
// Created by Spud on 7/14/21.
//

#include "npf/content/text.hpp"

void Text::populateNPF(JSON_OBJECT entry) { // TODO Comments

	objectHasValue(entry, "text", text);

	// Subtype
	std::string subString;
	objectHasValue(entry, "subtype", subString);
	if (subString == "heading1") {
		subtype = heading1;
	} else if (subString == "heading2") {
		subtype = heading2;
	} else if (subString == "quirky") {
		subtype = quirky;
	} else if (subString == "quote") {
		subtype = quote;
	} else if (subString == "indented") {
		subtype = indented;
	} else if (subString == "chat") {
		subtype = chat;
	} else if (subString == "ordered_list_item") {
		subtype = ordered_list_item;
	} else if (subString == "unordered_list_item") {
		subtype = unordered_list_item;
	}

	objectHasValue(entry, "text", indent_level);

	// Formatting
	populateVectorObject(entry, "formatting", formatting);

}
