/*
 * UI.h
 *
 *  Created on: Dec 6, 2012
 *  Author: Aidan Fewster
 */

#include <stdio.h>

#ifndef GUI_H_
#define GUI_H_

#include "entrants.h"


void load_files_text();
void load_file(char text[], FILE ** file);
void user_options();
void invalid_user_input();
void press_enter();
void supply_entrant_time();
void query_entrant_location();
void print_results_table();
int compare_entrants (const void * entrant_one, const void * entrant_two);
int time_difference_mc(Entrant * entrant);
void get_checkpoint_path();
void get_log_file_path();
void add_to_log(const char* message);
#endif /* GUI_H_ */
