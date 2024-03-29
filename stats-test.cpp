#include "stats.h"

#include "ledAlerter.h"
#include "emailAlerter.h"

#include "gtest/gtest.h"
#include <stdlib.h>
#include <math.h>

TEST(Statistics, ReportsAverageMinMax) {
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    struct Stats computedStats = compute_statistics(numberset, setlength);
    float epsilon = 0.001;
    EXPECT_LT(abs(computedStats.average - 4.525), epsilon);
    EXPECT_LT(abs(computedStats.max - 8.9), epsilon);
    EXPECT_LT(abs(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    Stats computedStats = compute_statistics(0, 0);
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the EXPECT statement here.
    //Use https://stackoverflow.com/questions/1923837/how-to-use-nan-and-inf-in-c
    ASSERT_TRUE(isnan(computedStats.average));
}

TEST(Alert, AlertsWhenMaxExceeds) {
    // create additional .c and .h files
    // containing functions called emailAlerter, ledAlerter
    alerter_funcptr alerters[] = {emailAlerter, ledAlerter};

    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    Stats computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerters, computedStats);

    // need a way to check if both emailAlerter, ledAlerter were called
    // you can define call-counters along with the functions, as shown below
    EXPECT_TRUE(emailAlertCallCount);
    EXPECT_TRUE(ledAlertCallCount);
}
