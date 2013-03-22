#include "entrant.h"
#include <iostream>

//Model representing an entrant on the course

Entrant::Entrant(int id, std::string name, Course* course){
    this->id = id;
    this->name = name;
    this->visitedNodes = 0;
    this->course = course;
}

int Entrant::getId(){
    return this->id;
}

//Called when an entrant reachs a new checkpoint
void Entrant::incrementVisitedNodes(){
    this->visitedNodes++;
}

//Resets the entrant, used whe reloading
void Entrant::reset(){
    this->visitedNodes = 0;
}

//Returns the next node, this entrant is expected at
Node* Entrant::nextNode(){
    return this->course->getCheckpointNo(this->visitedNodes);
}

std::string Entrant::getName(){
    return this->name;
}
