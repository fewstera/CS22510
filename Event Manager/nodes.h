/* 
 * File:   nodes.h
 * Author: Aidan Fewster
 *
 * Created on December 7, 2012, 8:31 PM
 */


#ifndef NODES_H
#define	NODES_H


typedef struct{
	int id;
	char type[2];
} Node;
 
void parse_nodes_file();
void add_node(Node);
Node * get_node_from_id(int id);

#endif	/* NODES_H */

