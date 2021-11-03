#include <FaustWrapper.h>

namespace Faust
{
#include <GeneratedDSP/Volume.h>
}

#include <array>

auto getDummyArray()
{
    std::array<std::array<float, 1000>, 1> channels {};

    for (auto& channel: channels)
    {
        for (auto& sample: channel)
            sample = 1.f;
    }

    return channels;
}

int main()
{
    Faust::Module<Faust::Volume> v;

    v.init(44100);
    v.params["1"] = 1.f;

    auto channels = getDummyArray();
    auto x = &channels[0][0];

    v.compute(1000, &x, &x);

    return 0;
}
