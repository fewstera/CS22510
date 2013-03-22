/*
 * main.h
 *
 *  Created on: Dec 6, 2012
 *  Author: Aidan Fewster
 */
#include "entrants.h"


#ifndef MAIN_H_
#define MAIN_H_



typedef struct{
	int hours;
	int minutes;
} Time;

void parse_files();
int time_to_int(Time time);
int time_difference(Time one, Time two);
#endif 
