#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include "node.h"

class Course
{
public:
    Course(std::string id);
    void addCheckpoint(Node* checkpoint);
    Node* getCheckpointNo(int no);
    std::string getId();
private:
    std::string id;
    std::vector<Node*> checkpoints;
};

#endif // COURSE_H
