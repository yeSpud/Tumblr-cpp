//
// Created by Spud on 7/14/21.
//

#include "attribution.hpp"
/*
struct attribution::Attribution {

	**
	 * The type of the attribution.
	 * Current valid values are "link", "blog", "post", or "app".
	 *
	attributionType type;

	**
	 * The URL to be attributed.
	 *
	std::string url;

	**
	 * A Post pointer with at least the id field.
	 *
	post::Post *post;

	**
	 * A Blog pointer with at least the uuid field.
	 *
	blog::Blog *blog;

	**
	 * The name of the application to be attributed.
	 *
	std::string app_name;

	**
	 * Any display text that the client should use with the attribution.
	 *
	std::string display_text;

	**
	 * A specific logo that the client should use with the third-party app attribution.
	 *
	Media logo;

};
*/

Attribution Attribution::generateAttribution(const rapidjson::Value &entry) {
	// TODO
}

