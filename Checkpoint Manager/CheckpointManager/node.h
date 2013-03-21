#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int number, bool isMedical);
    int getNumber();
    bool getIsMedical();
private:
    int number;
    bool isMedical;
};

#endif // NODE_H
