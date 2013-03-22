/*
 *  nodes.c
 *
 *  Created on: Dec 6, 2012
 *  Author: Aidan Fewster
 * 
 *  This file is used to hold functions for a node
 * 
 */
#include "main.h"
#include "courses.h"
#include "nodes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Load in external globals (From main.c) */
extern FILE *nodes_file;
extern Node * nodes;
extern int number_nodes;

/* Adds all the nodes from a nodes file to the nodes array */
void parse_nodes_file(){
    char temp_node_string[10];
    while(fgets(temp_node_string, 10, nodes_file)){
        Node new_node;
        sscanf(temp_node_string, "%d %s", &new_node.id, new_node.type);
        add_node(new_node);
    }
}

/* Adds a new node to the nodes array */
void add_node(Node new_node){
    /* Resize the nodes array */
    void *temp_array = realloc(nodes, ((number_nodes+1) * sizeof(Node)));
    if(!temp_array){
        printf("Memory error, exiting");
        exit(EXIT_FAILURE);
    }
    nodes = (Node*)temp_array;
    nodes[number_nodes].id = new_node.id;
    strcpy(nodes[number_nodes].type, new_node.type);
    number_nodes++;
}

/* Returns a pointer to a node with the id asked for */
Node * get_node_from_id(int id){
    int index;
    for(index = 0; index<number_nodes; index++){
        if(nodes[index].id==id){
            return &nodes[index];
        }
    }
    return NULL;
}

