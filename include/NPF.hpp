//
// Created by Spud on 7/15/21.
//

#ifndef TUMBLRAPI_NPF_HPP
#define TUMBLRAPI_NPF_HPP

#include "rapidjson/document.h"

class NPF {

public:

	/**
	 * TODO Documentation
	 * @tparam C
	 * @param entry
	 * @return
	 */
	template<class C>
	static virtual C generateNPF(const rapidjson::Value &entry);

};

#endif //TUMBLRAPI_NPF_HPP
