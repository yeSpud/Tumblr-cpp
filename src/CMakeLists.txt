file(GLOB HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB NPF_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/*.hpp")
file(GLOB CONTENT_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/content/*.hpp")
file(GLOB LAYOUT_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/npf/layout/*.hpp")


file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(TumblrAPI STATIC ${HEADERS} ${NPF_HEADERS} ${CONTENT_HEADERS} ${LAYOUT_HEADERS} ${SOURCE_LIST})

target_include_directories(TumblrAPI PUBLIC ../include)

#target_link_libraries()

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST})
