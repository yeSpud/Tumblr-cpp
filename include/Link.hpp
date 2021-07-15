//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_LINK_HPP
#define TUMBLRAPI_LINK_HPP

public:

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
		Image poster;

	};

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Link generateLink(const rapidjson::Value &entry);

#endif //TUMBLRAPI_LINK_HPP
