add_subdirectory(Wrapper)

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

    target_link_libraries(${target} PRIVATE FaustWrapper)
endfunction()