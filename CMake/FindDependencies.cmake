include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

CPMAddPackage(
        NAME Faust
        GITHUB_REPOSITORY grame-cncm/faust
        GIT_TAG origin/master
        GIT_SHALLOW TRUE)

option(LIBMICROHTTPD_CFLAGS "Manual C flags for libmicrohttpd" ON)
option(LIBMICROHTTPD_LDFLAGS "Manual link flags for libmicrohttpd" ON)
option(INCLUDE_WASM_GLUE "" OFF)
option(INCLUDE_OSC "" OFF)
option(INCLUDE_HTTP "" OFF)
option(INCLUDE_ITP "" OFF)
option(INCLUDE_EMCC "" OFF)

set(CPP_BACKEND COMPILER STATIC DYNAMIC CACHE STRING "Include CPP backend" FORCE)

add_subdirectory(${Faust_SOURCE_DIR}/build)