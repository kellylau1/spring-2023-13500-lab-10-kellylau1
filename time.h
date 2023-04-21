#pragma once

class Time { 
public:
    int h;
    int m;
};

int minutesSinceMidnight(Time); 

int minutesUntil(Time, Time);

Time addMinutes(Time, int); 
