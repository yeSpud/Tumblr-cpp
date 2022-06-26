//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_ASK_HPP
#define TUMBLRAPI_ASK_HPP

#include "layout.hpp"
#include "rapidjson/document.h"
#include <vector>


class Ask : public Layout {

public:

	explicit Ask(const rapidjson::GenericObject<true, rapidjson::Value>& layoutJsonObject) : Layout(layoutType::ask) {

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

		// TODO Attribution

	};

	/**
	 * This is an array of block indices that are a part of the ask content of the Post.
	 */
	std::vector<std::vector<int>> blocks;

	/**
	 * If the ask is not anonymous, this will include information about the blog that submitted the ask.
	 */
	//Attribution attribution; // FIXME Blog attribute

};

#endif //TUMBLRAPI_ASK_HPP
