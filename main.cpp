#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include <string>


int main () {
//Task A
std::cout << "Task A" << std::endl; 
Time morningLecture = {10, 30};
Time nightLecture = {13, 40} ;
std::cout << minutesSinceMidnight(morningLecture) << std::endl; 
std::cout << minutesUntil(morningLecture, nightLecture) << std::endl; // ==> should return 190 minutes 


//Task B
std::cout << "Task B" << std::endl; 
Time time0 = {8,10}; 
Time addedTime = addMinutes(time0, 75);
std::cout << addedTime.h << ":" << addedTime.m << std::endl;
std::cout << std::endl;


//Task C
std::cout << "Task C" << std::endl; 
Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};

TimeSlot morning = {movie1, {9, 15}};  
TimeSlot daytime = {movie2, {12, 15}}; 
TimeSlot evening = {movie2, {16, 45}}; 

std::cout << getTimeSlot(morning) << std::endl;
std::cout << getTimeSlot(daytime) << std::endl;
std::cout << getTimeSlot(evening) << std::endl; 
std::cout << std::endl;


//Task D
std::cout << "Task D" << std::endl; 
TimeSlot m = scheduleAfter(morning, movie1); 
TimeSlot m1 = scheduleAfter(daytime, movie2); 
std::cout << getTimeSlot(m) << std::endl; 
std::cout << getTimeSlot(m1) << std::endl;
std::cout << std::endl;


//Task E
std::cout << "Task E" << std::endl; 
Movie movie5 = {"Back to the Future", COMEDY, 15};
Movie movie6 = {"Black Panther", ACTION, 134};
TimeSlot overlap1 = {movie5, {10, 00}};
TimeSlot overlap2 = {movie6, {10, 15}};
TimeSlot overlap3 = {movie5, {10, 14}};
std::cout << timeOverlap(overlap1, overlap2) << std::endl;
std::cout << timeOverlap(overlap1, overlap3) << std::endl; 
std::cout << std::endl;

return 0; 
}