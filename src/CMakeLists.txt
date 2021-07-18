file(GLOB HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB NPF_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/*.hpp")
file(GLOB CONTENT_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/content/*.hpp")
file(GLOB LAYOUT_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/layout/*.hpp")

file(GLOB SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB NPF_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/npf/*.cpp")
file(GLOB CONTENT_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/npf/content/*.cpp")
file(GLOB LAYOUT_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/npf/layout/*.cpp")

add_library(TumblrAPI STATIC ${HEADERS} ${NPF_HEADERS} ${CONTENT_HEADERS} ${LAYOUT_HEADERS} ${SOURCES} ${NPF_SOURCES} ${CONTENT_SOURCES} ${LAYOUT_SOURCES})

target_include_directories(TumblrAPI PUBLIC ../include)

#target_link_libraries()

target_compile_features(TumblrAPI PUBLIC cxx_std_11)

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})
