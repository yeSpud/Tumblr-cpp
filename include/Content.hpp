//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

#include <vector>
#include <string>
#include "rapidjson/document.h"

/**
 * Neue Post Format stuff
 * TODO Documentation
 */
class Content {

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

	/**
	 * Media objects are used for image blocks, all kinds of posters (GIF, video, etc), native audio, native video,
	 * and some trusted third-party content. All media objects returned from the API should contain type and url,
	 * and any video and image media objects should always contain a width and height.
	 */
	struct MediaObject {

		/**
		 * The canonical URL of the media asset.
		 */
		std::string url;

		/**
		 * The MIME type of the media asset, or a best approximation will be made based on the given URL.
		 */
		std::string type;

		/**
		 * The width of the media asset, if that makes sense (for images and videos, but not for audio).
		 */
		int width;

		/**
		 * The height of the media asset, if that makes sense (for images and videos, but not for audio).
		 */
		int height;

		/**
		 * For display purposes, this indicates whether the dimensions are defaults.
		 */
		bool original_dimensions_missing;

		/**
		 * This indicates whether this media object is a cropped version of the original media.
		 */
		bool cropped;

		/**
		 * This indicates whether this media object has the same dimensions as the original media.
		 */
		bool has_original_dimensions;

	};

	/**
	 * TODO Documentation
	 */
	struct iFrameObject {
		// TODO
	};

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
		Content::subtype subtype;

		/**
		 * TODO Documentation
		 */
		uint64_t indent_level;

		// TODO
		// auto formatting;
	};

	/**
	 * TODO Documentation
	 */
	struct Image;

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
	struct Audio;

	/**
	 * TODO Documentation
	 */
	struct Video;

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
	static bool entryHasNumber(const rapidjson::Value &entry, const char *value, uint64_t &buffer);

	/**
	 * TODO Documentation
	 * @param entry
	 * @param value
	 * @param buffer
	 * @return
	 */
	static bool entryHasBool(const rapidjson::Value &entry, const char *value, bool &buffer);

	// TODO Media generation

	// TODO iFrame generation

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Content::Theme generateTheme(const rapidjson::Value &entry);

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Content::Text generateText(const rapidjson::Value &entry);

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Content::Image generateImage(const rapidjson::Value &entry);

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Content::Link generateLink(const rapidjson::Value &entry);

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Content::Audio generateAudio(const rapidjson::Value &entry);

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Content::Video generateVideo(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_CONTENT_HPP
