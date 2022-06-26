//
// Created by Spud on 6/25/22.
//

#ifndef TUMBLRAPI_CONTENTTEST_HPP
#define TUMBLRAPI_CONTENTTEST_HPP

#include <vector>
#include <memory>
#include "posts_types/content.hpp"

class ContentTest {

public:

	static void testContent(const std::vector<std::shared_ptr<Content>>& content);

};


#endif //TUMBLRAPI_CONTENTTEST_HPP
