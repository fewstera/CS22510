/*
 *  checkpoints.c
 *
 *  Created on: Dec 7, 2012
 *  Author: Aidan Fewster
 * 
 *  This file is used to hold functions for checkpoints
 * 
 */
#include "UI.h"
#include "checkpoints.h"
#include "entrants.h"
#include "courses.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Load in external globals (From main.c) */
extern Entrant * entrants;
extern Time current_time;
extern int number_entrants;
extern char checkpoint_file_path[150];

/* Parses checkpoint file that has been loaded */
void parse_checkpoint_file(){
    reload_entrants();
    FILE * checkpoint_file = fopen(checkpoint_file_path, "r");
    char temp_entrant_checkpoint[70];
    while(fgets(temp_entrant_checkpoint, 70, checkpoint_file)){
        Entrant * entrant;
        Node * node;
        Time time;
        int node_no, entrant_no;
        char type;
        sscanf(temp_entrant_checkpoint, "%c %d %d %d:%d", 
                &type, &node_no, &entrant_no,
                &time.hours, &time.minutes);
        entrant = get_entrant_from_id(entrant_no);
        node = get_node_from_id(node_no);
        /* If the next node being entered isn't right exit*/
        if(entrant==NULL){
            printf("Error in checkpoint file, exiting!");
            exit(EXIT_FAILURE);
        }else{
            if(type=='T'){
                
                CheckpointTime checkpoint_time;
                checkpoint_time.arrival_time = time;
                checkpoint_time.node = node;
                checkpoint_time.exit_time = time;
                entrant->at_medical_checkpoint = 0;
                set_entrant_time(entrant, checkpoint_time);
            }else if(type=='A'){
                CheckpointTime checkpoint_time;
                checkpoint_time.arrival_time = time;
                checkpoint_time.node = node;
                set_entrant_time(entrant, checkpoint_time);
                entrant->at_medical_checkpoint = 1;
            }else if(type=='I'){
                entrant->is_disqualified = 2;
            }else if(type=='E'){
                entrant->is_disqualified = 1;
            }else if(type=='D'){
                entrant->checkpoint_times[
                        entrant->number_visited_checkpoints-1
                                ].exit_time = time;
                entrant->at_medical_checkpoint = 0;
            }
        }
    }
    fclose (checkpoint_file);
}