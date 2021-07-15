//
// Created by Spud on 7/14/21.
//

#ifndef TUMBLRAPI_AUDIO_HPP
#define TUMBLRAPI_AUDIO_HPP

class audio {

public:

	/**
	 * TODO Documentation
	 */
	struct Audio;

	/**
	 * TODO Documentation
	 * @param entry
	 * @return
	 */
	static Audio generateAudio(const rapidjson::Value &entry);


};

#endif //TUMBLRAPI_AUDIO_HPP
