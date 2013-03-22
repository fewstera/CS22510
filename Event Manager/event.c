/*
 *  entrants.c
 *
 *  Created on: Dec 6, 2012
 *  Author: Aidan Fewster
 * 
 *  This file is used to hold functions for an event
 * 
 */
#include "main.h"
#include "event.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Load in external globals (From main.c) */
extern FILE *event_file;
extern char event_name[80], event_date[80];
extern Time event_start_time, current_time;


/* Parses an event file */
void parse_event_file(){
        /* Setup temp char arrays to hold the string from fgets */
	char temp_event_name_string[80], temp_event_date_string[80];
        char temp_event_time_string[6];

	fgets(temp_event_name_string, 80, event_file);
        /* Place the first line into event_name */
	sscanf(temp_event_name_string, "%[^\n]s", event_name);

	fgets(temp_event_date_string, 80, event_file);
         /* Place the second line into event_name */
	sscanf(temp_event_date_string, "%[^\n]s", event_date);

	fgets(temp_event_time_string, 80, event_file);
        /* Place the third line into event time structure */
	sscanf(temp_event_time_string, "%d:%d", 
                &event_start_time.hours, &event_start_time.minutes);
        
        /* Set the current time to this time. */
        current_time = event_start_time;
        
}