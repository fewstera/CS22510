#ifndef ENTRANT_H
#define ENTRANT_H
#include <iostream>
#include "course.h"

class Entrant
{
public:
    Entrant(int id, std::string string, Course* course);
    int getId();
    void reset();
    Node* nextNode();
    void incrementVisitedNodes();
    std::string getName();
private:
    Course* course;
    int id;
    std::string name;
    int visitedNodes;
};

#endif // ENTRANT_H
