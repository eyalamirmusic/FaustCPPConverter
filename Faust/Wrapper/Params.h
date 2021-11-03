#pragma once

#include "UIWrapper.h"

namespace Faust
{
struct Params : UIWrapper
{
    void declare(float* zone, const char* key, const char* val) override
    {
        values[key] = zone;
    }

    float& operator[](const std::string& key) { return *values[key]; }

    std::map<std::string, float*> values;
};
} // namespace Faust