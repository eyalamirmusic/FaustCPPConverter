#include <FaustWrapper.h>

namespace Faust
{
#include <GeneratedDSP/Volume.h>
#include <GeneratedDSP/Distortion.h>
} // namespace Faust

#include <array>

constexpr int bufferSize = 1000;
constexpr int sampleRate = 44100;

auto getDummyArray()
{
    std::array<std::array<float, bufferSize>, 1> channels {};

    for (auto& channel: channels)
    {
        for (auto& sample: channel)
            sample = 1.f;
    }

    return channels;
}

int main()
{
    auto channels = getDummyArray();
    auto rawChannelsData = &channels[0][0];

    Faust::Module<Faust::Volume> volume;

    volume.init(sampleRate);
    volume.params["1"] = 1.f;
    volume.compute(bufferSize, &rawChannelsData);

    Faust::Module<Faust::Distortion> distortion;

    distortion.init(sampleRate);
    distortion.params["1"] = 1.f;
    distortion.compute(bufferSize, &rawChannelsData);

    return 0;
}
