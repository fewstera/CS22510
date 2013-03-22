/*
 *  courses.c
 *
 *  Created on: Dec 6, 2012
 *  Author: Aidan Fewster
 * 
 *  This file is used to hold functions for courses
 * 
 */

#include "main.h"
#include "courses.h"
#include "tracks.h"
#include "nodes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Load in external globals (From main.c) */
extern FILE *courses_file;
extern Course * courses;
extern Track * tracks;
extern int number_courses, number_tracks;


/* Parses a course file supplied by the user */
void parse_courses_file(){
    char temp_courses_string[150];
    while(fgets(temp_courses_string, 150, courses_file)){
        
        /* scan_buffer holds the same value as temp_courses_string
         * but as part of the string is read, that bit is cut
         * out of scan_buffer
         */
        char *scan_buffer = temp_courses_string;
        int no_bytes_in; /* The number of bytes to cut off */
     
        char identifier; /* The course name (identifier) */
        int no_course_nodes;

        /* Read in the course identifier and number of nodes */
        sscanf(scan_buffer, "%c %d%n", 
                &identifier, &no_course_nodes, &no_bytes_in);
        /* Shift the scan_buffer along */
        scan_buffer += no_bytes_in;
        
        Node* course_nodes[no_course_nodes]; /* Setup an array of nodes */
        
        int index;
        /* Interate over the remaining scan buffer getting the nodes */
        for(index = 0; index<no_course_nodes; index++){ 
            int temp_node;
            sscanf(scan_buffer, "%d%n", &temp_node, &no_bytes_in);
            scan_buffer += no_bytes_in; //Move the scan buffer along
            course_nodes[index] = get_node_from_id(temp_node);
            if(course_nodes[index]==NULL){
                printf("Error with either courses or nodes file");
                exit(EXIT_FAILURE);         
            }
        }
        
        /* Add the course*/
        add_new_course(identifier, no_course_nodes, course_nodes);
    }    
}

/* Adds a new course to the courses array */
void add_new_course(char identifier, int no_course_nodes, Node* course_nodes[]){
    
    int index;
    Path* new_path_head = NULL;
    
    /* Create the path of the course */
    for(index = 0; index<no_course_nodes; index++){ 
        Path* new_path = create_path(course_nodes[index]);
        add_to_path(&new_path_head, new_path);
    }
    
    /* Add the tracks between paths to the path */
    add_tracks_to_path(&new_path_head);
    
    /* Reallocate the courses array to make room for a new element */
    void *temp_array = realloc(courses, ((number_courses+1) * sizeof(Course)));
    if(!temp_array){
        printf("Memory error, exiting");
        exit(EXIT_FAILURE);
    }
    courses = (Course*)temp_array;    
    
    /* Set the course values */
    courses[number_courses].identifier = identifier;
    courses[number_courses].start_path_node = new_path_head;
    number_courses++;  
}

/* Creates a new path from with node */
Path* create_path(Node* path_node){
    Path* new_path = malloc(sizeof(Path));
    new_path->next_step = NULL;
    new_path->next_track = NULL;
    new_path->node = path_node;
    return new_path;
}

/* Adds a path to a path (Linked list) */
void add_to_path(Path** path_node, Path* new_path){
    if((*path_node) == NULL){
        (*path_node) = new_path;
    }else{
         add_to_path(&((*path_node)->next_step), new_path);
   }
}

/* Adds the tracks to get from one node to another to the path */
void add_tracks_to_path(Path** path_node){
    Path* new_path = (*path_node);
    if((new_path != NULL)&&(new_path->next_step != NULL)){
        Path* new_path = (*path_node);
        Track* track = get_track_from_nodes(new_path->node, new_path->next_step->node);
        new_path->next_track = track;
        add_tracks_to_path(&(new_path->next_step));
    }
}

/* Returns the track between two nodes */
Track* get_track_from_nodes(Node* start_node, Node* end_node){
    if((start_node==NULL)||(end_node==NULL)){
        return NULL;
    }else{
        int index;
        for(index = 0; index<number_tracks; index++){
            /* Check if the nodes are the ones we want */
            if((tracks[index].start_node==start_node)
                    &&(tracks[index].end_node==end_node)
                        ||(tracks[index].start_node==end_node)
                                &&(tracks[index].end_node==start_node)
                    ){
                return &tracks[index];
            }
        }
        printf("\nTrack not found %d -> %d", start_node->id, end_node->id);
        exit(EXIT_FAILURE);
    }
}

/* returns the numbers of checkpoints a course */
int get_number_course_checkpoints(Course * course){
    Path * current_path = course->start_path_node;
    int number_course_nodes = 0;
    while(current_path!=NULL){
        if(strcmp(current_path->node->type, "JN")!=0){
                number_course_nodes++;
        }
        current_path = current_path->next_step;
    }
    return number_course_nodes;
}

/* Returns the n'th checkpoint on the course */
Node * get_course_checkpoint_no(Course * course, int number){
    Path * current_path = course->start_path_node;
    int no_counter = 0;
    /* Traverse through the course counting the checkpoints */
    while(current_path!=NULL){
        if(strcmp(current_path->node->type, "JN")!=0){
            if(number==no_counter){
                return current_path->node;
            }else{
                no_counter++;
            }
        }
        current_path = current_path->next_step;
    }
    return NULL;
}