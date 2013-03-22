#include "node.h"

//Model representing a node on the course

Node::Node(int number, bool isMedical){
    this->number = number;
    this->isMedical = isMedical;
}

int Node::getNumber(){
    return this->number;
}

//check if the node is a medical checkpoint
bool Node::getIsMedical(){
    return this->isMedical;
}
