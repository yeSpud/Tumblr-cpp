//
// Created by Spud on 7/16/21.
//

#include "npf/layout/carousel.hpp"

void Carousel::populateNPF(JSON_OBJECT entry) { // TODO Comments

	Rows::populateNPF(entry);

	objectHasValue(entry, "truncate_after", truncate_after);

}
