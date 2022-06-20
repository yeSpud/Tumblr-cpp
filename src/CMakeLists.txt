file(GLOB HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB NPF_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/*.hpp")
file(GLOB POST_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/posts_types/*.hpp")
file(GLOB CONTENT_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/content/*.hpp")
file(GLOB LAYOUT_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/layout/*.hpp")

file(GLOB RAPIDJSON_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/rapidjson/*.h" "${PROJECT_SOURCE_DIR}/include/rapidjson/error/*.h" "${PROJECT_SOURCE_DIR}/include/rapidjson/internal/*.h" "${PROJECT_SOURCE_DIR}/include/rapidjson/msinttypes/*.h")

file(GLOB SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB NPF_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/npf/*.cpp")
file(GLOB CONTENT_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/npf/content/*.cpp")
file(GLOB LAYOUT_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/npf/layout/*.cpp")

add_library(TumblrAPI STATIC ${HEADERS} ${NPF_HEADERS} ${POST_HEADERS} ${CONTENT_HEADERS} ${LAYOUT_HEADERS} ${SOURCES} ${NPF_SOURCES} ${CONTENT_SOURCES} ${LAYOUT_SOURCES} ${RAPIDJSON_HEADERS})

add_library(TumblrAPI::TumblrAPI ALIAS TumblrAPI)

target_include_directories(TumblrAPI PUBLIC ../include)

target_compile_features(TumblrAPI PUBLIC cxx_std_17)

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})

install(TARGETS TumblrAPI)