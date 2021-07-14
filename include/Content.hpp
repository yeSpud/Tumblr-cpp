//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include <vector>
#include "rapidjson/document.h"
#include "TumblrAPI.hpp"

/**
 * Neue Post Format stuff
 * TODO Documentation
 */
class Content {

public:

	/**
	 * The blog's general theme options, which may not be useful if the blog uses a custom theme.
	 * Used by blog info.
	 */
	struct Theme {

		/**
		 * "Circle" or "square", this is the shape of the mask over the user's avatar.
		 */
		std::string avatar_shape;

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
		 * If the blog cropped/repositioned their header image, this will be that version, which should be preferred over the original.
		 */
		std::string header_image_focused;

		/**
		 * The URL of a single-frame "poster" version of the blog's header image, if it's an animated image.
		 * Note that this may be an empty string if no poster could be made or is not needed.
		 */
		std::string header_image_poster;

		/**
		 * If the blog only scaled their header image, this will be that scaled version.
		 * Note that this may be a default Tumblr header image in the case that they scaled and repositioned it, in which case, use the _focused version.
		 */
		std::string header_image_scaled;

		/**
		 * Whether or not the blog's header is meant to be stretched to aspect-fill any given space where it's used.
		 */
		bool header_stretch;

		/**
		 * The intended hex color of any links in the blog's description.
		 */
		std::string link_color;

		/**
		 * Whether or not the blog's avatar should be displayed, even if it's given in the API payload.
		 */
		bool show_avatar;

		/**
		 * Whether or not the blog's description should be displayed, even if it's given in the API payload.
		 */
		bool show_description;

		/**
		 * Whether or not the blog's header image should be displayed, even if it's given in the API payload.
		 */
		bool show_header_image;

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

	};

	/**
	 * TODO Documentation
	 */
	struct Text {

		/**
		 * TODO Documentation
		 */
		std::string type;

		/**
		 * The text to use
		 */
		std::string text;

		/**
		 * The subtype of text block
		 */
		std::string subtype; // TODO Make this into an enum

		/**
		 * TODO Documentation
		 */
		int indent_level; // TODO Concert to u_int64?

		// TODO
		// auto formatting;
	};

	/**
	 * TODO Documentation
	 */
	struct Image {

		/**
		 * The MIME type of the image asset, or a best approximation will be made based on the given URL
		 */
		std::string type;

		/**
		 * TODO Documentation
		 * Undocumented?
		 */
		std::string media_key;

		/**
		 * The width of the image asset
		 */
		unsigned int width;

		/**
		 * The height of the media asset
		 */
		unsigned int height;

		/**
		 * The canonical URL of the image asset
		 */
		std::string url;

		/**
		 * This indicates whether this media object has the same dimensions as the original media
		 */
		bool has_original_dimensions = false;

	};

	/**
	 * TODO Documentation
	 */
	struct Link {

		/**
		 * The URL to use
		 */
		std::string url;

		/**
		 * The title of where the link goes.
		 */
		std::string title;

		/**
		 * The description of where the link goes.
		 */
		std::string description;

		/**
		 * The author of the link's content.
		 */
		std::string author;

		/**
		 * The name of the site being linked to.
		 */
		std::string site_name;

		/**
		 * TODO Documentation
		 */
		std::string display_url;

		/**
		 * An image object to use as a "poster" for the link.
		 */
		Content::Image poster;

	};

	/**
	 * TODO Documentation
	 */
	struct Audio {

		/**
		 * TODO Documentation
		 */
		std::string type;

		/**
		 * The URL to use for the audio content, if no media is present.
		 */
		std::string url;

		// TODO
		// auto media;

		/**
		 * The provider of the audio source, whether it's tumblr for native audio or a trusted third party.
		 */
		std::string provider;

		/**
		 * The title of the audio asset.
		 */
		std::string title;

		/**
		 * The artist of the audio asset.
		 */
		std::string artist;

		/**
		 * The album from which the audio asset originated.
		 */
		std::string album;

		/**
		 * An image to use as a "poster" for the audio track, usually album art.
		 */
		Content::Image poster;

		/**
		 * HTML code that could be used to embed this audio track into a webpage.
		 */
		std::string embed_html;

		/**
		 * A URL to the embeddable content to use as an iframe.
		 */
		std::string embed_url;

		// TODO
		// auto metadata;

		// TODO
		// auto attribution;
	};

	/**
	 * TODO Documentation
	 */
	struct Video {

		/**
		 * TODO Documentation
		 */
		std::string type;

		/**
		 * The URL to use for the video content, if no media is present.
		 */
		std::string url;

		// TODO
		// auto media;

		/**
		 * The provider of the video, whether it's tumblr for native video or a trusted third party.
		 */
		std::string provider;

		/**
		 * HTML code that could be used to embed this video into a webpage.
		 */
		std::string embed_html;

		// TODO
		// auto embed_iframe;

		/**
		 * A URL to the embeddable content to use as an iframe.
		 */
		std::string embed_url;

		/**
		 * An image to use as a "poster" for the video, usually a single frame.
		 */
		Content::Image poster;

		// TODO
		// auto metadata;

		// TODO
		// auto attribution;

		/**
		 * TODO Documentation
		 * Undocumented?
		 */
		std::vector<Content::Image> filmstrip;

		/**
		 * Whether this video can be played on a cellular connection.
		 */
		bool can_autoplay_on_cellular;

	};

	/**
	 * TODO Docuementation
	 */
	struct Attribution {

		/**
		 * TODO Documentation
		 */
		std::string type;

		/**
		 * TODO Documentation
		 */
		std::string url;

		/**
		 * TODO Documentation
		 */
		TumblrAPI::Post post;

		/**
		 * TODO Documentation
		 */
		TumblrAPI::Blog blog;

	};

	/**
	 * TODO Documentation
	 * @param entry
	 * @param value
	 * @param buffer
	 * @return
	 */
	static bool entryHasString(const rapidjson::Value &entry, const char *value, std::string &buffer);

	/**
	 * TODO Documentation
	 * @param entry
	 * @param value
	 * @param buffer
	 * @return
	 */
	static bool entryHasInt(const rapidjson::Value &entry, const char *value, unsigned int &buffer);

	// TODO Parse the different types of content

};

#endif //TUMBLRAPI_CONTENT_HPP
