//
//  test_EpochTime.c
//  EpochTime
//
//  Created by Nidhi Galgali on 3/30/23.
//  Used: https://www.epochconverter.com/ and https://www.epoch101.com/ to verify results
//

#include "test_EpochTime.h"
#include "EpochTime.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>
void test_someTime_lessThanZero(void);
void test_someTime_equalToZero(void);
void test_HMS_NULLPointers(void);
void test_time_now(void);
void test_random_time(void);
void test_leap_time(void);
void test_max_time(void);
void test_dayOfweek_zerotime(void);
void test_dayOfweek_current(void);
void test_dayOfweek_random(void);
void test_leap_day(void);
void test_getEpoch_invalid(void);
void test_getEpoch_leap(void);
void test_getEpoch_random(void);
void test_startEpoch_random(void);

// TEST CASE 1:
void test_someTime_lessThanZero() {
int hour, min, sec;
time_t someTime = -1;
int result = getHMS(someTime, &hour, &min, &sec);
assert(result == -1 && "Test Case 1 Failed");
printf("Test Case 1 Passed\n");
}

// TEST CASE 2:
void test_someTime_equalToZero() {
int hour, min, sec;
time_t someTime = 0;
getHMS(someTime, &hour, &min, &sec);
assert(hour == 0 && min == 0 && sec == 0 && "Test Case 2 Failed");
printf("Test Case 2 Passed\n");
}

// TEST CASE 3:
void test_HMS_NULLPointers() {
time_t someTime = time(NULL);
int result = getHMS(someTime, NULL, NULL, NULL);
assert(result == -1 && "Test Case 3 Failed");
printf("Test Case 3 Passed\n");

}

// TEST CASE 4:
void test_time_now() {
    time_t now = time(NULL);
    struct tm* timenow = gmtime(&now);
    int expected_h = timenow->tm_hour;
    int expected_m = timenow->tm_min;
    int expected_s = timenow->tm_sec;

    int h, m, s;
    getHMS(now, &h, &m, &s);

    assert(h == expected_h && m == expected_m && s == expected_s && "Test Case 4 Failed");
    printf("Test Case 4 Passed\n");
}

// TEST CASE 5:
void test_random_time() {
    time_t now = 951745975;// corresponds to Monday, 28 February 2000 1:52:55 PM GMT
    
    struct tm* time_random = gmtime(&now);
    int expected_h = time_random->tm_hour;
    int expected_m = time_random->tm_min;
    int expected_s = time_random->tm_sec;

    int h, m, s;
    getHMS(now, &h, &m, &s);

    assert(h == expected_h && m == expected_m && s == expected_s && "Test Case 5 Failed");
    printf("Test Case 5 Passed\n");
}

// TEST CASE 6:
void test_leap_time() {
    time_t now = 951835975;// corresponds to Tuesday, 29 February 2000 2:52:55 PM GMT
    
    struct tm* time_random = gmtime(&now);
    int expected_h = time_random->tm_hour;
    int expected_m = time_random->tm_min;
    int expected_s = time_random->tm_sec;

    int h, m, s;
    getHMS(now, &h, &m, &s);

    assert(h == expected_h && m == expected_m && s == expected_s && "Test Case 6 Failed");
    printf("Test Case 6 Passed\n");
}

// TEST CASE 7:
void test_max_time() {
    time_t now = 2147483647;// maximum number of seconds that can be stored in time_t
    // corresponds to Tuesday, 19 January 2038 3:14:07 AM GMT
    
    struct tm* time_random = gmtime(&now);
    int expected_h = time_random->tm_hour;
    int expected_m = time_random->tm_min;
    int expected_s = time_random->tm_sec;

    int h, m, s;
    getHMS(now, &h, &m, &s);

    assert(h == expected_h && m == expected_m && s == expected_s && "Test Case 7 Failed");
    printf("Test Case 7 Passed\n");
}

// TEST CASE 8:
void test_dayOfweek_zerotime() {
time_t curTime = 0;// Thursday(Day 4) January 1 1970
int result = getDayOfWeek(curTime);
assert(result == 4 && "Test Case 8 Failed");
printf("Test Case 8 Passed\n");
}

// TEST CASE 9:
void test_dayOfweek_current() {
time_t curTime = time(NULL);
int result = getDayOfWeek(curTime);
int expected_day = localtime(&curTime)->tm_wday;
assert(result == expected_day && "Test Case 9 Failed");
printf("Test Case 9 Passed\n");
}

// TEST CASE 10:
void test_dayOfweek_random() {
time_t curTime = 951835975;// corresponds to Tuesday(Day 2), 29 February 2000 2:52:55 PM GMT
int result = getDayOfWeek(curTime);
int expected_day = localtime(&curTime)->tm_wday;
assert(result == expected_day && "Test Case 10 Failed");
printf("Test Case 10 Passed\n");
}

// TEST CASE 11:
void test_leap_day() {
time_t curTime = 1078087500;// corresponds to  Sunday(Day 0), 29 February 2004 8:45:00 PM GMT
int result = getDayOfWeek(curTime);
int expected_day = localtime(&curTime)->tm_wday;
assert(result == expected_day && "Test Case 11 Failed");
printf("Test Case 11 Passed\n");
}

// TEST CASE 12:
void test_getEpoch_invalid() {
int month = 1;
int day = 32;
int year = 2022;
int hour = 12;
int min = 61;
int sec = 45;
time_t expected_epoch = -1;
time_t result = getTime(month, day, year, hour, min, sec);
assert(result == expected_epoch && "Test Case 12 Failed");
printf("Test Case 12 Passed\n");
}

// TEST CASE 13:
void test_getEpoch_leap() {
int month = 1;// feb
int day = 28;// 29th
int year = 2004;
int hour = 20;
int min = 45;
int sec = 59;
time_t expected_epoch = 1078087559;
time_t result = getTime(month, day, year, hour, min, sec);
assert(result == expected_epoch && "Test Case 13 Failed");
printf("Test Case 13 Passed\n");
}

// TEST CASE 14:
void test_getEpoch_random() {
int month = 9;// Oct
int day = 28;// 29th
int year = 2025;
int hour = 21;
int min = 10;
int sec = 33;
time_t expected_epoch = 1761772233;
time_t result = getTime(month, day, year, hour, min, sec);
assert(result == expected_epoch && "Test Case 14 Failed");
printf("Test Case 14 Passed\n");
}
// TEST CASE 15:
void test_startEpoch_random() {
int month = 0;// January
int day = 0;// 1st
int year = 1970;
int hour = 0;
int min = 0;
int sec = 0;
time_t expected_epoch = 0;
time_t result = getTime(month, day, year, hour, min, sec);
assert(result == expected_epoch && "Test Case 15 Failed");
printf("Test Case 15 Passed\n");
}
int main() {
//    Testing getHMS()
    test_someTime_lessThanZero();
    test_someTime_equalToZero();
    test_HMS_NULLPointers();
    test_time_now();
    test_random_time();
    test_leap_time();
    test_max_time();
//    Testing getDayOfWeek()
    test_dayOfweek_zerotime();
    test_dayOfweek_current();
    test_dayOfweek_random();
    test_leap_day();
//     Testing getTime()
    test_getEpoch_invalid();
    test_getEpoch_leap();
    test_getEpoch_random();
    test_startEpoch_random();
    return 0;
}


