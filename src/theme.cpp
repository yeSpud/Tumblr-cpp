//
// Created by Spud on 7/14/21.
//

#include "theme.hpp"
#include "npf/npf.hpp" // npf.hpp has very useful preprocessors and static functions that are very nice to use.

Theme Theme::generateTheme(const JSON_OBJECT &entry) { // TODO Comments

	Theme theme;

	objectHasValue(entry, "avatar_shape", theme.avatar_shape);
	objectHasValue(entry, "background_color", theme.background_color);
	objectHasValue(entry, "body_font", theme.body_font);

	// TODO Header bounds when implemented

	objectHasValue(entry, "header_image", theme.header_image);
	objectHasValue(entry, "header_image_focused", theme.header_image_focused);
	objectHasValue(entry, "header_image_poster", theme.header_image_poster);
	objectHasValue(entry, "header_image_scaled", theme.header_image_scaled);
	objectHasValue(entry, "header_stretch", theme.header_stretch);
	objectHasValue(entry, "link_color", theme.link_color);
	objectHasValue(entry, "show_avatar", theme.show_avatar);
	objectHasValue(entry, "show_description", theme.show_description);
	objectHasValue(entry, "show_header_image", theme.show_header_image);
	objectHasValue(entry, "show_title", theme.show_title);
	objectHasValue(entry, "title_color", theme.title_color);
	objectHasValue(entry, "title_font", theme.title_font);
	objectHasValue(entry, "title_font_weight", theme.title_font_weight);

	return theme;

}
