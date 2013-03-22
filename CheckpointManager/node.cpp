#include "node.h"

Node::Node(int number, bool isMedical){
    this->number = number;
    this->isMedical = isMedical;
}

int Node::getNumber(){
    return this->number;
}

bool Node::getIsMedical(){
    return this->isMedical;
}
