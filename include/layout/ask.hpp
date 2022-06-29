//
// Created by Spud on 7/16/21.
//

#ifndef TUMBLRAPI_ASK_HPP
#define TUMBLRAPI_ASK_HPP

#include "layout.hpp"
#include "attributes/blog_attribution.hpp"


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

		// Attribution.
		if (layoutJsonObject.HasMember("attribution")) {
			if (layoutJsonObject["attribution"].IsObject()) {
				const rapidjson::GenericObject<true, rapidjson::Value> attributionObject = layoutJsonObject["attribution"].GetObj();

				MinimalBlog blog = MinimalBlog(attributionObject);
				BlogAttribution blogAttribution = BlogAttribution(attributionObject, blog);
				this->attribution = std::make_shared<BlogAttribution>(blogAttribution);
			}
		}
	}

	/**
	 * This is an array of block indices that are a part of the ask content of the Post.
	 */
	std::vector<std::vector<int>> blocks;

	/**
	 * If the ask is not anonymous, this will include information about the blog that submitted the ask.
	 */
	std::shared_ptr<BlogAttribution> attribution;

};

#endif //TUMBLRAPI_ASK_HPP
