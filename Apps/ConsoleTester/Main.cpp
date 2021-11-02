#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

namespace Faust
{
#include <faust/gui/meta.h>
#include <faust/gui/UI.h>
#include <faust/dsp/dsp.h>
#include <GeneratedDSP/Volume.h>
} // namespace Faust

int main()
{
    Faust::Volume v;

    v.init(44100);

    float channels[2][10];

    for (auto& channel: channels)
    {
        for (auto& sample: channel)
            sample = 0.f;
    }

    auto x = &channels[0][0];

    v.compute(10, &x, &x);

    return 0;
}
