#ifndef _STATS_H
#define _STATS_H

#include <math.h>
// define the Stats structure here. See the tests to infer its properties

struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

#endif