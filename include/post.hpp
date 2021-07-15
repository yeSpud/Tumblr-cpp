//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_POST_HPP
#define TUMBLRAPI_POST_HPP

class post {

public:

	/**
	 * TODO Documentation
	 */
	struct Post;

	/**
	 * TODO Documentation
	 * @param json
	 * @return
	 */
	static std::vector<Post> generatePosts(const char *json);

};

#endif //TUMBLRAPI_POST_HPP
