//
// Created by Sud on 6/17/22.
//

#include "npf/abstract_post.hpp"

bool Post::operator==(const Post &post) const {

    bool postTypeCheck = this->type == post.type;
    //bool originalTypeCheck = this->original_type == post.original_type;
    bool blogNameCheck = this->blog_name == post.blog_name;
    //bool blogCheck;
    bool idCheck = this->id == post.id;
    bool idStringCheck = this->id_string == post.id_string;
    bool genesisPostIdCheck = this->genesis_post_id == post.genesis_post_id;
    bool postUrlCheck = this->post_url == post.post_url;
    //bool slugCheck = this->slug == post.slug;
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
    //bool shortUrlCheck = this->short_url == post.short_url;
    //bool postAuthorCheck = this->post_author == post.post_author;
    //bool isSubmissionCheck = this->is_submission == post.is_submission;
    //bool anonymousNameCheck = this->anonymous_name == post.anonymous_name;
    //bool anonymousEmailCheck = this->anonymous_email == post.anonymous_email;
    //bool summaryCheck = this->summary == post.summary;
    //bool shouldOpenInLegacyCheck = this->should_open_in_legacy == post.should_open_in_legacy;
    //bool noteCountCheck = this->note_count == post.note_count;
    //bool contentCheck;
    //bool layoutCheck;
    //bool trailsCheck;
    //bool canLikeCheck;
    //bool canReblogCheck;
    //bool canSendInMessageCheck;
    //bool canReplyCheck;
    //bool displayAvatarCheck;

    return postTypeCheck && blogNameCheck && idCheck && idStringCheck && genesisPostIdCheck && postUrlCheck && dateCheck
    && timestampCheck && formatCheck && reblogKeyCheck && bookmarkletCheck && mobileCheck && sourceUrlCheck &&
    sourceTitleCheck && totalPostsCheck;
    /*return postTypeCheck && originalTypeCheck && blogNameCheck && idCheck && idStringCheck && genesisPostIdCheck
           && postUrlCheck && slugCheck && dateCheck && timestampCheck && formatCheck && reblogKeyCheck && bookmarkletCheck
           && mobileCheck && sourceUrlCheck && sourceTitleCheck && totalPostsCheck && shortUrlCheck && postAuthorCheck &&
           isSubmissionCheck && anonymousNameCheck && anonymousEmailCheck && summaryCheck && shouldOpenInLegacyCheck;*/

}

bool Post::operator!=(const Post &post) const {

    bool postTypeCheck = this->type != post.type;
    //bool originalTypeCheck = this->original_type != post.original_type;
    bool blogNameCheck = this->blog_name != post.blog_name;
    //bool blogCheck;
    bool idCheck = this->id != post.id;
    bool idStringCheck = this->id_string != post.id_string;
    bool genesisPostIdCheck = this->genesis_post_id != post.genesis_post_id;
    bool postUrlCheck = this->post_url != post.post_url;
    //bool slugCheck = this->slug != post.slug;
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
    //bool shortUrlCheck = this->short_url != post.short_url;
    //bool postAuthorCheck = this->post_author != post.post_author;
    //bool isSubmissionCheck = this->is_submission != post.is_submission;
    //bool anonymousNameCheck = this->anonymous_name != post.anonymous_name;
    //bool anonymousEmailCheck = this->anonymous_email != post.anonymous_email;
    //bool summaryCheck = this->summary != post.summary;
    //bool shouldOpenInLegacyCheck = this->should_open_in_legacy != post.should_open_in_legacy;
    //bool noteCountCheck = this->note_count != post.note_count;
    //bool contentCheck;
    //bool layoutCheck;
    //bool trailsCheck;
    //bool canLikeCheck;
    //bool canReblogCheck;
    //bool canSendInMessageCheck;
    //bool canReplyCheck;
    //bool displayAvatarCheck;

    return postTypeCheck && blogNameCheck && idCheck && idStringCheck && genesisPostIdCheck && postUrlCheck && dateCheck
    && timestampCheck && formatCheck && reblogKeyCheck && bookmarkletCheck && mobileCheck && sourceUrlCheck &&
    sourceTitleCheck && totalPostsCheck;
    /*return postTypeCheck && originalTypeCheck && blogNameCheck && idCheck && idStringCheck && genesisPostIdCheck
           && postUrlCheck && slugCheck && dateCheck && timestampCheck && formatCheck && reblogKeyCheck && bookmarkletCheck
           && mobileCheck && sourceUrlCheck && sourceTitleCheck && totalPostsCheck && shortUrlCheck && postAuthorCheck &&
           isSubmissionCheck && anonymousNameCheck && anonymousEmailCheck && summaryCheck && shouldOpenInLegacyCheck;*/

}