#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cmath>
#include <map>

namespace Faust
{
#include <faust/gui/meta.h>
#include <faust/gui/UI.h>
#include <faust/dsp/dsp.h>

//A dummy wrapper needed to satisfy the requirement for a UI
struct UIWrapper : UI
{
    void openTabBox(const char*) override {}
    void openHorizontalBox(const char*) override {}
    void openVerticalBox(const char*) override {}
    void closeBox() override {}
    void addButton(const char*, float*) override {}
    void addCheckButton(const char*, float*) override {}
    void addVerticalSlider(const char*, float*, float, float, float, float) override
    {
    }
    void
        addHorizontalSlider(const char*, float*, float, float, float, float) override
    {
    }
    void addNumEntry(const char*, float*, float, float, float, float) override {}
    void addHorizontalBargraph(const char*, float*, float, float) override {}
    void addVerticalBargraph(const char*, float*, float, float) override {}
    void addSoundfile(const char*, const char*, Faust::Soundfile**) override {}
};
} // namespace Faust
