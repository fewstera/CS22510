/*
 *  tracks.c
 *
 *  Created on: Dec 6, 2012
 *  Author: Aidan Fewster
 * 
 *  This file is used to hold functions for a track
 * 
 */
#include "main.h"
#include "tracks.h"
#include "nodes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Load in external globals (From main.c) */
extern FILE *tracks_file;
extern Track * tracks; 
extern Node * nodes;
extern int number_tracks, number_nodes; 

/* Adds all the tracks from a tracks file to the tracks array*/
void parse_tracks_file(){
    char temp_track_string[10];
    while(fgets(temp_track_string, 10, tracks_file)){
        Track new_track;
        int temp_start_node, temp_end_node;
        
        sscanf(temp_track_string, "%d %d %d %d", 
                &new_track.id, &temp_start_node, 
                &temp_end_node, &new_track.max_time);
        
        Node * start_node = get_node_from_id(temp_start_node);
        Node * end_node = get_node_from_id(temp_end_node);
        if((start_node==NULL)||(end_node==NULL)){
           printf("Error with either tracks or nodes file");
           exit(EXIT_FAILURE);         
        }
        new_track.start_node = start_node;
        new_track.end_node = end_node;
        add_track(new_track);
    }
}

/* Adds a new track to the tracks array */
void add_track(Track new_track){
    /* Resize the tracks array  */
    void *temp_array = realloc(tracks, ((number_tracks+1) * sizeof(Track)));
    if(!temp_array){
        printf("Memory error, exiting");
        exit(EXIT_FAILURE);
    }
    tracks = (Track*)temp_array;
    
    /* Code set the values of the new track */
    tracks[number_tracks].id = new_track.id;
    tracks[number_tracks].max_time = new_track.max_time;
    tracks[number_tracks].start_node = new_track.start_node;
    tracks[number_tracks].end_node = new_track.end_node;
    number_tracks++;
}

