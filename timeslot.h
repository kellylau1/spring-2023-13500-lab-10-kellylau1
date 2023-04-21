#pragma once
#include "movie.h"

std::string getTimeSlot(TimeSlot); 
TimeSlot scheduleAfter(TimeSlot, Movie); 
bool timeOverlap(TimeSlot, TimeSlot); 