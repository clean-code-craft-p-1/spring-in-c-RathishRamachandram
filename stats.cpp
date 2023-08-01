#include "stats.h"
#include "ledAlerter.h"
#include "emailAlerter.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int counter = 0;
    float sum = 0;

    s.average = 0;
    s.min = 0;
    s.max = 0;

    if (numberset != NULL && setlength != 0)
    {
        float min = numberset[counter];
        float max = numberset[counter];

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
    }

    return s;
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if (computedStats.average > maxThreshold)
    {

    }
}
