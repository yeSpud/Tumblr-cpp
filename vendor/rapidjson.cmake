# Download RapidJSON
ExternalProject_Add(
        rapidjson
        PREFIX "vendor/rapidjson"
        GIT_REPOSITORY "https://github.com/Tencent/rapidjson.git"
        GIT_TAG origin/master
        TIMEOUT 10
        CMAKE_ARGS
            -DRAPIDJSON_BUILD_TESTS=OFF
            -DRAPIDJSON_BUILD_DOC=OFF
            -DRAPIDJSON_BUILD_EXAMPLES=OFF
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        UPDATE_COMMAND ""
)

# Prepare RapidJSON
ExternalProject_Get_property(rapidjson source_dir)
set(RAPIDJSON_INCLUDE_DIR ${source_dir}/include)