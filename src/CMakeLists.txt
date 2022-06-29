file(GLOB HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB ATTRIBUTE_HEADERS CONFIGURE_DEPENDS "../include/attributes/*.hpp")
file(GLOB POST_HEADERS CONFIGURE_DEPENDS "../include/posts/*.hpp")
file(GLOB LAYOUT_HEADERS CONFIGURE_DEPENDS "../include/layout/*.hpp")

file(GLOB SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(TumblrAPI STATIC ${HEADERS} ${ATTRIBUTE_HEADERS} ${POST_HEADERS} ${CONTENT_HEADERS} ${LAYOUT_HEADERS} ${SOURCES})

add_library(TumblrAPI::TumblrAPI ALIAS TumblrAPI)
add_dependencies(TumblrAPI rapidjson)

target_include_directories(TumblrAPI PUBLIC ../include)

target_compile_features(TumblrAPI PUBLIC cxx_std_17)

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})

install(TARGETS TumblrAPI)