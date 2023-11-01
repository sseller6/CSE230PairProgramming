
#include ""physics.h"

// Linear Interpolation
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
    // off the scale on the small end
    if (domain < mapping[0].domain)
        return mapping[0].range;

    // within the table
    for (int i = 0; i < numMapping - 1; i++)
    {
        // the domain must be in order
        assert(mapping[i + 0].domain < mapping[i + 1].domain);
        if (mapping[i + 0].domain <= domain && domain <= mapping[i + 1].domain)
            return linearInterpolation(mapping[i + 0], mapping[i + 1], domain);
    }
    // off the scale on the large end
    return mapping[numMapping - 1].range;
}