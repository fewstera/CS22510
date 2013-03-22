/* 
 * File:   courses.h
 * Author: Aidan Fewster
 *
 * Created on December 7, 2012, 8:38 PM
 */

#ifndef COURSES_H
#define	COURSES_H

#include "tracks.h"
#include "nodes.h"

typedef struct path_struct Path;

struct path_struct {
    Node * node;
    Track * next_track;
    Path * next_step;
};

typedef struct{
	char identifier;
	Path * start_path_node;
} Course;

void parse_courses_file();
void add_new_course(char identifier, int no_course_nodes, Node* course_nodes[]);
Path* create_path(Node* path_node);
void add_to_path(Path** path_node, Path* new_path);
void add_tracks_to_path(Path** path_node);
Track* get_track_from_nodes(Node* start_node, Node* end_node);
int get_number_course_checkpoints(Course * course);
Node * get_course_checkpoint_no(Course * course, int number);

#endif	/* COURSES_H */

