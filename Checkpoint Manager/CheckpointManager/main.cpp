#include "checkpointmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    if(argc<4){
        std::cout << "\n\nPlease run the application as follows"
                " \"./CheckpointManager node.txt entrants.txt course.txt"
                " times.txt\" without the qoutes\n\n\n\n";
        return 0;
    }
    QApplication a(argc, argv);
    CheckpointManager w;
    w.show();
    
    return a.exec();
}
