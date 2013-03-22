/* 
 * File:   tracks.h
 * Author: Aidan Fewster
 *
 * Created on December 7, 2012, 8:34 PM
 */

#ifndef TRACKS_H
#define	TRACKS_H

#include "nodes.h"

typedef struct{
	int id;
        int max_time; //maximum time to complete track
	Node * start_node;
        Node * end_node;
} Track;

void add_track(Track new_track);
void parse_tracks_file();

#endif	/* TRACKS_H */

