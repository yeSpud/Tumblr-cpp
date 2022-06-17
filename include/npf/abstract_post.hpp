//
// Created by Spud on 6/16/22.
//

#ifndef TUMBLRAPI_ABSTRACT_POST_HPP
#define TUMBLRAPI_ABSTRACT_POST_HPP

class Post {

public:

    /**
	 * TODO Documentation
	 */
    enum postType {

        /**
         * TODO Documentation
         */
        text,

        /**
         * TODO Documentation
         */
        quote,

        /**
         * TODO Documentation
         */
        link,

        /**
         * TODO Documentation
         */
        answer,

        /**
         * TODO Documentation
         */
        video,

        /**
         * TODO Documentation
         */
        audio,

        /**
         * TODO Documentation
         */
        photo,

        /**
         * TODO Documentation
         */
        chat
    };

    /**
	 * TODO Documentation
	 */
    enum postFormat {

        /**
         * TODO Documentation
         */
        html,

        /**
         * TODO Documentation
         */
        markdown,

        /**
         * Used if there is no post format provided.
         */
        none

    };

    /**
	 * TODO Documentation
	 */
    enum postState {

        /**
         * TODO Documentation
         */
        published,

        /**
         * TODO Documentation
         */
        queued,

        /**
         * TODO Documentation
         */
        draft,

        /**
         * TODO Documentation
         */
        privat
    };

    /**
     * The short name used to uniquely identify a blog.
     */
    std::string blog_name;

    /**
     * The post's unique ID.
     */
    long long id;

    /**
     * The post's unique ID as a string.
     * For clients that don't support 64-bit integers.
     */
    std::string id_string;

    /**
     * The post's unique "genesis" ID as a string. Only available to the post owner in certain circumstances.
     * <br>
     * The "genesis" ID for a post is only available and different than its current ID if that post had been drafted,
     * queued, or scheduled, and is now published.
     * In which case, the "genesis" ID will be the original post ID generated when drafting, queuing, or scheduling that post.
     * You cannot use this ID to look up the post after it has been published,
     * but it can be useful for tracking a post from its pre- to post-published state.
     */
    std::string genesis_post_id;

    /**
     * The location of the post.
     */
    std::string post_url;

    /**
     * The type of post.
     */
    const postType type;

    /**
     * The time of the post, in seconds since the epoch.
     */
    long long timestamp;

    /**
     * The GMT date and time of the post, as a string.
     */
    std::string date;

    /**
     * The post format: html or markdown.
     */
    postFormat format;

    /**
     * The key used to reblog this post.
     */
    std::string reblog_key;

    /**
     * Tags applied to the post.
     */
    std::string tags;

    /**
     * Indicates whether the post was created via the Tumblr bookmark. Exists only if true.
     */
    bool bookmarklet = false;

    /**
     * Indicates whether the post was created via mobile/email publishing. Exists only if true.
     */
    bool mobile = false;

    /**
     * The URL for the source of the content (for quotes, reblogs, etc.). Exists only of there's a content source.
     */
    std::string source_url;

    /**
     * The title of the source site. Exists only if there's a content source.
     */
    std::string source_title;

    /**
     * Indicates if a user has already liked a post or not. Exists nly if the request is fully authenticated with OAuth.
     */
    bool liked = false;

    /**
     * Indicates the current state of the post. States are published, queued, draft and private.
     */
    postState state;

    /**
     * The total number of post available for this request, useful for paginating though results.
     */
    unsigned long long total_posts;

    // auto content; FIXME

    // auto layout; FIXME

    // auto trail; FIXME

};

#endif //TUMBLRAPI_ABSTRACT_POST_HPP
