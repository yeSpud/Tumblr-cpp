//
// Created by Spud on 7/24/21.
//

#include "blogTest.hpp"
#include <catch2/catch.hpp>
#include "contentTest.hpp"
#include <iostream>

void BlogTest::testBlogInfo(const Blog& blog, const bool &ask, const bool &ask_anon, const std::string& ask_page_title,
                            const bool &ask_allow_media, const bool &can_chat, const bool &can_subscribe, const std::string &description,
                            const bool &is_nsfw, const std::string &name, const unsigned long long &posts, const uint64_t &likes,
                            const bool &shared_likes, const bool &subscribed, const std::string &title, const unsigned long long &total_posts,
                            const uint64_t &updated, const std::string &tz, const std::string &timezone_offset, const std::string &url,
                            const std::string &uuid, const bool &is_blocked_from_primary, const bool &is_optout_ads) {

	std::cout << "\nTesting blog..." << std::endl;

	REQUIRE(blog.ask == ask);
	REQUIRE(blog.ask_anon == ask_anon);
	REQUIRE(blog.ask_page_title == ask_page_title);
	REQUIRE(blog.asks_allow_media == ask_allow_media);
	REQUIRE(blog.can_chat == can_chat);
	REQUIRE(blog.can_subscribe == can_subscribe);
	REQUIRE(blog.description == description);
	REQUIRE(blog.is_nsfw == is_nsfw);
	REQUIRE(blog.name == name);
	REQUIRE(blog.posts == posts);
	REQUIRE(blog.likes == likes);
	REQUIRE(blog.shared_likes == shared_likes);
	REQUIRE(blog.subscribed == subscribed);
	REQUIRE(blog.title == title);
	REQUIRE(blog.total_posts == total_posts);
	REQUIRE(blog.updated == updated);
	REQUIRE(blog.timezone == tz);
	REQUIRE(blog.timezone_offset == timezone_offset);
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
	REQUIRE(blog.url == url);
#pragma clang diagnostic pop
	REQUIRE(blog.uuid == uuid);
	REQUIRE(blog.is_blocked_from_primary == is_blocked_from_primary);
	REQUIRE(blog.is_optout_ads == is_optout_ads);

	// TODO Test Theme...
	std::cout << "Reminder to add theme test" << std::endl;

	std::cout << "Tested blog successfully!\n" << std::endl;
}

void BlogTest::testGetAvatar(const Blog& blog) {

	std::cout << "\nTesting retrieving blog avatar..." << std::endl;

	REQUIRE_THROWS(blog.getAvatar(-1));
	REQUIRE_THROWS(blog.getAvatar(0));
	REQUIRE_THROWS(blog.getAvatar(1));

	std::string returnedAvatar;
	REQUIRE_NOTHROW(returnedAvatar = blog.getAvatar(16));
	REQUIRE(returnedAvatar == "https://64.media.tumblr.com/avatar_fdf0635a9d74_64.png");

	//REQUIRE_NOTHROW(returnedAvatar = this->blog->getAvatar(24));
	//REQUIRE(returnedAvatar != "https://64.media.tumblr.com/avatar_fdf0635a9d74_64.png");
    REQUIRE_NOTHROW(blog.getAvatar(24));


	//REQUIRE_NOTHROW(returnedAvatar = this->blog->getAvatar(30));
    REQUIRE_NOTHROW(blog.getAvatar(30));

	std::cout << "Tested retrieving blog avatar successfully!" << std::endl;

}

void BlogTest::testGetLikes(const Blog& blog) {

    std::cout << "\nTesting retrieving blog likes..." << std::endl;

    //REQUIRE(blogPointer != nullptr);

    if (!blog.shared_likes) {
        std::cout << "Cannot test blog likes on a blog that does not share its likes," << std::endl;
        return;
    }

    REQUIRE_THROWS(blog.getLikes(-1));
    REQUIRE_THROWS(blog.getLikes(0));

    // TODO Test offset, before, and after.
    std::cout << "Reminder to test offset, before, and after parameters." << std::endl;

    Blog::blogLikes blogLikes;
    REQUIRE_NOTHROW(blogLikes = blog.getLikes(1));
    REQUIRE(blogLikes.liked_posts.size() == blogLikes.liked_count);

    // TODO Test other limits.

    std::cout << "Tested retrieving blog likes successfully!" << std::endl;
}

void testPosts(const std::vector<Post> &posts) {
	for (const Post& post : posts) {

		ContentTest::testContent(post.content);

		for (const Trail& trail : post.trail) {

			ContentTest::testContent(trail.content);

		}
	}
}

void BlogTest::testGetPost(const Blog& blog) {

    std::cout << "\nTesting retrieving blog posts..." << std::endl;

    //REQUIRE(blogPointer != nullptr);

    std::vector<Post> defaultPosts = blog.getPosts();
	REQUIRE(defaultPosts.size() == 20);
	testPosts(defaultPosts);

	std::vector<Post> linkPosts = blog.getPosts(Content::postType::link, 0, "", 5);
	REQUIRE(linkPosts.size() == 5);
	testPosts(linkPosts);

	std::vector<Post> videoPosts = blog.getPosts(Content::postType::video, 0, "", 3);
	REQUIRE(videoPosts.size() == 3);
	testPosts(videoPosts);

	std::vector<Post> audioPost = blog.getPosts(Content::postType::audio, 0, "", 2);
	REQUIRE(audioPost.size() == 2);
	testPosts(audioPost);

    std::cout << "Tested retrieving blog posts successfully!" << std::endl;
}

void BlogTest::testGetNotes(const Blog& blog) {

	std::cout << "\nTesting retrieving blog notes..." << std::endl;

	//REQUIRE(blogPointer != nullptr);

	NoteResponse noteResponse = blog.getNotes();

}

// TODO Rest of tests
