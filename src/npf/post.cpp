//
// Created by Spud on 6/17/22.
//

#include "npf/post.hpp"
#include "npf/layout/condensed.hpp"
#include "npf/layout/ask.hpp"
#include "npf/layout/carousel.hpp"

bool Post::operator==(const Post &post) const {

    bool postTypeCheck = this->type == post.type;
    bool originalTypeCheck = this->original_type == post.original_type;
    bool blogNameCheck = this->blog_name == post.blog_name;
	bool blogCheck;
    bool idCheck = this->id == post.id;
    bool idStringCheck = this->id_string == post.id_string;
    bool genesisPostIdCheck = this->genesis_post_id == post.genesis_post_id;
    bool postUrlCheck = this->post_url == post.post_url;
    bool slugCheck = this->slug == post.slug;
    bool dateCheck = this->date == post.date;
    bool timestampCheck = this->timestamp == post.timestamp;
    bool formatCheck = this->format == post.format;
    //bool stateCheck;
    bool reblogKeyCheck = this->reblog_key == post.reblog_key;
    //bool tagsCheck;
    bool bookmarkletCheck = this->bookmarklet == post.bookmarklet;
    bool mobileCheck = this->mobile == post.mobile;
    bool sourceUrlCheck = this->source_url == post.source_url;
    bool sourceTitleCheck = this->source_title == post.source_title;
    //bool likedCheck;
    bool totalPostsCheck = this->total_posts == post.total_posts;
    bool shortUrlCheck = this->short_url == post.short_url;
    //bool postAuthorCheck = this->post_author == post.post_author;
    //bool isSubmissionCheck = this->is_submission == post.is_submission;
    //bool anonymousNameCheck = this->anonymous_name == post.anonymous_name;
    //bool anonymousEmailCheck = this->anonymous_email == post.anonymous_email;
    bool summaryCheck = this->summary == post.summary;
    bool shouldOpenInLegacyCheck = this->should_open_in_legacy == post.should_open_in_legacy;
    //bool noteCountCheck;
    //bool contentCheck;
    //bool layoutCheck;
    //bool trailsCheck;
    //bool canLikeCheck;
    //bool canReblogCheck;
    //bool canSendInMessageCheck;
    //bool canReplyCheck;
    //bool displayAvatarCheck;


	/*return postTypeCheck && originalTypeCheck && blogNameCheck && idCheck && idStringCheck && genesisPostIdCheck
	       && postUrlCheck && slugCheck && dateCheck && timestampCheck && formatCheck && reblogKeyCheck && bookmarkletCheck
	       && mobileCheck && sourceUrlCheck && sourceTitleCheck && totalPostsCheck && shortUrlCheck && postAuthorCheck &&
	       isSubmissionCheck && anonymousNameCheck && anonymousEmailCheck && summaryCheck && shouldOpenInLegacyCheck;*/
    return postTypeCheck && originalTypeCheck && blogNameCheck && idCheck && idStringCheck && genesisPostIdCheck
           && postUrlCheck && slugCheck && dateCheck && timestampCheck && formatCheck && reblogKeyCheck && bookmarkletCheck
           && mobileCheck && sourceUrlCheck && sourceTitleCheck && totalPostsCheck && shortUrlCheck && summaryCheck &&
		   shouldOpenInLegacyCheck;

}

bool Post::operator!=(const Post &post) const {

	bool postTypeCheck = this->type != post.type;
	bool originalTypeCheck = this->original_type != post.original_type;
	bool blogNameCheck = this->blog_name != post.blog_name;
	bool blogCheck;
	bool idCheck = this->id != post.id;
	bool idStringCheck = this->id_string != post.id_string;
	bool genesisPostIdCheck = this->genesis_post_id != post.genesis_post_id;
	bool postUrlCheck = this->post_url != post.post_url;
	bool slugCheck = this->slug != post.slug;
	bool dateCheck = this->date != post.date;
	bool timestampCheck = this->timestamp != post.timestamp;
	bool formatCheck = this->format != post.format;
	//bool stateCheck;
	bool reblogKeyCheck = this->reblog_key != post.reblog_key;
	//bool tagsCheck;
	bool bookmarkletCheck = this->bookmarklet != post.bookmarklet;
	bool mobileCheck = this->mobile != post.mobile;
	bool sourceUrlCheck = this->source_url != post.source_url;
	bool sourceTitleCheck = this->source_title != post.source_title;
	//bool likedCheck;
	bool totalPostsCheck = this->total_posts != post.total_posts;
	bool shortUrlCheck = this->short_url != post.short_url;
	//bool postAuthorCheck = this->post_author != post.post_author;
	//bool isSubmissionCheck = this->is_submission != post.is_submission;
	//bool anonymousNameCheck = this->anonymous_name != post.anonymous_name;
	//bool anonymousEmailCheck = this->anonymous_email != post.anonymous_email;
	bool summaryCheck = this->summary != post.summary;
	bool shouldOpenInLegacyCheck = this->should_open_in_legacy != post.should_open_in_legacy;
	bool noteCountCheck = this->note_count != post.note_count;
	//bool contentCheck;
	//bool layoutCheck;
	//bool trailsCheck;
	//bool canLikeCheck;
	//bool canReblogCheck;
	//bool canSendInMessageCheck;
	//bool canReplyCheck;
	//bool displayAvatarCheck;

	/*return postTypeCheck && originalTypeCheck && blogNameCheck && idCheck && idStringCheck && genesisPostIdCheck
		   && postUrlCheck && slugCheck && dateCheck && timestampCheck && formatCheck && reblogKeyCheck && bookmarkletCheck
		   && mobileCheck && sourceUrlCheck && sourceTitleCheck && totalPostsCheck && shortUrlCheck && postAuthorCheck &&
		   isSubmissionCheck && anonymousNameCheck && anonymousEmailCheck && summaryCheck && shouldOpenInLegacyCheck;*/
	return postTypeCheck && originalTypeCheck && blogNameCheck && idCheck && idStringCheck && genesisPostIdCheck
	       && postUrlCheck && slugCheck && dateCheck && timestampCheck && formatCheck && reblogKeyCheck && bookmarkletCheck
	       && mobileCheck && sourceUrlCheck && sourceTitleCheck && totalPostsCheck && shortUrlCheck && summaryCheck &&
		   shouldOpenInLegacyCheck;
}

void Post::populateContent(const rapidjson::GenericArray<true, rapidjson::Value>& contentJsonArray) {

	for (const rapidjson::Value &contentEntry : contentJsonArray) {

		if (contentEntry.IsObject()) {
			rapidjson::GenericObject entryObject = contentEntry.GetObj();

			std::string contentTypeString;
			TumblrAPI::setStringFromJson(entryObject, "type", contentTypeString);

			// TODO Change each of the post class types.
			if (contentTypeString == "text" || contentTypeString == "answer" || contentTypeString == "chat" || contentTypeString == "quote") {

				std::string text;
				TumblrAPI::setStringFromJson(entryObject, "text", text);

				Text textPost = Text(entryObject, text);
				this->content.push_back(std::make_shared<Text>(textPost));
			} else if (contentTypeString == "link") {

				std::string urlString;
				TumblrAPI::setStringFromJson(entryObject, "url", urlString);

				Link linkPost = Link(entryObject, urlString);
				this->content.push_back(std::make_shared<Link>(linkPost));
			} else if (contentTypeString == "video") {

				Video videoPost = Video(entryObject);
				this->content.push_back(std::make_shared<Video>(videoPost));
			} else if (contentTypeString == "audio") {

				Audio audioPost = Audio(entryObject);
				this->content.push_back(std::make_shared<Audio>(audioPost));
			} else if (contentTypeString == "image") {
				Image imagePost = Image(entryObject);
				this->content.push_back(std::make_shared<Image>(imagePost));
			} else { // TODO Add paywall post
				spdlog::get("TumblrAPI Logger")->warn("Unable to recognize content type {}", contentTypeString);
			}
		}
	}
}

void Post::populateLayout(const rapidjson::GenericArray<true, rapidjson::Value> &layoutJsonArray) {

	for (const rapidjson::Value& layoutEntry : layoutJsonArray) {

		if (layoutEntry.IsObject()) {
			rapidjson::GenericObject entryObject = layoutEntry.GetObj();

			std::string layoutTypeString;
			TumblrAPI::setStringFromJson(entryObject, "type", layoutTypeString);

			if (layoutTypeString == "rows") {

				// Having "truncate_after" signifies a carousel layout.
				// TODO Also check for mode of carousel
				if (entryObject.HasMember("truncate_after")) {
					Carousel carouselLayout = Carousel(entryObject);
					this->layout.push_back(std::make_shared<Carousel>(carouselLayout));
				} else {
					Rows rowsLayout = Rows(entryObject);
					this->layout.push_back(std::make_shared<Rows>(rowsLayout));
				}
			} else if (layoutTypeString == "condensed") {
				Condensed contentLayout = Condensed(entryObject);
				this->layout.push_back(std::make_shared<Condensed>(contentLayout));
			} else if (layoutTypeString == "ask") {
				Ask askLayout = Ask(entryObject);
				this->layout.push_back(std::make_shared<Ask>(askLayout));
			} else {
				spdlog::get("TumblrAPI Logger")->warn("Unable to recognize layout type {}", layoutTypeString);
			}
		}
	}
}
