//
// Created by Spud on 7/4/22.
//

#ifndef TUMBLRAPI_NOTE_HPP
#define TUMBLRAPI_NOTE_HPP

#include "theme.hpp"

class Note {

public:

	explicit Note(const rapidjson::GenericObject<true, rapidjson::Value>& noteJsonObjet) {

		TumblrAPI::setStringFromJson(noteJsonObjet, "type", this->type);

		TumblrAPI::setUInt64FromJson(noteJsonObjet, "timestamp", this->timestamp);

		TumblrAPI::setStringFromJson(noteJsonObjet, "blog_name", this->blog_name);
		TumblrAPI::setStringFromJson(noteJsonObjet, "blog_uuid", this->blog_uuid);
		TumblrAPI::setStringFromJson(noteJsonObjet, "blog_url", this->blog_url);

		TumblrAPI::setBooleanFromJson(noteJsonObjet, "followed", this->followed);

		// Set avatar shape
		std::string avatarShapeString;
		TumblrAPI::setStringFromJson(noteJsonObjet, "avatar_shape", avatarShapeString);

		if (avatarShapeString == "circle") {
			this->avatar_shape = Theme::shape::circle;
		} else if (avatarShapeString == "square") {
			this->avatar_shape = Theme::shape::square;
		} else {
			TUMBLR_LOGGER->warn("Unable to determine avatar shape: {} | Defaulting to square." + avatarShapeString);
			this->avatar_shape = Theme::shape::square;
		}

		// Post ID may be a string?
		if (noteJsonObjet.HasMember("post_id")) {

			if (noteJsonObjet["post_id"].IsString()) {
				TUMBLR_LOGGER->info("post_id ended up being a string...");
				this->post_id = std::stoll(noteJsonObjet["post_id"].GetString());
			} else if (noteJsonObjet["post_id"].IsInt64()) {
				this->post_id = noteJsonObjet["post_id"].GetInt64();
			} else {
				TUMBLR_LOGGER->warn("Unable to determine post_id type.");
			}
		}

		TumblrAPI::setStringFromJson(noteJsonObjet, "reblog_parent_blog_name", this->reblog_parent_blog_name);
	}

	enum mode {

		/**
		 * All notes for the post.
		 */
		all,

		/**
		 * Only likes for the post.
		 */
		likes,

		/**
		 * Only replies and reblogs with added text commentary,
		 * with the rest of the notes (likes, reblogs without commentary) in a rollup_notes field.
		 */
		conversation,

		/**
		 * Only like and reblog notes for the post in the notes array.
		 */
		rollup,

		/**
		 * Only the reblog notes for the post, and each note object includes a tags array field (which may be empty).
		 */
		reblogs_with_tags

	};

	/**
	 * TODO Documentation
	 */
	std::string type;

	/**
	 * TODO Documentation
	 */
	unsigned long long timestamp = 0;

	/**
	 * TODO Documentation
	 */
	std::string blog_name;

	/**
	 * TODO Documentation
	 */
	std::string blog_uuid;

	/**
	 * TODO Documentation
	 */
	std::string blog_url;

	/**
	 * TODO Documentation
	 */
	bool followed = false;

	/**
	 * TODO Documentation
	 */
	Theme::shape avatar_shape;

	/**
	 * The ID of the post to fetch notes for
	 */
	long long post_id;

	/**
	 * TODO Documentation
	 */
	std::string reblog_parent_blog_name;

};

struct NoteResponse {

	/**
	 * An array of notes, which may be formatted differently based on the mode and note type.
	 */
	std::vector<Note> notes;

	/**
	 * In "conversation" mode, this contains notes not listed in the notes array.
	 */
	std::vector<Note> rollup_notes;

	/**
	 * The total notes, which can change depending on the mode.
	 */
	unsigned long long total_notes = 0;

	/**
	 * The total likes, when mode is conversation.
	 */
	unsigned long long total_likes = 0;

	/**
	 * The total reblogs, when mode is conversation.
	 */
	unsigned long long total_reblogs = 0;

	/**
	 * Contains a next link object for pagination.
	 */
	//auto _links; TODO
};

#endif //TUMBLRAPI_NOTE_HPP
