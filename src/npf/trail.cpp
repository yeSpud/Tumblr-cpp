//
// Created by Spud on 7/16/21.
//

#include "npf/trail.hpp"
#include "npf/content/audio.hpp"
#include "npf/content/link.hpp"
#include "npf/content/text.hpp"
#include "npf/content/video.hpp"
#include "npf/layout/ask.hpp"
#include "npf/layout/condensed.hpp"
#include "npf/layout/carousel.hpp"

Trail::~Trail() {

	/*
	if (post != nullptr) {
		delete post;
		post = nullptr;
	}
	 */
	DELETE_NPF(post)
	DELETE_NPF(blog)

	for (Content *c : content) {
		DELETE_NPF(c)
	}

	for (Layout *l : layout) {
		DELETE_NPF(l)
	}

}

void Trail::populateNPF(JSON_OBJECT entry) { // TODO Comments

	POPULATE_OBJECT(entry, "post", post = new Post(); post->populatePost(entry["post"].GetObj());)
	POPULATE_OBJECT(entry, "blog", blog = new Blog(); blog->populateBlog(entry["blog"].GetObj());)

	POPULATE_ARRAY(entry, "content", for (JSON_ARRAY_ENTRY &arrayEntry : entry["content"].GetArray()) {

		if (arrayEntry.IsObject()) {
			if (arrayEntry.HasMember("type")) {
				if (arrayEntry["type"].IsString()) {
					std::string type = arrayEntry["type"].GetString();

					if (type == "audio") {
						Audio audio;
						audio.populateNPF(arrayEntry.GetObj());
						content.push_back(&audio);
					} else if (type == "image") {
						Image image;
						image.populateNPF(arrayEntry.GetObj());
						content.push_back(&image);
					} else if (type == "link") {
						Link link;
						link.populateNPF(arrayEntry.GetObj());
						content.push_back(&link);
					} else if (type == "text") {
						Text text;
						text.populateNPF(arrayEntry.GetObj());
						content.push_back(&text);
					} else if (type == "video") {
						Video video;
						video.populateNPF(arrayEntry.GetObj());
						content.push_back(&video);
					}
				}
			}
		}
	})
	POPULATE_ARRAY(entry, "layout", for (JSON_ARRAY_ENTRY &arrayEntry : entry["layout"].GetArray()) {
		if (arrayEntry.IsObject()) {
			if (arrayEntry.HasMember("type")) {
				if (arrayEntry["type"].IsString()) {
					std::string type = arrayEntry["type"].GetString();

					if (type == "ask") {
						Ask ask;
						ask.populateNPF(arrayEntry.GetObj());
						layout.push_back(&ask);
					} else if (type == "condensed") {
						Condensed condensed;
						condensed.populateNPF(arrayEntry.GetObj());
						layout.push_back(&condensed);
					} else if (type == "rows") {
						// TODO Figure out carousel type specifier.

						Rows rows;
						rows.populateNPF(arrayEntry.GetObj());
						layout.push_back(&rows);
					}

				}
			}
		}
	})

	objectHasValue(entry, "broken_blog_name", broken_blog_name);

}
