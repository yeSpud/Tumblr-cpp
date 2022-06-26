//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_ROWS_HPP
#define TUMBLRAPI_ROWS_HPP

#include "layout.hpp"
#include "TumblrAPI.hpp"

class Rows : public Layout {

public:

	explicit Rows(const rapidjson::GenericObject<true, rapidjson::Value> &layoutJsonObject) : Layout(layoutType::rows) {

		if (layoutJsonObject.HasMember("display")) {
			if (layoutJsonObject["display"].IsArray()) {
				rapidjson::GenericArray displayJsonArray = layoutJsonObject["display"].GetArray();

				for (const rapidjson::Value &displayEntry : displayJsonArray) {
					if (displayEntry.IsObject()) {

						rapidjson::GenericObject displayEntryObject = displayEntry.GetObj();
						if (displayEntryObject.HasMember("blocks")) {
							if (displayEntryObject["blocks"].IsArray()) {
								std::vector<int> blockVector;
								rapidjson::GenericArray blockJsonArray = displayEntryObject["blocks"].GetArray();

								for (const rapidjson::Value &blockEntry : blockJsonArray) {
									if (blockEntry.IsInt()) {
										blockVector.push_back(blockEntry.GetInt());
									}
								}

								this->blocks.push_back(blockVector);
							}
						}
					}
				}
			}
		}

		// TODO Mode
	};

	/**
	 * This is an array of block indices to use in this row.
	 */
	std::vector<std::vector<int>> blocks;

	/**
	 * To specify a display mode other than weighted, add an object here with a type.
	 */
	//auto mode; TODO

};

#endif //TUMBLRAPI_ROWS_HPP
