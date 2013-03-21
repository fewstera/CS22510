#include "entrant.h"
#include <iostream>

Entrant::Entrant(int id, std::string name, Course* course){
    this->id = id;
    this->name = name;
    this->visitedNodes = 0;
    this->course = course;
}

int Entrant::getId(){
    return this->id;
}

void Entrant::incrementVisitedNodes(){
    this->visitedNodes++;
}

void Entrant::reset(){
    this->visitedNodes = 0;
}

Node* Entrant::nextNode(){
    return this->course->getCheckpointNo(this->visitedNodes);
}

std::string Entrant::getName(){
    return this->name;
}
