//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_TEXT_HPP
#define TUMBLRAPI_TEXT_HPP

#include "content.hpp"
#include "formatting.hpp"

/**
 * TODO Documentation
 */
class Text : public Content {

protected:

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

public:

	/**
	 * TODO Documentation
	 */
	Text() : Content("text") {};

	/**
	 * The text to use.
	 */
	std::string text;

	/**
	 * The subtype of text block.
	 */
	subtype subtype;

	/**
	 * TODO Documentation
	 */
	uint64_t indent_level;

	/**
	 * TODO Documentation
	 */
	std::vector<Formatting> formatting;

	/**
	 * TODO Documentation
	 * @param entry
	 */
	void populateNPF(JSON_OBJECT entry) override;

};

#endif //TUMBLRAPI_TEXT_HPP
