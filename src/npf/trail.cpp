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

Trail::~Trail() = default;

void Trail::populateContentPointerArray(const JSON_OBJECT &object, std::vector<std::shared_ptr<Content>> &array) { // TODO Comments

	POPULATE_ARRAY(object, "content", for (JSON_ARRAY_ENTRY &entry : object["content"].GetArray()) {

		if (entry.IsObject()) { // TODO Might need fixing...
			if (entry.HasMember("type")) {
				if (entry["type"].IsString()) {
					std::string type = entry["type"].GetString();

					if (type == "audio") {
						Audio audio;
						audio.populateNPF(entry.GetObj());
						array.push_back(std::make_unique<Audio>(audio));
					} else if (type == "image") {
						Image image;
						image.populateNPF(entry.GetObj());
						array.push_back(std::make_unique<Image>(image));
					} else if (type == "link") {
						Link link;
						link.populateNPF(entry.GetObj());
						array.push_back(std::make_unique<Link>(link));
					} else if (type == "text") {
						Text text;
						text.populateNPF(entry.GetObj());
						array.push_back(std::make_unique<Text>(text));
					} else if (type == "video") {
						Video video;
						video.populateNPF(entry.GetObj());
						array.push_back(std::make_unique<Video>(video));
					}
				}
			}
		}
	})

}

void Trail::populateLayoutPointerArray(const JSON_OBJECT &object, std::vector<std::shared_ptr<Layout>> &array) { // TODO Comments

	POPULATE_ARRAY(object, "layout", for (JSON_ARRAY_ENTRY &entry : object["layout"].GetArray()) {
		if (entry.IsObject()) { // TODO Might need fixing...
			if (entry.HasMember("type")) {
				if (entry["type"].IsString()) {
					std::string type = entry["type"].GetString();

					if (type == "ask") {
						Ask ask;
						ask.populateNPF(entry.GetObj());
						array.push_back(std::shared_ptr<Ask>(&ask));
					} else if (type == "condensed") {
						Condensed condensed;
						condensed.populateNPF(entry.GetObj());
						array.push_back(std::shared_ptr<Condensed>(&condensed));
					} else if (type == "rows") {
						// TODO Figure out carousel type specifier.
						Rows rows;
						rows.populateNPF(entry.GetObj());
						array.push_back(std::shared_ptr<Rows>(&rows));
					}
				}
			}
		}
	})

}

void Trail::populateNPF(JSON_OBJECT entry) { // TODO Comments

	POPULATE_OBJECT(entry, "post", post = std::shared_ptr<Post>(new Post); post->populatePost(entry["post"].GetObj());)
	POPULATE_OBJECT(entry, "blog", blog = std::shared_ptr<Blog>(new Blog); blog->populateBlog(entry["blog"].GetObj());)

	populateContentPointerArray(entry, content);
	populateLayoutPointerArray(entry, layout);

	objectHasValue(entry, "broken_blog_name", broken_blog_name);

}
