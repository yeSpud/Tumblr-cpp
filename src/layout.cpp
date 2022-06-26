//
// Created by Spud on 6/25/22.
//

#include "layout/layout.hpp"
#include "layout/carousel.hpp"
#include "layout/condensed.hpp"
#include "layout/ask.hpp"

std::shared_ptr<Layout> Layout::getLayoutFromJsonObject(const rapidjson::GenericObject<true, rapidjson::Value> &layoutJsonObject) {

	std::string layoutTypeString;
	TumblrAPI::setStringFromJson(layoutJsonObject, "type", layoutTypeString);

	if (layoutTypeString == "rows") {

		// Having "truncate_after" signifies a carousel layout.
		// TODO Also check for mode of carousel
		if (layoutJsonObject.HasMember("truncate_after")) {
			Carousel carouselLayout = Carousel(layoutJsonObject);
			return std::make_shared<Carousel>(carouselLayout);
		} else {
			Rows rowsLayout = Rows(layoutJsonObject);
			return std::make_shared<Rows>(rowsLayout);
		}
	} else if (layoutTypeString == "condensed") {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
		Condensed contentLayout = Condensed(layoutJsonObject);
		return std::make_shared<Condensed>(contentLayout);
#pragma clang diagnostic pop
	} else if (layoutTypeString == "ask") {
		Ask askLayout = Ask(layoutJsonObject);
		return std::make_shared<Ask>(askLayout);
	} else {
		spdlog::get("TumblrAPI Logger")->warn("Unable to recognize layout type {}", layoutTypeString);
		return nullptr;
	}
}

void Layout::setLayoutVectorFromJsonObject(const rapidjson::GenericObject<true, rapidjson::Value> &jsonObject,
                                           std::vector<std::shared_ptr<Layout>> &vectorBuffer) {

	const rapidjson::Value* postLayoutJsonPointer = TumblrAPI::getValuePointerFromJson(jsonObject, "layout");
	if (postLayoutJsonPointer != nullptr) {
		if (postLayoutJsonPointer->IsArray()) {
			rapidjson::GenericArray postLayoutArray = postLayoutJsonPointer->GetArray();
			if (!postLayoutArray.Empty()) {
				for (const rapidjson::Value& layoutEntry : postLayoutArray) {
					if (layoutEntry.IsObject()) {
						rapidjson::GenericObject entryObject = layoutEntry.GetObj();
						auto layout = Layout::getLayoutFromJsonObject(entryObject);
						vectorBuffer.push_back(layout);
					}
				}
			}
		}
	}
}