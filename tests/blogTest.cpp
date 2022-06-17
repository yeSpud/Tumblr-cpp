//
// Created by Spud on 7/24/21.
//

#include "blogTest.hpp"
#include "catch2/catch.hpp"
#include <iostream>

void BlogTest::testBlog(const std::string& blogIdentifier, const bool &ask, const bool &ask_anon, const std::string& ask_page_title,
						const bool &ask_allow_media, const bool &can_chat, const bool &can_subscribe, const std::string &description,
						const bool &is_nsfw, const std::string &name, const unsigned long long &posts, const uint64_t &likes,
                        const bool &shared_likes, const bool &subscribed, const std::string &title, const unsigned long long &total_posts,
						const uint64_t &updated, const std::string &tz, const std::string &timezone_offset, const std::string &url,
                        const std::string &uuid, const bool &is_blocked_from_primary, const bool &is_optout_ads) {

	std::cout << "\nTesting blog..." << std::endl;

	std::unique_ptr<Blog> localBlog(new Blog(blogIdentifier, this->tumblrApi));

	REQUIRE(localBlog->ask == ask);
	REQUIRE(localBlog->ask_anon == ask_anon);
	REQUIRE(localBlog->ask_page_title == ask_page_title);
	REQUIRE(localBlog->asks_allow_media == ask_allow_media);
	REQUIRE(localBlog->can_chat == can_chat);
	REQUIRE(localBlog->can_subscribe == can_subscribe);
	REQUIRE(localBlog->description == description);
	REQUIRE(localBlog->is_nsfw == is_nsfw);
	REQUIRE(localBlog->name == name);
	REQUIRE(localBlog->posts == posts);
	REQUIRE(localBlog->likes == likes);
	REQUIRE(localBlog->shared_likes == shared_likes);
	REQUIRE(localBlog->subscribed == subscribed);
	REQUIRE(localBlog->title == title);
	REQUIRE(localBlog->total_posts == total_posts);
	REQUIRE(localBlog->updated == updated);
	REQUIRE(localBlog->timezone == tz);
	REQUIRE(localBlog->timezone_offset == timezone_offset);
	REQUIRE(localBlog->url == url);
	REQUIRE(localBlog->uuid == uuid);
	REQUIRE(localBlog->is_blocked_from_primary == is_blocked_from_primary);
	REQUIRE(localBlog->is_optout_ads == is_optout_ads);

	// TODO Test Theme...
	std::cout << "Reminder to add theme test" << std::endl;

	this->blog = std::move(localBlog);
	std::cout << "Tested blog successfully!\n" << std::endl;
}

void BlogTest::testGetAvatar() {

	std::cout << "\nTesting retrieving blog avatar..." << std::endl;

	REQUIRE(this->blog != nullptr);
	REQUIRE_THROWS(this->blog->getAvatar(-1));
	REQUIRE_THROWS(this->blog->getAvatar(0));
	REQUIRE_THROWS(this->blog->getAvatar(1));

	std::string returnedAvatar;
	REQUIRE_NOTHROW(returnedAvatar = this->blog->getAvatar(16));
	REQUIRE(returnedAvatar == "https://64.media.tumblr.com/avatar_fdf0635a9d74_64.png");

	//REQUIRE_NOTHROW(returnedAvatar = this->blog->getAvatar(24));
	//REQUIRE(returnedAvatar != "https://64.media.tumblr.com/avatar_fdf0635a9d74_64.png");
    REQUIRE_NOTHROW(this->blog->getAvatar(24));


	//REQUIRE_NOTHROW(returnedAvatar = this->blog->getAvatar(30));
    REQUIRE_NOTHROW(this->blog->getAvatar(30));

	std::cout << "Tested retrieving blog avatar successfully!" << std::endl;

}

void BlogTest::testGetLikes() {

    std::cout << "\nTesting retrieving blog likes..." << std::endl;

    REQUIRE(this->blog != nullptr);

    if (!this->blog->shared_likes) {
        std::cout << "Cannot test blog likes on a blog that does not share its likes," << std::endl;
        return;
    }

    REQUIRE_THROWS(this->blog->getLikes(-1));
    REQUIRE_THROWS(this->blog->getLikes(0));

    // TODO Test offset, before, and after.
    std::cout << "Reminder to test offset, before, and after parameters." << std::endl;

    Blog::blogLikes blogLikes;
    REQUIRE_NOTHROW(blogLikes = this->blog->getLikes(1));
    REQUIRE(blogLikes.liked_posts.size() == blogLikes.liked_count);

    // TODO Test other limits.

    std::cout << "Tested retrieving blog likes successfully!" << std::endl;
}

// TODO Rest of tests
