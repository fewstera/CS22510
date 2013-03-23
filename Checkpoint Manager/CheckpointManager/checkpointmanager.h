#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include <QWidget>
#include "node.h"
#include "entrant.h"
#include "course.h"

namespace Ui {
class CheckpointManager;
}

class CheckpointManager : public QWidget
{
    Q_OBJECT

public:
    explicit CheckpointManager(QWidget *parent = 0);
    std::string nodesFilePath;
    std::string entrantsFilePath;
    std::string coursesFilePath;
    std::string timesFilePath;

    ~CheckpointManager();
public slots:
    void checkpointChanged(int);
    void entrantChanged();
    void entrantExcludedChanged();
    void submitPressed();

private:
    int currentState; //Current state of the form (0 unfinished, 1 time, 
    //2 medical, 3 excluded)

    void loadNodes();
    void loadEntrants();
    void hideElements();

    Course * getCourse(std::string courseId);
    Node * getNode(int nodeNumber);
    Entrant * getEntrant(int id);

    void removeEntrant(int id);

    void resetEntrants();

    void parseNodesFile();
    void parseEntrantsFile();
    void parseCoursesFile();
    void parseTimesFile();

    Ui::CheckpointManager *ui;
    std::vector<Node> nodes;
    std::vector<Entrant> entrants;
    std::vector<Course> courses;
};

#endif // CHECKPOINTMANAGER_H
