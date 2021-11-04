project(ConsoleTester)

add_executable(ConsoleTester Main.cpp)

compileFaustDSP(ConsoleTester ${Faust_SOURCE_DIR}/examples/dynamic/volume.dsp Volume)
compileFaustDSP(ConsoleTester ${Faust_SOURCE_DIR}/examples/dynamic/distortion.dsp Distortion)
