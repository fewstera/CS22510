/* 
 * File:   entrants.h
 * Author: Aidan Fewster
 *
 * Created on December 7, 2012, 8:42 PM
 */

#ifndef ENTRANTS_H
#define	ENTRANTS_H

#include "main.h"
#include "nodes.h"
#include "courses.h"

typedef struct{
    Node * node;
    Time arrival_time;
    Time exit_time;
} CheckpointTime;

typedef struct{
	int id;
        char name[50];
        Course * course;
        CheckpointTime * checkpoint_times;
        int number_visited_checkpoints;
        int at_medical_checkpoint; /* 1 = yes, 0 = no.
        /* 
         * is_disqualified determines if a user is disqualified
         * 0 - Not disqualified
         * 1 - Disqualified for Medical reason
         * 2 - Disqualified for going the wrong way
         */ 
        int is_disqualified; 
        
} Entrant;

void parse_entrants_file();
Course * get_course_from_identifier(char identifier);
void add_entrant(Entrant new_entrant);
CheckpointTime * create_checkpoint_times_array(int size);
void print_not_started();
void print_on_course();
void print_finished();
Entrant * get_entrant_from_id();
int has_finished(Entrant * entrant);
void print_entrant_location(Entrant * entrant);
Track * get_entrant_track(Entrant * entrant);
void print_disqualified(int type);
void reload_entrants();

#endif	/* ENTRANTS_H */

