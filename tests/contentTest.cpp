//
// Created by Spud on 6/25/22.
//

#include "contentTest.hpp"
#include "posts/text_post.hpp"
#include <catch2/catch.hpp>
#include "posts/image_post.hpp"
#include "posts/link_post.hpp"
#include "posts/video_post.hpp"
#include "posts/audio_post.hpp"

void ContentTest::testContent(const std::vector<std::shared_ptr<Content>>& content) {

	for (const auto& c : content) {

		switch (c->type) {
			case Content::text: {
				std::shared_ptr<Text> textPointer = std::static_pointer_cast<Text>(c);
				REQUIRE(!textPointer->text.empty());
				break;
			}
			case Content::photo: {
				std::shared_ptr<Image> imagePointer = std::static_pointer_cast<Image>(c);
				for (const Media& media : imagePointer->media) {
					REQUIRE(!media.url.empty());
				}
				break;
			}
			case Content::link: {
				std::shared_ptr<Link> linkPointer = std::static_pointer_cast<Link>(c);
				REQUIRE(!linkPointer->url.empty());
				break;
			}
			case Content::video: {
				std::shared_ptr<Video> videoPointer = std::static_pointer_cast<Video>(c);
				if (videoPointer->url.empty()) {
					REQUIRE(videoPointer->media != nullptr);
				} else if (videoPointer->media == nullptr) {
					REQUIRE(!videoPointer->url.empty());
				} else if (videoPointer->url.empty() && videoPointer->media == nullptr) {
					FAIL("Either the video url or the media object needs to exist!");
				}
				break;
			}
			case Content::audio: {
				std::shared_ptr<Audio> audioPointer = std::static_pointer_cast<Audio>(c);
				if (audioPointer->url.empty()) {
					REQUIRE(audioPointer->media != nullptr);
				} else if (audioPointer->media == nullptr) {
					REQUIRE(!audioPointer->url.empty());
				} else if (audioPointer->url.empty() && audioPointer->media == nullptr) {
					FAIL("Either the audio url or the media object needs to exist!");
				}
				break;
			}
			default:
				FAIL("Unhandled content type");
				break;
		}
	}
}