//
// Created by Spud on 7/24/21.
//

#include "catch2/catch.hpp"
#include "postTest.hpp"
#include "blogTest.hpp"
#include "mediaTest.hpp"
#include "themeTest.hpp"
#include "imageTest.hpp"
#include <iostream>

void
PostTest::testPost(const Post &post, const Post::postType &type, const std::string& original_type, const std::string& blog_name,
                   uint64_t id, const std::string& id_string, const std::string& genesis_post_id, const std::string& post_url,
                   const std::string& slug, const std::string& date, uint64_t timestamp, const Post::postFormat &format,
                   const Post::postState &state, const std::string& reblog_key, std::vector<std::string> tags,
                   bool bookmarklet, bool mobile, const std::string& source_url, const std::string& source_title, bool liked,
                   uint64_t total_posts, const std::string& short_url, const std::string& post_author, bool is_submission,
                   const std::string& anonymous_name, const std::string& anonymous_email, const std::string& summary,
                   bool should_open_in_legacy, uint64_t note_count, bool can_like, bool can_reblog,
                   bool can_send_in_message, bool can_reply, bool display_avatar) {

	std::cout << "\nTesting post..." << std::endl;

	REQUIRE(post.type == type);
	REQUIRE(post.original_type == original_type);
	REQUIRE(post.blog_name == blog_name);
	REQUIRE(post.id == id);
	REQUIRE(post.id_string == id_string);
	REQUIRE(post.genesis_post_id == genesis_post_id);
	REQUIRE(post.post_url == post_url);
	REQUIRE(post.slug == slug);
	REQUIRE(post.date == date);
	REQUIRE(post.timestamp == timestamp);
	REQUIRE(post.format == format);
	REQUIRE(post.state == state);
	REQUIRE(post.reblog_key == reblog_key);

	for (int i = 0; i < tags.size(); i++) {
		REQUIRE(post.tags[i] == tags[i]);
	}

	REQUIRE(post.bookmarklet == bookmarklet);
	REQUIRE(post.mobile == mobile);
	REQUIRE(post.source_url == source_url);
	REQUIRE(post.source_title == source_title);
	REQUIRE(post.liked == liked);
	REQUIRE(post.total_posts == total_posts);
	REQUIRE(post.short_url == short_url);
	REQUIRE(post.post_author == post_author);
	REQUIRE(post.is_submission == is_submission);
	REQUIRE(post.anonymous_name == anonymous_name);
	REQUIRE(post.anonymous_email == anonymous_email);
	REQUIRE(post.summary == summary);
	REQUIRE(post.should_open_in_legacy == should_open_in_legacy);
	REQUIRE(post.note_count == note_count);
	REQUIRE(post.can_like == can_like);
	REQUIRE(post.can_reblog == can_reblog);
	REQUIRE(post.can_send_in_message == can_send_in_message);
	REQUIRE(post.can_reply == can_reply);
	REQUIRE(post.display_avatar == display_avatar);

	std::cout << "Post tested successfully\n" << std::endl;

}

TEST_CASE("Populate Post Test", "[Post]") {

	/*
	{
	    "type": "blocks",
	    "original_type": "regular",
	    "blog_name": "foxes-in-love",
	    "blog": {
	        "name": "foxes-in-love",
	        "title": "Foxes in Love",
	        "description": "",
	        "url": "https://foxes-in-love.tumblr.com/",
	        "uuid": "t:bF2JMCXfv_Agp-5ZfJQ75A",
	        "updated": 1631767427
	    },
	    "id": 662456162462154752,
	    "id_string": "662456162462154752",
	    "post_url": "https://foxes-in-love.tumblr.com/post/662456162462154752",
	    "slug": "",
	    "date": "2021-09-16 04:43:47 GMT",
	    "timestamp": 1631767427,
	    "state": "published",
	    "reblog_key": "DZRk9lQG",
	    "tags": [],
	    "short_url": "https://tmblr.co/Zn_LPXanX5woqq00",
	    "summary": "",
	    "should_open_in_legacy": false,
	    "recommended_source": null,
	    "recommended_color": null,
	    "note_count": 4973,
	    "content": [
	        {
	            "type": "image",
	            "media": [
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 1600,
	                    "height": 1600,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s2048x3072/fc4e3a881144ab9514936342187773381f9e87bb.jpg",
	                    "has_original_dimensions": true
	                },
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 1280,
	                    "height": 1280,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s1280x1920/6edfedea7b49384416c99828a97d0b52ef288d73.jpg"
	                },
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 640,
	                    "height": 640,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s640x960/082cb3411fe2de9181aab754124c64b56ae60883.jpg"
	                },
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 540,
	                    "height": 540,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s540x810/4223bb511a9435e79f03ecbee14050978c0d7edf.jpg"
	                },
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 500,
	                    "height": 500,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s500x750/6379a93ce8d5acd37254f184558c70e4ad99cabb.jpg"
	                },
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 400,
	                    "height": 400,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s400x600/7e96093ad6e2e9d293ac3ddcf1845e2fd6816da9.jpg"
	                },
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 250,
	                    "height": 250,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s250x400/01cac1bb8e4253537885edbeaabd9fa5266c53f0.jpg"
	                },
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 100,
	                    "height": 100,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s100x200/024aead13f5ef961e8247cbebb0f4667c905d738.jpg"
	                },
	                {
	                    "media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
	                    "type": "image/jpeg",
	                    "width": 75,
	                    "height": 75,
	                    "url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s75x75_c1/bb0d435b3ddb22b3ccb4d913d24af3d6dc3eae36.jpg",
	                    "cropped": true
	                }
	            ],
	            "colors": {
	                "c0": "fdfdfe",
	                "c1": "121213",
	                "c2": "395387",
	                "c3": "e3e5e6",
	                "c4": "b9b3b2"
	            },
	            "exif": {
	                "Time": "1625435142"
	            }
	        }
	    ],
	    "layout": [],
	    "trail": [],
	    "can_like": false,
	    "can_reblog": false,
	    "can_send_in_message": true,
	    "can_reply": false,
	    "display_avatar": true
	}
	 */

	rapidjson::Document singlePostDocument;
	singlePostDocument.Parse(R"({"type":"blocks","original_type":"regular","blog_name":"foxes-in-love","blog":{"name":"foxes-in-love","title":"Foxes in Love","description":"","url":"https://foxes-in-love.tumblr.com/","uuid":"t:bF2JMCXfv_Agp-5ZfJQ75A","updated":1631767427},"id":662456162462154752,"id_string":"662456162462154752","post_url":"https://foxes-in-love.tumblr.com/post/662456162462154752","slug":"","date":"2021-09-16 04:43:47 GMT","timestamp":1631767427,"state":"published","reblog_key":"DZRk9lQG","tags":[],"short_url":"https://tmblr.co/Zn_LPXanX5woqq00","summary":"","should_open_in_legacy":false,"recommended_source":null,"recommended_color":null,"note_count":4973,"content":[{"type":"image","media":[{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":1600,"height":1600,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s2048x3072/fc4e3a881144ab9514936342187773381f9e87bb.jpg","has_original_dimensions":true},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":1280,"height":1280,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s1280x1920/6edfedea7b49384416c99828a97d0b52ef288d73.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":640,"height":640,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s640x960/082cb3411fe2de9181aab754124c64b56ae60883.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":540,"height":540,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s540x810/4223bb511a9435e79f03ecbee14050978c0d7edf.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":500,"height":500,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s500x750/6379a93ce8d5acd37254f184558c70e4ad99cabb.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":400,"height":400,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s400x600/7e96093ad6e2e9d293ac3ddcf1845e2fd6816da9.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":250,"height":250,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s250x400/01cac1bb8e4253537885edbeaabd9fa5266c53f0.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":100,"height":100,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s100x200/024aead13f5ef961e8247cbebb0f4667c905d738.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":75,"height":75,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s75x75_c1/bb0d435b3ddb22b3ccb4d913d24af3d6dc3eae36.jpg","cropped":true}],"colors":{"c0":"fdfdfe","c1":"121213","c2":"395387","c3":"e3e5e6","c4":"b9b3b2"},"exif":{"Time":"1625435142"}}],"layout":[],"trail":[],"can_like":false,"can_reblog":false,"can_send_in_message":true,"can_reply":false,"display_avatar":true})");

	REQUIRE(singlePostDocument.IsObject());

	Post populatedPost;
	populatedPost.populatePost(singlePostDocument.GetObj());

	// Test generated post layout.
	REQUIRE(populatedPost.layout.empty());

	PostTest::testPost(populatedPost, Post::photo, "regular", "foxes-in-love", 662456162462154752,
					   "662456162462154752","", "https://foxes-in-love.tumblr.com/post/662456162462154752",
					   "", "2021-09-16 04:43:47 GMT",1631767427, Post::none, Post::published,
					   "DZRk9lQG", std::vector<std::string>(), false, false, "",
					           "", false, 0,"https://tmblr.co/Zn_LPXanX5woqq00",
							   "", false, "", "", "",
							   false, 4973, false, false, true,
							   false,true);

	// Test blog pointer for populated post.
	BlogTest::testBlog(populatedPost.blog.get(), false, false, "", false, false,
	                   false, "", false, "foxes-in-love", 0, 0,
	                   false,false, "Foxes in Love", 0, 1631767427, "",
	                   "", "https://foxes-in-love.tumblr.com/", "t:bF2JMCXfv_Agp-5ZfJQ75A",
	                   false, false);

	// Test populated post content.
	Image* populatedPostImage = dynamic_cast<Image*>(populatedPost.content[0].get());
	ImageTest::testImage(populatedPostImage, "", "");
	MediaTest::testMedia(populatedPostImage->media[0], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s2048x3072/fc4e3a881144ab9514936342187773381f9e87bb.jpg",
	                     1600, 1600, true, false, true);
	MediaTest::testMedia(populatedPostImage->media[1], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s1280x1920/6edfedea7b49384416c99828a97d0b52ef288d73.jpg",
	                     1280, 1280, true, false, false);
	MediaTest::testMedia(populatedPostImage->media[2], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s640x960/082cb3411fe2de9181aab754124c64b56ae60883.jpg",
	                     640, 640, true, false, false);
	MediaTest::testMedia(populatedPostImage->media[3], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s540x810/4223bb511a9435e79f03ecbee14050978c0d7edf.jpg",
	                     540, 540, true, false, false);
	MediaTest::testMedia(populatedPostImage->media[4], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s500x750/6379a93ce8d5acd37254f184558c70e4ad99cabb.jpg",
	                     500, 500, true, false, false);
	MediaTest::testMedia(populatedPostImage->media[5], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s400x600/7e96093ad6e2e9d293ac3ddcf1845e2fd6816da9.jpg",
	                     400, 400, true, false, false);
	MediaTest::testMedia(populatedPostImage->media[6], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s250x400/01cac1bb8e4253537885edbeaabd9fa5266c53f0.jpg",
	                     250, 250, true, false, false);
	MediaTest::testMedia(populatedPostImage->media[7], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s100x200/024aead13f5ef961e8247cbebb0f4667c905d738.jpg",
	                     100, 100, true, false, false);
	MediaTest::testMedia(populatedPostImage->media[8], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s75x75_c1/bb0d435b3ddb22b3ccb4d913d24af3d6dc3eae36.jpg",
	                     75, 75, true, true, false);

	// Test populated post layout.
	REQUIRE(populatedPost.layout.empty());

	// Test populated post trail.
	REQUIRE(populatedPost.trails.empty());

}

TEST_CASE("Generate Post Test", "[Post]") {

	/*
	{
		"blog": {
			"ask": false,
			"ask_anon": false,
			"ask_page_title": "Ask me anything",
			"asks_allow_media": true,
			"avatar": [
				{
					"width": 512,
					"height": 512,
					"url": "https://64.media.tumblr.com/avatar_a95095bda931_512.png"
				},
				{
					"width": 128,
					"height": 128,
					"url": "https://64.media.tumblr.com/avatar_a95095bda931_128.png"
				},
				{
					"width": 96,
					"height": 96,
					"url": "https://64.media.tumblr.com/avatar_a95095bda931_96.png"
				},
				{
					"width": 64,
					"height": 64,
					"url": "https://64.media.tumblr.com/avatar_a95095bda931_64.png"
				}
			],
			"can_chat": true,
			"can_subscribe": false,
			"description": "",
			"is_nsfw": false,
			"name": "foxes-in-love",
			"posts": 483,
			"share_likes": false,
			"subscribed": false,
			"theme": {
				"header_full_width": 850,
				"header_full_height": 850,
				"header_focus_width": 850,
				"header_focus_height": 479,
				"avatar_shape": "circle",
				"background_color": "#FAFAFA",
				"body_font": "Helvetica Neue",
				"header_bounds": "185,850,664,0",
				"header_image": "https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/Bx4plw0mr/tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o.jpg",
				"header_image_focused": "https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/VSyplw0ms/tumblr_static_tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o_focused_v3.jpg",
				"header_image_poster": "",
				"header_image_scaled": "https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/Bx4plw0mr/tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o_2048_v2.jpg",
				"header_stretch": true,
				"link_color": "#529ECC",
				"show_avatar": true,
				"show_description": true,
				"show_header_image": true,
				"show_title": true,
				"title_color": "#444444",
				"title_font": "Gibson",
				"title_font_weight": "bold"
			},
			"title": "Foxes in Love",
			"total_posts": 483,
			"updated": 1631767427,
			"url": "https://foxes-in-love.tumblr.com/",
			"uuid": "t:bF2JMCXfv_Agp-5ZfJQ75A",
			"is_optout_ads": true
		},
		"posts": [
			{
			"type": "blocks",
			"original_type": "regular",
			"blog_name": "foxes-in-love",
			"blog": {
				"name": "foxes-in-love",
				"title": "Foxes in Love",
				"description": "",
				"url": "https://foxes-in-love.tumblr.com/",
				"uuid": "t:bF2JMCXfv_Agp-5ZfJQ75A",
				"updated": 1631767427
			},
			"id": 662456162462154752,
			"id_string": "662456162462154752",
			"post_url": "https://foxes-in-love.tumblr.com/post/662456162462154752",
			"slug": "",
			"date": "2021-09-16 04:43:47 GMT",
			"timestamp": 1631767427,
			"state": "published",
			"reblog_key": "DZRk9lQG",
			"tags": [],
			"short_url": "https://tmblr.co/Zn_LPXanX5woqq00",
			"summary": "",
			"should_open_in_legacy": false,
			"recommended_source": null,
			"recommended_color": null,
			"note_count": 4973,
			"content": [
				{
				"type": "image",
				"media": [
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 1600,
					"height": 1600,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s2048x3072/fc4e3a881144ab9514936342187773381f9e87bb.jpg",
					"has_original_dimensions": true
					},
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 1280,
					"height": 1280,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s1280x1920/6edfedea7b49384416c99828a97d0b52ef288d73.jpg"
					},
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 640,
					"height": 640,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s640x960/082cb3411fe2de9181aab754124c64b56ae60883.jpg"
					},
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 540,
					"height": 540,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s540x810/4223bb511a9435e79f03ecbee14050978c0d7edf.jpg"
					},
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 500,
					"height": 500,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s500x750/6379a93ce8d5acd37254f184558c70e4ad99cabb.jpg"
					},
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 400,
					"height": 400,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s400x600/7e96093ad6e2e9d293ac3ddcf1845e2fd6816da9.jpg"
					},
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 250,
					"height": 250,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s250x400/01cac1bb8e4253537885edbeaabd9fa5266c53f0.jpg"
					},
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 100,
					"height": 100,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s100x200/024aead13f5ef961e8247cbebb0f4667c905d738.jpg"
					},
					{
					"media_key": "cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29",
					"type": "image/jpeg",
					"width": 75,
					"height": 75,
					"url": "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s75x75_c1/bb0d435b3ddb22b3ccb4d913d24af3d6dc3eae36.jpg",
					"cropped": true
					}
				],
				"colors": {
					"c0": "fdfdfe",
					"c1": "121213",
					"c2": "395387",
					"c3": "e3e5e6",
					"c4": "b9b3b2"
				},
				"exif": {
					"Time": "1625435142"
					}
				}
			],
			"layout": [],
			"trail": [],
			"can_like": false,
			"can_reblog": false,
			"can_send_in_message": true,
			"can_reply": false,
			"display_avatar": true
			}
		],
		"total_posts": 483,
		"_links": {
			"next": {
				"href": "/v2/blog/foxes-in-love.tumblr.com/posts?npf=true&limit=1&tumblelog=foxes-in-love.tumblr.com&page_number=VKaKChv_8ZfW55mJL2GuXjr5G5oI-Lv0CYJw6YIWk_drc3lMelU0VjBnbVpDVk82Q0xsdDI3aitUNi9wRFZYZWpWNnJFZ3QwUE9IYVRQU1hLUVJZN3lZZkxDbDBHanFuTkE0STQ4YU4vdWxGUzIrdHhPZjlGbmYvbVVzT2ZQL2p6V1l4WFJraDZwZXN3QW5NaTZsbFQ1TjhaejVaSk1VVnRnWnhXV2gxcFlXMWp5d1BRK1NHNGt3WkVWVmZ1cTZ0VkExZFZZZ3lTVnh4b2RPZitocnViTU1VNS9vcDdFcFBOUUllT0Erd2hiQXlWWndtcnRDU0VpZkdyVkdhREZuOENyWmpSTVhQcjFucnFrNEZRZGplb0xYZkVuMTBlVGF2OFZGRDlEVmROTG5Banl1S0UwRUZBTDJ1SDE3VElEbXd2bEk5TkNkY0kwcHBja1J3TFJ5cFBoM1I3b0M5b09CUVBBOTIxYXlRa0VDbFB2RDJXS3ZWRmE1WmNDZXBOYVJyTUoxYnptWFk2bVhiOEtDak4xeXVwUFEwanFiZWp6YitZ",
				"method": "GET",
				"query_params": {
					"npf": "true",
					"limit": "1",
					"tumblelog": "foxes-in-love.tumblr.com",
					"page_number": "VKaKChv_8ZfW55mJL2GuXjr5G5oI-Lv0CYJw6YIWk_drc3lMelU0VjBnbVpDVk82Q0xsdDI3aitUNi9wRFZYZWpWNnJFZ3QwUE9IYVRQU1hLUVJZN3lZZkxDbDBHanFuTkE0STQ4YU4vdWxGUzIrdHhPZjlGbmYvbVVzT2ZQL2p6V1l4WFJraDZwZXN3QW5NaTZsbFQ1TjhaejVaSk1VVnRnWnhXV2gxcFlXMWp5d1BRK1NHNGt3WkVWVmZ1cTZ0VkExZFZZZ3lTVnh4b2RPZitocnViTU1VNS9vcDdFcFBOUUllT0Erd2hiQXlWWndtcnRDU0VpZkdyVkdhREZuOENyWmpSTVhQcjFucnFrNEZRZGplb0xYZkVuMTBlVGF2OFZGRDlEVmROTG5Banl1S0UwRUZBTDJ1SDE3VElEbXd2bEk5TkNkY0kwcHBja1J3TFJ5cFBoM1I3b0M5b09CUVBBOTIxYXlRa0VDbFB2RDJXS3ZWRmE1WmNDZXBOYVJyTUoxYnptWFk2bVhiOEtDak4xeXVwUFEwanFiZWp6YitZ"
				}
			}
		}
	}
	 */

	std::string blogAndPostString = (R"({"meta":{"status":200,"msg":"OK"},"response":{"blog":{"ask":false,"ask_anon":false,"ask_page_title":"Ask me anything","asks_allow_media":true,"avatar":[{"width":512,"height":512,"url":"https://64.media.tumblr.com/avatar_a95095bda931_512.png"},{"width":128,"height":128,"url":"https://64.media.tumblr.com/avatar_a95095bda931_128.png"},{"width":96,"height":96,"url":"https://64.media.tumblr.com/avatar_a95095bda931_96.png"},{"width":64,"height":64,"url":"https://64.media.tumblr.com/avatar_a95095bda931_64.png"}],"can_chat":true,"can_subscribe":false,"description":"","is_nsfw":false,"name":"foxes-in-love","posts":483,"share_likes":false,"subscribed":false,"theme":{"header_full_width":850,"header_full_height":850,"header_focus_width":850,"header_focus_height":479,"avatar_shape":"circle","background_color":"#FAFAFA","body_font":"Helvetica Neue","header_bounds":"185,850,664,0","header_image":"https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/Bx4plw0mr/tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o.jpg","header_image_focused":"https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/VSyplw0ms/tumblr_static_tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o_focused_v3.jpg","header_image_poster":"","header_image_scaled":"https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/Bx4plw0mr/tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o_2048_v2.jpg","header_stretch":true,"link_color":"#529ECC","show_avatar":true,"show_description":true,"show_header_image":true,"show_title":true,"title_color":"#444444","title_font":"Gibson","title_font_weight":"bold"},"title":"Foxes in Love","total_posts":483,"updated":1631767427,"url":"https://foxes-in-love.tumblr.com/","uuid":"t:bF2JMCXfv_Agp-5ZfJQ75A","is_optout_ads":true},"posts":[{"type":"blocks","original_type":"regular","blog_name":"foxes-in-love","blog":{"name":"foxes-in-love","title":"Foxes in Love","description":"","url":"https://foxes-in-love.tumblr.com/","uuid":"t:bF2JMCXfv_Agp-5ZfJQ75A","updated":1631767427},"id":662456162462154752,"id_string":"662456162462154752","post_url":"https://foxes-in-love.tumblr.com/post/662456162462154752","slug":"","date":"2021-09-16 04:43:47 GMT","timestamp":1631767427,"state":"published","reblog_key":"DZRk9lQG","tags":[],"short_url":"https://tmblr.co/Zn_LPXanX5woqq00","summary":"","should_open_in_legacy":false,"recommended_source":null,"recommended_color":null,"note_count":4973,"content":[{"type":"image","media":[{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":1600,"height":1600,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s2048x3072/fc4e3a881144ab9514936342187773381f9e87bb.jpg","has_original_dimensions":true},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":1280,"height":1280,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s1280x1920/6edfedea7b49384416c99828a97d0b52ef288d73.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":640,"height":640,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s640x960/082cb3411fe2de9181aab754124c64b56ae60883.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":540,"height":540,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s540x810/4223bb511a9435e79f03ecbee14050978c0d7edf.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":500,"height":500,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s500x750/6379a93ce8d5acd37254f184558c70e4ad99cabb.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":400,"height":400,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s400x600/7e96093ad6e2e9d293ac3ddcf1845e2fd6816da9.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":250,"height":250,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s250x400/01cac1bb8e4253537885edbeaabd9fa5266c53f0.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":100,"height":100,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s100x200/024aead13f5ef961e8247cbebb0f4667c905d738.jpg"},{"media_key":"cd7cb9636b5d1ed62a4e2c262b3f27b8:14bdf768bba10f86-29","type":"image/jpeg","width":75,"height":75,"url":"https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s75x75_c1/bb0d435b3ddb22b3ccb4d913d24af3d6dc3eae36.jpg","cropped":true}],"colors":{"c0":"fdfdfe","c1":"121213","c2":"395387","c3":"e3e5e6","c4":"b9b3b2"},"exif":{"Time":"1625435142"}}],"layout":[],"trail":[],"can_like":false,"can_reblog":false,"can_send_in_message":true,"can_reply":false,"display_avatar":true}],"total_posts":483,"_links":{"next":{"href":"/v2/blog/foxes-in-love.tumblr.com/posts?npf=true&limit=1&tumblelog=foxes-in-love.tumblr.com&page_number=VKaKChv_8ZfW55mJL2GuXjr5G5oI-Lv0CYJw6YIWk_drc3lMelU0VjBnbVpDVk82Q0xsdDI3aitUNi9wRFZYZWpWNnJFZ3QwUE9IYVRQU1hLUVJZN3lZZkxDbDBHanFuTkE0STQ4YU4vdWxGUzIrdHhPZjlGbmYvbVVzT2ZQL2p6V1l4WFJraDZwZXN3QW5NaTZsbFQ1TjhaejVaSk1VVnRnWnhXV2gxcFlXMWp5d1BRK1NHNGt3WkVWVmZ1cTZ0VkExZFZZZ3lTVnh4b2RPZitocnViTU1VNS9vcDdFcFBOUUllT0Erd2hiQXlWWndtcnRDU0VpZkdyVkdhREZuOENyWmpSTVhQcjFucnFrNEZRZGplb0xYZkVuMTBlVGF2OFZGRDlEVmROTG5Banl1S0UwRUZBTDJ1SDE3VElEbXd2bEk5TkNkY0kwcHBja1J3TFJ5cFBoM1I3b0M5b09CUVBBOTIxYXlRa0VDbFB2RDJXS3ZWRmE1WmNDZXBOYVJyTUoxYnptWFk2bVhiOEtDak4xeXVwUFEwanFiZWp6YitZ","method":"GET","query_params":{"npf":"true","limit":"1","tumblelog":"foxes-in-love.tumblr.com","page_number":"VKaKChv_8ZfW55mJL2GuXjr5G5oI-Lv0CYJw6YIWk_drc3lMelU0VjBnbVpDVk82Q0xsdDI3aitUNi9wRFZYZWpWNnJFZ3QwUE9IYVRQU1hLUVJZN3lZZkxDbDBHanFuTkE0STQ4YU4vdWxGUzIrdHhPZjlGbmYvbVVzT2ZQL2p6V1l4WFJraDZwZXN3QW5NaTZsbFQ1TjhaejVaSk1VVnRnWnhXV2gxcFlXMWp5d1BRK1NHNGt3WkVWVmZ1cTZ0VkExZFZZZ3lTVnh4b2RPZitocnViTU1VNS9vcDdFcFBOUUllT0Erd2hiQXlWWndtcnRDU0VpZkdyVkdhREZuOENyWmpSTVhQcjFucnFrNEZRZGplb0xYZkVuMTBlVGF2OFZGRDlEVmROTG5Banl1S0UwRUZBTDJ1SDE3VElEbXd2bEk5TkNkY0kwcHBja1J3TFJ5cFBoM1I3b0M5b09CUVBBOTIxYXlRa0VDbFB2RDJXS3ZWRmE1WmNDZXBOYVJyTUoxYnptWFk2bVhiOEtDak4xeXVwUFEwanFiZWp6YitZ"}}}}})");
	Post generatedPost = *Post::generatePosts(blogAndPostString.c_str())[0].get();

	// Test blog in generated post.
	Blog generatedPostBlog = Blog::generateBlog(blogAndPostString.c_str());
	BlogTest::testBlog(&generatedPostBlog, false, false, "Ask me anything", true,
	                   true, false, "", false, "foxes-in-love", 483,
	                   0, false, false, "Foxes in Love", 483, 1631767427,
	                   "", "","https://foxes-in-love.tumblr.com/", "t:bF2JMCXfv_Agp-5ZfJQ75A",
	                   false, true);

	// Test blog avatars.
	MediaTest::testMedia(generatedPostBlog.avatars[0], "", "https://64.media.tumblr.com/avatar_a95095bda931_512.png",
	                     512, 512, true, false, false);
	MediaTest::testMedia(generatedPostBlog.avatars[1], "", "https://64.media.tumblr.com/avatar_a95095bda931_128.png",
	                     128, 128, true, false, false);
	MediaTest::testMedia(generatedPostBlog.avatars[2], "", "https://64.media.tumblr.com/avatar_a95095bda931_96.png",
	                     96, 96, true, false, false);
	MediaTest::testMedia(generatedPostBlog.avatars[3], "", "https://64.media.tumblr.com/avatar_a95095bda931_64.png",
	                     64, 64, true, false, false);

	// Test blog themes.
	ThemeTest::testTheme(generatedPostBlog.theme, "circle", "#FAFAFA", "Helvetica Neue",
	                     "https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/Bx4plw0mr/tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o.jpg",
	                     "https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/VSyplw0ms/tumblr_static_tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o_focused_v3.jpg",
	                     "", "https://static.tumblr.com/7e320b6d491ee3e42460543609b11bb4/rf83rif/Bx4plw0mr/tumblr_static_7wggfrzs5vcwwcso8cwk0kk0o_2048_v2.jpg",
	                     true, "#529ECC", true, true, true,
	                     true, "#444444", "Gibson", "bold");

	PostTest::testPost(generatedPost, Post::photo, "regular", "foxes-in-love", 662456162462154752,
	                   "662456162462154752","", "https://foxes-in-love.tumblr.com/post/662456162462154752",
	                   "", "2021-09-16 04:43:47 GMT",1631767427, Post::none, Post::published,
	                   "DZRk9lQG", std::vector<std::string>(), false, false,"",
	                   "", false, 0,"https://tmblr.co/Zn_LPXanX5woqq00",
	                   "", false, "", "", "",
	                   false, 4973, false, false,true,
	                   false,true);

	// Test blog pointer for generated post.
	BlogTest::testBlog(generatedPost.blog.get(), false, false, "", false, false,
	                   false, "", false, "foxes-in-love", 0, 0,
	                   false,false, "Foxes in Love", 0, 1631767427, "",
	                   "", "https://foxes-in-love.tumblr.com/", "t:bF2JMCXfv_Agp-5ZfJQ75A",
	                   false, false);

	// Test generated post content.
	Image* generatedPostImage = dynamic_cast<Image*>(generatedPost.content[0].get());
	ImageTest::testImage(generatedPostImage, "", "");
	MediaTest::testMedia(generatedPostImage->media[0], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s2048x3072/fc4e3a881144ab9514936342187773381f9e87bb.jpg",
	                     1600, 1600, true, false, true);
	MediaTest::testMedia(generatedPostImage->media[1], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s1280x1920/6edfedea7b49384416c99828a97d0b52ef288d73.jpg",
	                     1280, 1280, true, false, false);
	MediaTest::testMedia(generatedPostImage->media[2], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s640x960/082cb3411fe2de9181aab754124c64b56ae60883.jpg",
	                     640, 640, true, false, false);
	MediaTest::testMedia(generatedPostImage->media[3], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s540x810/4223bb511a9435e79f03ecbee14050978c0d7edf.jpg",
	                     540, 540, true, false, false);
	MediaTest::testMedia(generatedPostImage->media[4], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s500x750/6379a93ce8d5acd37254f184558c70e4ad99cabb.jpg",
	                     500, 500, true, false, false);
	MediaTest::testMedia(generatedPostImage->media[5], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s400x600/7e96093ad6e2e9d293ac3ddcf1845e2fd6816da9.jpg",
	                     400, 400, true, false, false);
	MediaTest::testMedia(generatedPostImage->media[6], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s250x400/01cac1bb8e4253537885edbeaabd9fa5266c53f0.jpg",
	                     250, 250, true, false, false);
	MediaTest::testMedia(generatedPostImage->media[7], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s100x200/024aead13f5ef961e8247cbebb0f4667c905d738.jpg",
	                     100, 100, true, false, false);
	MediaTest::testMedia(generatedPostImage->media[8], "image/jpeg", "https://64.media.tumblr.com/cd7cb9636b5d1ed62a4e2c262b3f27b8/14bdf768bba10f86-29/s75x75_c1/bb0d435b3ddb22b3ccb4d913d24af3d6dc3eae36.jpg",
	                     75, 75, true, true, false);

	// Test generated post trail.
	REQUIRE(generatedPost.trails.empty());

}

TEST_CASE("Empty Post Test", "[Post]") {

	Post emptyPost;

	PostTest::testPost(emptyPost, Post::text, "", "", 0, "", "",
					   "", "", "", 0, Post::none, Post::published, "",
					   std::vector<std::string>(), false, false, "", "", false,
					           0, "", "", false, "",
							   "", "", false, false, false, false,
							   false, false, false);

}
