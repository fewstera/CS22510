/*
 *  main.c
 *
 *  Created on: Dec 5, 2012
 *  Author: Aidan Fewster
 * 
 *  Main file for the Runners and Riders system
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "UI.h"
#include "event.h"
#include "nodes.h"
#include "tracks.h"
#include "courses.h"
#include "entrants.h"



/* Files loaded in by the user */
FILE *event_file, *nodes_file, *tracks_file, *courses_file, *entrants_file,  
        *checkpoint_file = NULL;

/* Holds the current time - updated with the last recorded time */
Time current_time;

char checkpoint_file_path[150];
char log_file_path[150];

/* Event date, time and name */
char event_name[80], event_date[80];
Time event_start_time;

Node * nodes = NULL; /* Array of nodes */
int number_nodes = 0; /*The number of nodes */

Track * tracks = NULL; /* Array of tracks */
int number_tracks = 0; /* The number of tracks */

Entrant * entrants = NULL; /* Array of entrants */
int number_entrants = 0; /* The number of courses */

Course * courses = NULL; /* Array of linked lists of courses */
int number_courses = 0; /* The number of courses */

int main(void) {
	load_files_text(); /* Asks the user for files */
        get_checkpoint_path();
        get_log_file_path();
	parse_files(); /* Parse the data within the files */
        user_options(); /* Ask the user what they want to do */
	return EXIT_SUCCESS;
}

void parse_files(){
	parse_event_file(); /* Parse the event file */
        parse_nodes_file(); /* Parse the nodes file */
        parse_tracks_file(); /* Parse the tracks file */
        parse_courses_file(); /* Parse the tracks file */
        parse_entrants_file(); /* Parse the tracks file */
}

/* Converts a Time into minutes */
int time_to_int(Time time){
    return (time.minutes+(time.hours*60));
}


/* The difference in minutes between two times */
int time_difference(Time one, Time two){
    return time_to_int(two)-time_to_int(one);
}