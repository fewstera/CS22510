/*
 *  entrants.c
 *
 *  Created on: Dec 6, 2012
 *  Author: Aidan Fewster
 * 
 *  This file is used to hold functions for entrants
 * 
 */
#include "main.h"
#include "courses.h"
#include "tracks.h"
#include "nodes.h"
#include "entrants.h"
#include "UI.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Load in external globals (From main.c) */
extern FILE *entrants_file;
extern Entrant * entrants;
extern Course * courses;
extern int number_entrants, number_courses;
extern Time current_time;

/* Adds all the entrants from a entrants file to the entrants array */
void parse_entrants_file(){
    char temp_entrant_string[70];
    /* Interate over the files lines */
    while(fgets(temp_entrant_string, 70, entrants_file)){
        Entrant new_entrant;
        char tempt_course_identifier;
        sscanf(temp_entrant_string, "%d %c %[^\n]s", 
                &new_entrant.id, &tempt_course_identifier, new_entrant.name);
        new_entrant.course = get_course_from_identifier(tempt_course_identifier); 
        add_entrant(new_entrant);
    }
}

/* Returns a pointer to a course from its identifier */
Course * get_course_from_identifier(char identifier){
    int index;
    for(index=0; index<number_courses; index++){
        if(courses[index].identifier==identifier){
            return &courses[index];
        }
    }
    return NULL;
}

/* Adds a new node to the nodes array */
void add_entrant(Entrant new_entrant){
    /* Resizes the entrants array */
    void *temp_array = realloc(entrants, ((number_entrants+1) * sizeof(Entrant)));
    if(!temp_array){
        printf("Memory error, exiting");
        exit(EXIT_FAILURE);
    }
    entrants = (Entrant*)temp_array;
    
    /* Sets the values of the new entrant */
    entrants[number_entrants].id = new_entrant.id;
    entrants[number_entrants].course = new_entrant.course;
    entrants[number_entrants].is_disqualified = 0;
    entrants[number_entrants].at_medical_checkpoint = 0;
    int no_checkpoints = get_number_course_checkpoints(new_entrant.course);
    entrants[number_entrants].checkpoint_times = 
            create_checkpoint_times_array(no_checkpoints);
    strcpy(entrants[number_entrants].name, new_entrant.name);
    entrants[number_entrants].number_visited_checkpoints = 0;
    number_entrants++;
}

/* Creates a CheckpointTime array of size size */
CheckpointTime * create_checkpoint_times_array(int size){
    CheckpointTime* times = malloc(sizeof(CheckpointTime)*size);
    return times;
}

/* Prints a list of entrant that have yet to start */
void print_not_started(){
    printf("\n\nThe following entrants have yet to start\n\n"
            "Competitor Number\tCompetitor Name\n");
    int index;
    int counter = 0;
    for(index=0; index<number_entrants; index++){
        if(entrants[index].number_visited_checkpoints == 0){
            printf("%d\t\t\t%s\n", entrants[index].id, entrants[index].name);
            counter++;
        }
    }
    printf("\nThat's a total of %d entrants\n\n", counter);
    press_enter();
    user_options();
}

/* Prints a list of entrants that are on the course */
void print_on_course(){
    printf("\n\nThe following entrants are on the course\n\n"
            "Competitor Number\tCompetitor Name\n");
    int index;
    int counter = 0;
        
    for(index=0; index<number_entrants; index++){
        if((entrants[index].number_visited_checkpoints>0)&&
                (has_finished(&entrants[index])==0)&&
                (entrants[index].is_disqualified==0)){
            printf("%d\t\t\t%s\n", entrants[index].id, entrants[index].name);
            counter++;
        }
    }
    printf("\nThat's a total of %d entrants\n\n", counter);
    press_enter();
    user_options();
}

/* Prints a list of entrants that have been disqualified */
void print_disqualified(int type){
    printf("\n\nThe following entrants have been disqualified");
    if(type==1){
        printf(" for medical reasons.");
    }else{
        printf(" for taking the incorrect route.");
    }
    
    printf("\n\nCompetitor Number\tCompetitor Name\n");
    int index;
    int counter = 0;
        
    for(index=0; index<number_entrants; index++){
        if((entrants[index].number_visited_checkpoints>0)&&
                (has_finished(&entrants[index])==0)&&
                (entrants[index].is_disqualified==type)){
            printf("%d\t\t\t%s\n", entrants[index].id, entrants[index].name);
            counter++;
        }
    }
    printf("\nThat's a total of %d entrants\n\n", counter);
}

/* Prints a list of entrants that have finished */
void print_finished(){
    printf("\n\nThe following entrants have finished the course\n\n"
            "Competitor Number\tCompetitor Name\n");
    int index;
    int counter = 0;
        
    for(index=0; index<number_entrants; index++){
        if(has_finished(&entrants[index])==1){
            printf("%d\t\t\t%s\n", entrants[index].id, entrants[index].name);
            counter++;
        }
    }
    printf("\nThat's a total of %d entrants\n\n", counter);
    press_enter();
    user_options();
}

/* Returns 1 if the given entrant has finished, 0 otherwise */
int has_finished(Entrant * entrant){
    int return_value = 0;
    int no_course_checkpoints = get_number_course_checkpoints(entrant->course);
    if(entrant->number_visited_checkpoints==no_course_checkpoints){
        return_value = 1;
    }
    return return_value;
}

/* Returns a point to an entrant with id entrant_no */
Entrant * get_entrant_from_id(int entrant_no){
    int index;
    for(index = 0; index < number_entrants; index++){
        if(entrants[index].id == entrant_no){
            return &entrants[index];
        }
    }
    return NULL;
}

/* Sets the time for entrant reaching a checkpoint. 
 * new_cp is if the checkpoint is new or not (Medical) 
 */
void set_entrant_time(Entrant * entrant, CheckpointTime time, int new_cp){
    entrant->checkpoint_times[entrant->number_visited_checkpoints] = time;
    entrant->number_visited_checkpoints++;
}

/* Print the entrants location/status */
void print_entrant_location(Entrant * entrant){
    if(has_finished(entrant)==1){
        printf("\n\n%s has finished course %c.\n\n",
                entrant->name, entrant->course->identifier);
    }else if(entrant->is_disqualified==1){
        printf("\n\n%s has been disqualified for medical reasons.\n\n",
                entrant->name);
    }else if(entrant->is_disqualified==2){
        printf("\n\n%s has been disqualified for taking an incorrect route\n\n",
                entrant->name);
    }else if(entrant->number_visited_checkpoints>0){
        if(entrant->at_medical_checkpoint==1){
                printf("\n\n%s is at a medical checkpoint (node %d) and "
                        "should now be leaving soon.\n\n",
                    entrant->name,
                    entrant->
                        checkpoint_times[entrant->
                                number_visited_checkpoints-1].node->id);
        }else{
            printf("\n\n%s was last seen at checkpoint number %d (node %d) and "
                    "should now be on track %d.\n\n",
                    entrant->name,
                    entrant->number_visited_checkpoints,
                    entrant->checkpoint_times[entrant->
                        number_visited_checkpoints-1].node->id,
                    get_entrant_track(entrant)->id);
        }
    }else{
        printf("\n\n%s has not yet started course %c.\n\n",
                entrant->name, entrant->course->identifier);
    }
}

/* Estimates which track a entrant is on */
Track * get_entrant_track(Entrant * entrant){
    
    Path * path = entrant->course->start_path_node;
    
    int counter = 0;
    /* Traverse the graph till you find the last known place the entrant was */
    while(counter<(entrant->number_visited_checkpoints-1)){
        if(strcmp(path->next_step->node->type, "JN")!=0){
            counter++;
        }
        path = path->next_step;
    }
    
    int no_checkpoints = entrant->number_visited_checkpoints;
    Time last_time = entrant->checkpoint_times[no_checkpoints-1].arrival_time;
    int min_difference = time_difference(last_time, current_time);
    
    int complete = 0; /* Boolean to exit the loop */
    
    Track * track = path->next_track;
    /* 
     * Traverse through the path checking if entrant could be on that track
     * If time is greater than the maximum time allowed by the track
     * then check the next track
     */
    while((strcmp(path->next_step->node->type, "JN")==0)&&(complete==0)){
        track = path->next_track;
        if((min_difference-(track->max_time))<=0){
            complete = 1;
        }else{
            min_difference -= track->max_time;
        }
        path = path->next_step;
    }
    return track;
}

void reload_entrants(){
    int index;
    for(index=0; index<number_entrants; index++){
        entrants[index].is_disqualified = 0;
        entrants[index].at_medical_checkpoint = 0;
        int no_checkpoints = get_number_course_checkpoints(entrants[index].course);
        free(entrants[index].checkpoint_times);
        entrants[index].checkpoint_times = 
            create_checkpoint_times_array(no_checkpoints);
        entrants[index].number_visited_checkpoints = 0;
    }
}