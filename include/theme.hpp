//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_THEME_HPP
#define TUMBLRAPI_THEME_HPP

#include <string>
#include "rapidjson/document.h"

/**
* The blog's general theme options, which may not be useful if the blog uses a custom theme.
* Used by blog info.
*/
class Theme {

public:

	/**
	 * "Circle" or "square", this is the shape of the mask over the user's avatar.
	 */
	std::string avatar_shape; // TODO Convert to enum

	/**
	 * The intended hex color used for the blog's background color.
	 */
	std::string background_color;

	/**
	 * The font that the blog has selected as their "body" font.
	 */
	std::string body_font;

	// If the blog's header should be cropped, this is a comma-separated list of top/right/bottom/left coordinates to use.
	// TODO
	// auto header_bounds;

	/**
	 * The URL of the blog's original, full header image. Note that this may be a default Tumblr header image.
	 */
	std::string header_image;

	/**
	 * If the blog cropped/repositioned their header image, this will be that version,
	 * which should be preferred over the original.
	 */
	std::string header_image_focused;

	/**
	 * The URL of a single-frame "poster" version of the blog's header image, if it's an animated image.
	 * Note that this may be an empty string if no poster could be made or is not needed.
	 */
	std::string header_image_poster;

	/**
	 * If the blog only scaled their header image, this will be that scaled version.
	 * Note that this may be a default Tumblr header image in the case that they scaled and repositioned it,
	 * in which case, use the _focused version.
	 */
	std::string header_image_scaled;

	/**
	 * Whether or not the blog's header is meant to be stretched to aspect-fill any given space where it's used.
	 */
	bool header_stretch = false;

	/**
	 * The intended hex color of any links in the blog's description.
	 */
	std::string link_color;

	/**
	 * Whether or not the blog's avatar should be displayed, even if it's given in the API payload.
	 */
	bool show_avatar = false;

	/**
	 * Whether or not the blog's description should be displayed, even if it's given in the API payload.
	 */
	bool show_description = false;

	/**
	 * Whether or not the blog's header image should be displayed, even if it's given in the API payload.
	 */
	bool show_header_image = false;

	/**
	 * Whether or not the blog's title should be displayed, even if it's given in the API payload.
	 */
	bool show_title = false;

	/**
	 * The intended hex color of the blog's title.
	 */
	std::string title_color;

	/**
	 * The intended font to use when displaying the blog's title.
	 */
	std::string title_font;

	/**
	 * The intended font weight to use when displaying the blog's title.
	 */
	std::string title_font_weight;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Theme generateTheme(const rapidjson::GenericObject<false, rapidjson::GenericValue<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>> &entry);

};

#endif //TUMBLRAPI_THEME_HPP
