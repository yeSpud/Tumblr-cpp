//
// Created by Spud on 7/15/21.
//

#include "npf/content/iframe.hpp"

void iFrame::populateNPF(JSON_OBJECT entry) { // TODO Comments

	objectHasValue(entry, "url", url);
	objectHasValue(entry, "width", width);
	objectHasValue(entry, "height", height);

}
