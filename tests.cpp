#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

Time morningLecture = {10, 30}; 
Time nightLecture = {13, 40};
Time t = {12, 30};
Time time0 = {8,10}; 

Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};

TimeSlot morning = {movie1, {9, 15}};  
TimeSlot daytime = {movie2, {12, 15}}; 
TimeSlot evening = {movie2, {16, 45}}; 

TEST_CASE("minutesSinceMidnight") {
    CHECK(minutesSinceMidnight(morningLecture) == 630);
    CHECK(minutesSinceMidnight(nightLecture) == 820);
}

TEST_CASE("minutesUntil") {
  CHECK(minutesUntil(morningLecture, nightLecture) == 190);
  CHECK(minutesUntil(nightLecture, morningLecture) == -190);
}

TEST_CASE("addMinutes") {
  CHECK(addMinutes(time0, 75).h == 9);
  CHECK(addMinutes(time0, 75).m == 25);
  CHECK(addMinutes(morningLecture, 20).h == 10);
  CHECK(addMinutes(morningLecture, 20).m == 50);
}

TEST_CASE("getTimeSlot") {
  CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min)[starts at 9:15, ends by 11:11]");
  CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min)[starts at 12:15, ends by 14:29]");
  CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min)[starts at 16:45, ends by 18:59]");
}

TEST_CASE("scheduleAfter") {
    CHECK(scheduleAfter(morning, movie1).startTime.h == 11);
    CHECK(scheduleAfter(morning, movie1).startTime.m == 11);
    CHECK(scheduleAfter(daytime, movie2).startTime.h == 14);
    CHECK(scheduleAfter(daytime, movie2).startTime.m == 29);
} 

TEST_CASE("timeOverlap") {
    Movie movie5 = {"Back to the Future", COMEDY, 15};
    Movie movie6 = {"Black Panther", ACTION, 134};
    TimeSlot overlap1 = {movie5, {10, 00}};
    TimeSlot overlap2 = {movie6, {10, 15}};
    TimeSlot overlap3 = {movie5, {10, 14}};
    TimeSlot overlap4 = {movie6, {22, 00}};
    CHECK(timeOverlap(overlap1, overlap2) == 0);
    CHECK(timeOverlap(overlap1, overlap3) == 1);
    CHECK(timeOverlap(overlap3, overlap4) == 0); 
} 