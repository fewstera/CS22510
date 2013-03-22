#include "course.h"
#include <stdexcept>

//The courses class represents a model of a course

Course::Course(std::string id)
{
    this->id = id;
}


void Course::addCheckpoint(Node* checkpoint){
    this->checkpoints.push_back(checkpoint);
}

//Get checkpoint number X
Node* Course::getCheckpointNo(int no){
    try {
        return this->checkpoints.at(no);
    }catch (const std::out_of_range& oor) {
        return NULL;
    }
}

std::string Course::getId(){
    return this->id;
}
