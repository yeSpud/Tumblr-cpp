//
// Created by Spud on 7/22/21.
//

#ifndef TUMBLRAPI_AUDIOTEST_HPP
#define TUMBLRAPI_AUDIOTEST_HPP

#include "npf/content/audio.hpp"

/**
 * TODO Documentation
 */
class AudioTest {

public:

	/**
	 * TODO Documentation
	 * @param audio
	 * @param url
	 * @param provider
	 * @param title
	 * @param artist
	 * @param album
	 * @param embed_html
	 * @param embed_url
	 */
	static void
	testAudio(const Audio &audio, const std::string &url, const std::string &provider, const std::string &title,
	          const std::string &artist, const std::string &album, const std::string &embed_html,
	          const std::string &embed_url);


};

#endif //TUMBLRAPI_AUDIOTEST_HPP
