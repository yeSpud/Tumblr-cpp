find_path(TUMBLRAPI_INCLUDE_DIR NAMES TumblrAPI.hpp)
find_path(TUMBLRAPI_LIBRARY NAMES TumblrAPI HINTS ${TUMBLR_LIBRARY_ROOT})
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TumblrAPI REQUIRED_VARS TUMBLRAPI_LIBRARY TUMBLRAPI_INCLUDE_DIR)

if (TUMBLRAPI_FOUND)
    set(TUMBLRAPI_LIBRARIES ${TUMBLRAPI_LIBRARY})
    set(TUMBLRAPI_INCLUDE_DIRS ${TUMBLRAPI_INCLUDE_DIR})
endif()