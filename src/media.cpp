//
// Created by Spud on 7/14/21.
//

#include "media.hpp"

/*
{
	"url": "https://69.media.tumblr.com/path/to/image.jpg",
	"type": "image/jpg",
	"width": 540,
	"height": 405
}
 */

/*
{
	"type": "image/gif",
	"url": "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.gif",
	"width": 500,
	"height": 400,
	"poster": {
		"type": "image/jpeg",
		"url": "https://69.media.tumblr.com/b06fe71cc4ab47e93749df060ff54a90/tumblr_nshp8oVOnV1rg0s9xo1_500.jpg",
		"width": 500,
		"height": 400
	}
}
 */

void Media::populateNPF(JSONOBJECT entry) { // TODO Comments

	//rapidjson::GenericObject<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>> object = entry.GetObj();
	objectHasValue(entry, "type", type);
	objectHasValue(entry, "url", url);
	objectHasValue(entry, "width", width);
	objectHasValue(entry, "height", height);
	objectHasValue(entry, "original_dimensions_missing", original_dimensions_missing);
	objectHasValue(entry, "cropped", cropped);
	objectHasValue(entry, "has_original_dimensions", has_original_dimensions);

}
