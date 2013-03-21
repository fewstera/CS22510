#include "checkpointmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CheckpointManager w;
    w.show();
    
    return a.exec();
}
