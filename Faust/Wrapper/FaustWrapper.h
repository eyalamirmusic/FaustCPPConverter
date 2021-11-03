#pragma once

#include "Params.h"

namespace Faust
{
template <typename ModuleType>
struct Module
{
    Module() { module.buildUserInterface(&params); }

    void init(int sampleRate) { module.init(sampleRate); }
    void compute(int count, float** inputs, float** outputs) noexcept
    {
        module.compute(count, inputs, outputs);
    }

    Params params;
    ModuleType module;
};
} // namespace Faust
