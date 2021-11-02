include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

CPMAddPackage(
        NAME Faust
        GITHUB_REPOSITORY grame-cncm/faust
        GIT_TAG origin/master
        GIT_SHALLOW TRUE)

