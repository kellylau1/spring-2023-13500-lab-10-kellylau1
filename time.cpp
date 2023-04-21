#include <iostream>
#include <string>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

//Task A 
int minutesSinceMidnight(Time time) {
    int total_mins = (time.h * 60) + time.m; //Calculates the minutes since midnight
return total_mins; 
}

int minutesUntil(Time earlier, Time later) {
    int result = ((later.h - earlier.h) * 60) + (later.m - earlier.m); //Calculates the minutes until later time
return result; 
}

//Task B
Time addMinutes(Time time0, int min){
    Time newTime; //Create class object 
    newTime.h = time0.h + (time0.m + min) / 60; //Calculates the new hour
    newTime.m = (time0.m + min) % 60; //Calculates the new minutes 
return newTime;
}

//Task C
std::string printMovie(Movie mv){
    std::string movieType; 
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    movieType = mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
return movieType; 
}

std::string getTimeSlot(TimeSlot ts) {
    Time endingTime = addMinutes(ts.startTime, ts.movie.duration); //Calculates when the movie ends
    std::string slot = printMovie(ts.movie); 
    slot = slot + "[starts at " + std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m)+ ", ends by " + std::to_string(endingTime.h) + ":" + std::to_string(endingTime.m) + "]"; //ex of output: Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
return slot; 
}

//Task D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    TimeSlot nextMovieTime; //Create class object
    nextMovieTime.movie = nextMovie; //movie variable in Timeslot now equals to nextMovie
    nextMovieTime.startTime = addMinutes(ts.startTime, ts.movie.duration); //addMinutes calculates the time of the next movie
return nextMovieTime; 
}

//Task E 
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) { 
    if (addMinutes(ts1.startTime, ts1.movie.duration).h >= addMinutes(ts2.startTime, ts2.movie.duration).h ) { //if the endtime hour of ts1 is greater than or equal to ts2...
        return true; 
    } else {
        return false; 
    }
}

