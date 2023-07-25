#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int counter = 0;
    float sum = 0;
    float min = numberset[counter];
    float max = numberset[counter];

    s.average = 0;
    s.min = 0;
    s.max = 0;

    if (numberset != NULL && setlength != 0)
    {
        for (counter = 0; counter < setlength; counter++)
        {
            sum += numberset[counter];

            if (numberset[counter] < min)
            {
                min = numberset[counter];
            }

            if (numberset[counter] > max)
            {
                max = numberset[counter];
            }
        }

        s.average = (float)sum / setlength;
        s.min = min;
        s.max = max;
    }
    else
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
    }

    return s;
}
