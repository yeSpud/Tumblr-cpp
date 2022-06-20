//
// Created by spud on 6/17/22.
//

#ifndef TUMBLRAPI_TEXT_POST_HPP
#define TUMBLRAPI_TEXT_POST_HPP

#include "content.hpp"
#include "npf/content/formatting.hpp"

class Text : public Content {

public:

	/**
	 * Text blocks can also have a subtype field that specifies a semantic meaning to the text block,
	 * which can also be used by the clients to render the entire block of text differently.
	 */
	enum subtype {

		/**
		 * Intended for Post headings.
		 */
		heading1,

		/**
		 * Intended for section subheadings.
		 */
		heading2,

		/**
		 * Tumblr Official clients display this with a large cursive font.
		 */
		quirky,

		/**
		 * Intended for short quotations, official Tumblr clients display this with a large serif font.
		 */
		quote,

		/**
		 * Intended for longer quotations or photo captions, official Tumblr clients indent this text block.
		 */
		indented,

		/**
		 * Intended to mimic the behavior of the Chat Post type,
		 * official Tumblr clients display this with a monospace font.
		 */
		chat,

		/**
		 * Intended to be an ordered list item prefixed by a number, see next section.
		 */
		ordered_list_item,

		/**
		 * Intended to be an unordered list item prefixed with a bullet, see next section.
		 */
		unordered_list_item

	};

	Text(const rapidjson::Value &contentJson, std::string  text) : Content(postType::text), text(std::move(text)) {

		if (contentJson.HasMember("subtype")) {
			const rapidjson::Value &contentJsonValue = contentJson["subtype"];
			if (contentJsonValue.IsString()) {
				std::string subtypeString = contentJsonValue.GetString();

				if (subtypeString == "heading1") {
					this->subtype = Text::subtype::heading1;
				} else if (subtypeString == "heading2") {
					this->subtype = Text::subtype::heading2;
				} else if (subtypeString == "quriky") {
					this->subtype = Text::subtype::quirky;
				} else if (subtypeString == "quote") {
					this->subtype = Text::subtype::quote;
				} else if (subtypeString == "indented") {
					this->subtype = Text::subtype::indented;
				} else if (subtypeString == "chat") {
					this->subtype = Text::subtype::chat;
				} else if (subtypeString == "ordered_list_item") {
					this->subtype = Text::subtype::ordered_list_item;
				} else if (subtypeString == "unordered_list_item") {
					this->subtype = Text::subtype::unordered_list_item;
				} else {
					spdlog::get("TumblrAPI Logger")->warn("Unable to assign subtype for type {}.\nDefaulting to quote.", subtypeString);
					this->subtype = Text::subtype::quote;
				}
			}
		}

		if (contentJson.HasMember("indent_level")) {
			const rapidjson::Value &contentJsonValue = contentJson["indent_level"];
			if (contentJsonValue.IsUint()) {
				this->indent_level = contentJsonValue.GetUint();
			}
		}

		// FIXME Add formatting

	};

	/**
	 * The text to use inside this block.
	 */
	const std::string text;

	/**
	 * 	The subtype of text block.
	 */
	Text::subtype subtype;

	/**
	 * The default indent_level is 0 for all cases. An indent_level of 1 with a list item subtype means the list item is nested; an indent_level of 2 means it is doubly nested, etc. up to the maximum of 7.
	 */
	unsigned short indent_level = 0;

	/**
	 * TODO Documentation
	 */
	std::vector<Formatting> formatting;


};

#endif //TUMBLRAPI_TEXT_POST_HPP
