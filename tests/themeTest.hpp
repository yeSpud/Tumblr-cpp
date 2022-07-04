//
// Created by Spud on 7/24/21.
//

#ifndef TUMBLRAPI_THEMETEST_HPP
#define TUMBLRAPI_THEMETEST_HPP

#include "theme.hpp"

class ThemeTest {

public:

	/**
	 * TODO Documentation
	 * @param theme
	 * @param avatar_shape
	 * @param background_color
	 * @param body_font
	 * @param header_image
	 * @param header_image_focused
	 * @param header_image_poster
	 * @param header_image_scaled
	 * @param header_stretch
	 * @param link_color
	 * @param show_avatar
	 * @param show_description
	 * @param show_header_image
	 * @param show_title
	 * @param title_color
	 * @param title_font
	 * @param title_font_weight
	 */
	static void testTheme(const Theme &theme, const Theme::shape &avatar_shape, const std::string &background_color,
	                      const std::string &body_font, const std::string &header_image,
	                      const std::string &header_image_focused, const std::string &header_image_poster,
	                      const std::string &header_image_scaled, const bool &header_stretch,
	                      const std::string &link_color, const bool &show_avatar, const bool &show_description,
	                      const bool &show_header_image, const bool &show_title, const std::string &title_color,
	                      const std::string &title_font, const std::string &title_font_weight);

};

#endif //TUMBLRAPI_THEMETEST_HPP
