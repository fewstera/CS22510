#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include <QMainWindow>
#include "node.h"

namespace Ui {
class CheckpointManager;
}

class CheckpointManager : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CheckpointManager(QWidget *parent = 0);
    std::string nodesFilePath;
    ~CheckpointManager();
public slots:
    void checkpointChanged(int);

private:
    void loadNodes();
    void hideElements();
    Node * getNode(int nodeNumber);
    void parseNodesFile();
    Ui::CheckpointManager *ui;
    std::vector<Node> nodes;
};

#endif // CHECKPOINTMANAGER_H
