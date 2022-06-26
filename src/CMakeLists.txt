file(GLOB HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB ATTRIBUTE_HEADERS CONFIGURE_DEPENDS "../include/attributes/*.hpp")
file(GLOB POST_HEADERS CONFIGURE_DEPENDS "../include/posts_types/*.hpp")
file(GLOB LAYOUT_HEADERS CONFIGURE_DEPENDS "../include/layout/*.hpp")

file(GLOB RAPIDJSON_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/rapidjson/*.h" "${PROJECT_SOURCE_DIR}/include/rapidjson/error/*.h" "${PROJECT_SOURCE_DIR}/include/rapidjson/internal/*.h" "${PROJECT_SOURCE_DIR}/include/rapidjson/msinttypes/*.h")

file(GLOB SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(TumblrAPI STATIC ${HEADERS} ${ATTRIBUTE_HEADERS} ${POST_HEADERS} ${CONTENT_HEADERS} ${LAYOUT_HEADERS} ${SOURCES} ${RAPIDJSON_HEADERS})

add_library(TumblrAPI::TumblrAPI ALIAS TumblrAPI)

target_include_directories(TumblrAPI PUBLIC ../include)

target_compile_features(TumblrAPI PUBLIC cxx_std_17)

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})

install(TARGETS TumblrAPI)