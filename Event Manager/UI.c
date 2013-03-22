/*
 *  UI.c
 *
 *  Created on: Dec 6, 2012
 *  Author: Aidan Fewster
 * 
 *  This file is used to hold functions for the user interface
 * 
 */

#include "UI.h"
#include "entrants.h"
#include "courses.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

/* Load in external globals (From main.c) */
extern FILE *event_file, *nodes_file, *tracks_file, *courses_file, *entrants_file;
extern FILE *checkpoint_file;
extern Entrant * entrants;
extern int number_entrants;
extern char checkpoint_file_path[150];
extern char log_file_path[150];

/* Ask the user for a file and loads it into a FILE pointer */
void load_file(char text[], FILE ** file){
	printf("%s", text); /* Print the text nicely to the user */
	char file_string[150]; /* String to hold the files location */
	scanf("%s", file_string);

	/*Open the file, if it fails to open ask the user to try again */
	if(!(*file = fopen(file_string, "r"))){
		printf("\nError file doesn't exit try again\n\n");
		load_file(text, file);
	}
}

void get_checkpoint_path(){
    printf("Please enter the location of the times file: ");
    char file_string[150]; /* String to hold the files location */
    scanf("%s", file_string);
    FILE *temp_file;
    /*Open the file, if it fails to open ask the user to try again */
    if (!(temp_file = fopen(file_string, "r"))) {
        printf("\nError file doesn't exit try again\n\n");
        get_checkpoint_path();
    }else{
        strcpy(checkpoint_file_path, file_string);
    }
}

/* Ask the user for the locations of the files*/
void load_files_text(){
	printf("Monitors the Runners and Riders\n\n");
	load_file("Please enter the location of the event file: ", &event_file);
        load_file("Please enter the location of the nodes file: ", &nodes_file);
        load_file("Please enter the location of the tracks file: ", &tracks_file);
	load_file("Please enter the location of the courses file: ", &courses_file);
        load_file("Please enter the location of the entrants file: ", &entrants_file);
}


/* Present the user with options and execute the cor1rect command*/
void user_options(){
    
    
    printf("\n\nWhat would you like to do?\n"
            "(1) Query the status/location of a competitor\n"
            "(2) Find out how many competitors have yet to start\n"
            "(3) Find out how many competitors are on the course\n"
            "(4) Find out how many competitors have finished\n"
            "(5) Find out how many competitors have disqualified on medical terms\n"
            "(6) Find out how many competitors have disqualified for going the wrong way\n"
            "(7) Produce a table\n"
            "(8) Exit\n\n"
            "Enter the number of your choice: ");
    int user_option = -1;
    scanf("%d", &user_option);
    parse_checkpoint_file();
    switch(user_option){
        case 1:
            add_to_log("Queried an entrant location");
            query_entrant_location();
            break;
        case 2:
            add_to_log("Viewed entrants not started table");
            print_not_started();
            break;
        case 3:
            add_to_log("Viewed entrants on course table");
            print_on_course();
            break;
        case 4:
            add_to_log("Viewed entrants finished table");
            print_finished();
            break;
        case 5:
            add_to_log("Viewed disqualified entrants table");
            print_disqualified(1);
            press_enter();
            user_options();
            break;
        case 6:
            add_to_log("Viewed medically disqualified entrants table");
            print_disqualified(2);
            press_enter();
            user_options();
            break;
        case 7:
            add_to_log("Viewed final results table");
            print_results_table();
            break;
        case 8:
            add_to_log("Exited application");
            break;
        default:
            invalid_user_input();
            break;
    }
}

/* Alerts the users they've done something wrong, and restarts */
void invalid_user_input(){
    printf("\nYou entered an invalid selection (only numbers allowed)\n\n");
    press_enter();
    user_options();
}

/* Flushes the input buffer and asks user to press enter */
void press_enter(){
    printf("Press enter to continue!\n");
    int ch;
    /* Flush the input buffer */
    while ((ch = getchar()) != EOF && ch != '\n') ;
    scanf("%*[^\n]");    
}


/* Prints out a users status / location */
void query_entrant_location(){
     printf("\n\nWhich entrant would you like to find the location of?\n\n"
            "Entrant Number\tName\n");
    int index;
    for(index = 0; index < number_entrants; index++){
        printf("(%d)\t\t%s\n", entrants[index].id, entrants[index].name);  
    }
    
    printf("\nPlease enter the entrant number of your choice: "); 
    int entrant_no = -1;
    scanf("%d", &entrant_no);
    Entrant * entrant = get_entrant_from_id(entrant_no);
    if(entrant == NULL){
        invalid_user_input();
    }else{
        /* print the users location/status */
        print_entrant_location(entrant);
        press_enter();
        user_options();
    }
}


/* Prints a results table of finished competitors */
void print_results_table(){
    int index;
    Entrant ** finished = NULL;
    int no_finished = 0;
    /* Iterate over the entrants and make an array of finished competitors */
    for(index = 0; index<number_entrants; index++){
        if(has_finished(&entrants[index])){
                void *temp_array = realloc(finished, ((no_finished+1) * sizeof(Entrant*)));
                if(!temp_array){
                        printf("Memory error, exiting");
                        exit(EXIT_FAILURE);
                }
                finished = (Entrant**) temp_array;
                finished[no_finished] = &entrants[index];
                no_finished++;
        }
    }
    
    /* Sort the array using quick sort */
    qsort (finished, no_finished, sizeof(Entrant*), compare_entrants);
    
    int counter;
    
    /* Print the results table */
    printf("\n\nId\tCourse\tEntrant Name\t\tTime\n");
    for(counter=0; counter<no_finished; counter++){
        int i_no = finished[counter]->number_visited_checkpoints-1;
        int race_time = 0;
        race_time = time_difference_mc(finished[counter]);
        Entrant * entrant = finished[counter];
        int no = entrant->id;
        printf("%d\t%c\t%-22s\t%.2d:%.2d\n",
                entrant->id,
                entrant->course->identifier,
                finished[counter]->name,
                race_time/60, race_time%60
                );
    }
    printf("\n\nThe next table will be entrants that were disqualified for medical reasons.\n");
    press_enter();
    print_disqualified(1);
    printf("\n\nThe next table will be entrants that were disqualified for taking an incorrect route.\n");
    press_enter();
    print_disqualified(2);
    press_enter();
    free(finished); /* Free the finished array */
    user_options();
}

/* 
 * Takes two entrants and compares there times (For use with quick sort)
 * Returns < 0 if entrant_one is quickest
 * Returns > 0 if entrant_two is quickest
 * Returns 0 otherwise  
 */
int compare_entrants (const void * entrant_one, const void * entrant_two){
    Entrant * one = *(Entrant **)entrant_one;
    Entrant * two = *(Entrant **)entrant_two;
    int time_one = time_difference_mc(one);
    int time_two = time_difference_mc(two);
    return ( time_one - time_two );
}

/* The difference in minutes between two times taking into account
 * medical check point waiting times
 */
int time_difference_mc(Entrant  * entrant){
    int time = time_difference(entrant->checkpoint_times[0].arrival_time,
          entrant->checkpoint_times[entrant->number_visited_checkpoints-1].arrival_time);
    /*Below accounts for medical checkpoints*/
    int index;
    int difference = 0;
    for(index = 0; index<(entrant->number_visited_checkpoints); index++){
        difference = difference + time_difference(entrant->checkpoint_times[index].arrival_time, 
                entrant->checkpoint_times[index].exit_time);
    }
    time -= difference;
    return time;
}

void get_log_file_path(){
    printf("Please enter the location of the log file: ");
    char file_string[150]; /* String to hold the files location */
    scanf("%s", file_string);
    FILE *temp_file;
    /*Open the file, if it fails to open ask the user to try again */
    if (!(temp_file = fopen(file_string, "r"))) {
        printf("\nError file doesn't exist try again\n\n");
        get_log_file_path();
    }else{
        strcpy(log_file_path, file_string);
    }
}

//Adds a new message to the log
void add_to_log(const char* message){    
    
    FILE* log_file = fopen(log_file_path, "a+");
    //Locks the log file while we write
    flock(fileno(log_file),LOCK_EX);
    time_t now;
    time(&now);
    char s[50];

    time_t t = time(NULL);
    struct tm * p = localtime(&t);

    //Formats the time string
    strftime(s, 1000, "[%A, %B %d %Y at %I:%M]", p);
    fprintf(log_file,"%s %s\n", s, message);
    //Unlocks the log file
    flock(fileno(log_file),LOCK_UN);
    fclose(log_file);
}