//
//  EpochTime.c
//  EpochTime
//
//  Created by Nidhi Galgali on 3/29/23.
//
// Results are GMT oriented

#include "EpochTime.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define TOTAL_SECONDS_PER_DAY (24 * 60 * 60)


static const int MONTH_DAYS[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
// Check for leap year
static bool is_leap(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int getHMS(time_t someTime, int *hour, int *min, int *sec)
{
//    Checking for negative input
    if (someTime < 0)
    {
        return -1;
    }
//    Checking for maximum number of seconds stored by time_t
    if (someTime == (time_t)(-1))
    {
        printf("Invalid Input");
        return -1;
    }
//    Checking for NULL pointers
    if ((hour==NULL)||(min==NULL)||(sec==NULL))
    {
        printf("One of the pointers point to NULL\n");
        return -1;
    }
// (someTime / 3600) gives the total number of hours since the start of Epoch time and % 24 gives the hours since the start of the day
        *hour = (someTime / 3600) % 24;
// someTime / 60) gives the total number of minutes since the start of Epoch time and % 60 gives the minutes in the 0-59 range
        *min = (someTime / 60) % 60;
//    someTime % 60 gives the seconds in the 0-59 range
        *sec = someTime % 60;
//        printf("HOUR: %d ",*hour);
//        printf("MINUTES: %d ",*min);
//        printf("SECONDS: %d ",*sec);
//        printf("\n");
        return 1;
}
int getDayOfWeek(time_t curTime) {
    if (curTime < 0)
    {
        printf("Invalid Input");
        return -1;
    }
    if (curTime == (time_t)(-1))
    {
        printf("Invalid Input");
        return -1;
    }
    int day_of_week=0;
//    current epoch time/ total  num of seconds in a day gives the number of days since the start of epoch time.
//    Since Jan 1 1970 was a Thursday we add a 4 to the number of days to shift the start day of the week to Sunday.
//    % 7 gives us the Day in the 0-6 range
    day_of_week= (curTime / 86400 + 4) % 7;
//    printf("DAY %d\n",day_of_week);
    return day_of_week;
}



time_t getTime(int month, int day, int year, int hour, int min, int sec) {
//     Checking for valid inputs
    if (month < 0 || month > 11 ||
        day < 0 || day >= (MONTH_DAYS[month] + (month == 1 && is_leap(year))) ||
        hour < 0 || hour > 23 ||
        min < 0 || min > 59 ||
        sec < 0 || sec > 59) {
        return (time_t) -1;
    }

    
    time_t epoch_seconds = 0;
    for (int i = 1970; i < year; i++) {
        epoch_seconds += is_leap(i) ? 366 * TOTAL_SECONDS_PER_DAY : 365 * TOTAL_SECONDS_PER_DAY;
    }
    for (int j = 0; j < month; j++) {
        epoch_seconds += MONTH_DAYS[j] * TOTAL_SECONDS_PER_DAY;
        if (j == 1 && is_leap(year)) {
            epoch_seconds += TOTAL_SECONDS_PER_DAY;
        }
    }
    epoch_seconds += day * TOTAL_SECONDS_PER_DAY + hour * 3600 + min * 60 + sec;

    return epoch_seconds;
}
    


//int main ()
//{
//
//    time_t now;
//    now = time(NULL);
//    int h=0,m=0,s=0;
//    getHMS(1770238062,&h,&m,&s);
//    printf("\n");
//    getDayOfWeek(1483315200);
//
//    printf("\n");
//    time_t new_time = getTime(0, 1, 2017,0,0,0);
//       if (new_time == -1) {
//           printf("Invalid input\n");
//       } else {
//           printf("New time: %ld\n", new_time);
//       }
//
//    }

