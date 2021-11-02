cmake_minimum_required(VERSION 3.17)
project(FaustCPPConverter)
set(CMAKE_CXX_STANDARD 17)

include(CMake/FindDependencies.cmake)

option(LIBMICROHTTPD_CFLAGS "Manual C flags for libmicrohttpd" ON)
option(LIBMICROHTTPD_LDFLAGS "Manual link flags for libmicrohttpd" ON)
option(INCLUDE_WASM_GLUE "" OFF)
option(INCLUDE_OSC "" OFF)
option(INCLUDE_HTTP "" OFF)
option(INCLUDE_ITP "" OFF)
option(INCLUDE_EMCC "" OFF)

set(CPP_BACKEND COMPILER STATIC DYNAMIC CACHE STRING "Include CPP backend" FORCE)

add_subdirectory(${Faust_SOURCE_DIR}/build)

#add_library(FaustEngine STATIC)

function(compileFaustDSP target fileName classname)
    set(generatedDir ${CMAKE_CURRENT_BINARY_DIR}/FaustGenerated)
    set(faustDir ${generatedDir}/GeneratedDSP)
    set(outFileName ${faustDir}/${classname}.h)

    file(MAKE_DIRECTORY ${faustDir})
    target_include_directories(${target} PRIVATE ${generatedDir})
    target_include_directories(${target} PRIVATE ${Faust_SOURCE_DIR}/architecture)

    add_custom_command(
            OUTPUT ${outFileName}
            COMMAND faust ${fileName}
            -I ${Faust_SOURCE_DIR}/libraries
            -o ${outFileName}
            -cn ${classname}
            DEPENDS ${fileName})

    target_sources(${target} PRIVATE ${outFileName})
endfunction()

add_subdirectory(Apps)



