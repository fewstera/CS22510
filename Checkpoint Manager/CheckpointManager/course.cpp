#include "course.h"
#include <stdexcept>

Course::Course(std::string id)
{
    this->id = id;
}


void Course::addCheckpoint(Node* checkpoint){
    this->checkpoints.push_back(checkpoint);
}

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
