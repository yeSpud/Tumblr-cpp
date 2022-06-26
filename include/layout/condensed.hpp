//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_CONDENSED_HPP
#define TUMBLRAPI_CONDENSED_HPP

#include "layout.hpp"
#include "TumblrAPI.hpp"

/**
 * The condensed layout is deprecated and replaced by the truncate_after property in the rows layout.
 * Please use the rows layout to get or set a recommended truncation index. If a post is created with a condensed layout,
 * it will be ignored by the backend. In other words, a read-more will not show up in the post.
 */
class [[deprecated("The condensed layout is deprecated and replaced by the truncate_after property in the rows layout. "
"Please use the rows layout to get or set a recommended truncation index.")]] Condensed : public Layout {

public:

	explicit Condensed(const rapidjson::GenericObject<true, rapidjson::Value> &layoutJsonObject) : Layout(layoutType::condensed) {

		if (layoutJsonObject.HasMember("blocks")) {
			if (layoutJsonObject["blocks"].IsArray()) {
				std::vector<int> blockVector;
				rapidjson::GenericArray blockJsonArray = layoutJsonObject["blocks"].GetArray();

				for (const rapidjson::Value &blockEntry : blockJsonArray) {
					if (blockEntry.IsInt()) {
						blockVector.push_back(blockEntry.GetInt());
					}
				}

				this->blocks.push_back(blockVector);
			}
		}

		TumblrAPI::setIntFromJson(layoutJsonObject, "truncate_after", this->truncate_after);

	};

	/**
	 * This is an array of block indices that are a part of the truncated version of the Post.
	 * Required if truncate_after is not supplied. Must be sequential, not empty, and begin with 0.
	 */
	std::vector<std::vector<int>> blocks;

	/**
	 * The last block to display before the Read More signifier. Required if blocks is not supplied.
	 */
	int truncate_after = 0;

};

#endif //TUMBLRAPI_CONDENSED_HPP
