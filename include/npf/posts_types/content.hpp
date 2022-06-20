//
// Created by Spud on 7/13/21.
//

#ifndef TUMBLRAPI_CONTENT_HPP
#define TUMBLRAPI_CONTENT_HPP

/**
 * TODO Documentation
 */
class Content {

public:

	/**
	 * TODO Documentation
	 */
	enum postType {

		/**
		 * TODO Documentation
		 */
		text,

		/**
		 * TODO Documentation
		 */
		quote,

		/**
		 * TODO Documentation
		 */
		link,

		/**
		 * TODO Documentation
		 */
		answer,

		/**
		 * TODO Documentation
		 */
		video,

		/**
		 * TODO Documentation
		 */
		audio,

		/**
		 * TODO Documentation
		 */
		photo,

		/**
		 * TODO Documentation
		 */
		chat,

		/**
		 * TODO Documentation
		 */
		all
	};

	/**
	 * TODO Documentation
	 * @param type
	 */
	explicit Content(const Content::postType &type) : type(type){};

	/**
	 * TODO Documentation
	 */
	const Content::postType type;

};

#endif //TUMBLRAPI_CONTENT_HPP
