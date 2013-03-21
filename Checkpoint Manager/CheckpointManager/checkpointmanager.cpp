#include "checkpointmanager.h"
#include "ui_checkpointmanager.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

CheckpointManager::CheckpointManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckpointManager){
    this->nodesFilePath = "/Users/fewstera/Documents/CS22510/data/extended/nodes.txt";
    this->entrantsFilePath = "/Users/fewstera/Documents/CS22510/data/extended/entrants.txt";
    this->coursesFilePath = "/Users/fewstera/Documents/CS22510/data/extended/courses.txt";
    this->timesFilePath = "/Users/fewstera/Documents/CS22510/data/extended/new.txt";

    ui->setupUi(this);

    parseNodesFile();
    parseCoursesFile();
    parseEntrantsFile();
    parseTimesFile();

    loadNodes();
    loadEntrants();

    hideElements();

    resize(sizeHint());
}

void CheckpointManager::hideElements(){
    ui->lblCheckpointType->setVisible(false);
    ui->lblCheckpointValue->setVisible(false);

    ui->lblEntrant->setVisible(false);
    ui->inptEntrant->setVisible(false);

    ui->lblArrival->setVisible(false);
    ui->inptArrivalTime->setVisible(false);

    ui->lblEntrantExcluded->setVisible(false);
    ui->inptExcluded->setVisible(false);
    ui->inptExcluded->setCurrentIndex(0);

    ui->lblDTime->setVisible(false);
    ui->inptDTime->setVisible(false);

    ui->lblNote->setText(QString(""));
    ui->lblNote->setVisible(false);

    ui->inptSubmit->setVisible(false);

    this->currentState = 0;
}

void CheckpointManager::loadNodes(){
    ui->inptNode->clear();
    ui->inptNode->addItem("Select a checkpoint", QVariant(-1));
    for(vector<Node>::iterator node = nodes.begin(); node!=nodes.end(); ++node){
        ui->inptNode->addItem(QString::number((*node).getNumber()), QVariant((*node).getNumber()));
    }
}

void CheckpointManager::loadEntrants(){
    ui->inptEntrant->addItem("Select an entrant", QVariant(-1));
    for(vector<Entrant>::iterator entrant = entrants.begin(); entrant!=entrants.end(); ++entrant){
        ui->inptEntrant->addItem(QString((*entrant).getName().c_str()), QVariant((*entrant).getId()));
    }
}

void CheckpointManager::checkpointChanged(int index){
    int nodeNumber = ui->inptNode->itemData(index).toInt();
    if(nodeNumber == -1){
        hideElements();
    }else{
        if(getNode(nodeNumber)->getIsMedical()){
            ui->lblCheckpointValue->setText(QString("Medical checkpoint"));
        }else{
            ui->lblCheckpointValue->setText(QString("Time checkpoint"));
        }
        entrantChanged();

        ui->lblCheckpointType->setVisible(true);
        ui->lblCheckpointValue->setVisible(true);
    }
    resize(sizeHint());
}


void CheckpointManager::entrantChanged(){
    hideElements();

    ui->lblCheckpointType->setVisible(true);
    ui->lblCheckpointValue->setVisible(true);

    ui->lblEntrant->setVisible(true);
    ui->inptEntrant->setVisible(true);

    int entrantId = ui->inptEntrant->itemData(ui->inptEntrant->currentIndex()).toInt();
    if(entrantId != -1){
        parseTimesFile();
        int nodeId = ui->inptNode->itemData(ui->inptNode->currentIndex()).toInt();

        Entrant * entrant = this->getEntrant(entrantId);
        Node * node = this->getNode(nodeId);

        ui->lblArrival->setVisible(true);
        ui->inptArrivalTime->setTime(QTime::currentTime());
        ui->inptArrivalTime->setVisible(true);

        if((*entrant).nextNode()->getNumber()==(*node).getNumber()){
            if((*node).getIsMedical()){
                ui->lblEntrantExcluded->setVisible(true);
                ui->inptExcluded->setVisible(true);

                ui->lblNote->setVisible(true);

                ui->lblDTime->setVisible(true);
                ui->inptDTime->setVisible(true);
                this->currentState = 2;
            }else{
                ui->inptDTime->setTime(QTime::currentTime());
                this->currentState = 1;
            }
        }else{
            ui->lblNote->setText(QString("Note: This entrant will be excluded for going the wrong way"));
            ui->lblNote->setVisible(true);
            this->currentState = 3;
        }

        ui->inptSubmit->setVisible(true);
    }
    resize(sizeHint());
}

void CheckpointManager::entrantExcludedChanged(){
    if(ui->inptExcluded->currentIndex()==1){
        ui->lblNote->setText(QString("Note: This entrant will be excluded for medical reasons"));
        ui->lblNote->setVisible(true);
    }else{
        ui->lblNote->setVisible(false);
    }
    resize(sizeHint());
}

void CheckpointManager::submitPressed(){
    //
}

Node * CheckpointManager::getNode(int nodeNumber){
    for(vector<Node>::iterator node = nodes.begin(); node!=nodes.end(); ++node){
        if((*node).getNumber()==nodeNumber)
            return &(*node);
    }
    return NULL;
}

Course * CheckpointManager::getCourse(string courseId){
    for(vector<Course>::iterator course = courses.begin(); course!=courses.end(); ++course){
        if((*course).getId().compare(courseId)==0)
            return &(*course);
    }
    return NULL;
}

Entrant * CheckpointManager::getEntrant(int id){
    for(vector<Entrant>::iterator entrant = entrants.begin(); entrant!=entrants.end(); ++entrant){
        if((*entrant).getId()==id)
            return &(*entrant);
    }
    return NULL;
}

void CheckpointManager::resetEntrants(){
    for(vector<Entrant>::iterator entrant = entrants.begin(); entrant!=entrants.end(); ++entrant){
        (*entrant).reset();
    }
}

void CheckpointManager::removeEntrant(int id){
    for(vector<Entrant>::iterator entrant = entrants.begin(); entrant!=entrants.end(); ++entrant){
        int entrantId = (*entrant).getId();
        if(entrantId==id){
            ui->inptEntrant->removeItem(ui->inptEntrant->findData(QVariant(entrantId)));
            entrants.erase(entrant);
            break;
        }
    }
}


//Load Files
void CheckpointManager::parseNodesFile(){
    ifstream nodesFile(nodesFilePath.c_str(), ios::in);

    if (!nodesFile){
        QMessageBox msgBox;
         msgBox.setText("Error!");
         msgBox.setInformativeText("Error parsing nodes file. The program will now exit.");
         msgBox.setIcon(QMessageBox::Critical);
         msgBox.exec();
         exit (EXIT_FAILURE);
    }

    while(nodesFile){
        string nodeNumber;
        string nodeType;
        getline(nodesFile, nodeNumber, ' ');
        getline(nodesFile, nodeType);
        if((nodeType.compare("JN")!=0) && (!nodeNumber.empty()) ){
            bool isMedical = (nodeType.compare("MC")==0);
            int nodeNo = atoi(nodeNumber.c_str());
            nodes.push_back(Node(nodeNo, isMedical));
        }
    }
}

void CheckpointManager::parseEntrantsFile(){
    ifstream entrantsFile(entrantsFilePath.c_str(), ios::in);

    if (!entrantsFile){
        QMessageBox msgBox;
         msgBox.setText("Error!");
         msgBox.setInformativeText("Error parsing entrants file. The program will now exit.");
         msgBox.setIcon(QMessageBox::Critical);
         msgBox.exec();
         exit (EXIT_FAILURE);
    }

    while(entrantsFile){
        string entrantId, courseId, entrantName;
        getline(entrantsFile, entrantId, ' ');
        getline(entrantsFile, courseId, ' ');
        getline(entrantsFile, entrantName);
        if(!entrantId.empty()){
            int entrantIdNo = atoi(entrantId.c_str());
            Course* entrantCourse = getCourse(courseId);
            entrants.push_back(Entrant(entrantIdNo, entrantName, entrantCourse));
        }
    }
}

void CheckpointManager::parseCoursesFile(){
    ifstream coursesFile(coursesFilePath.c_str(), ios::in);

    if (!coursesFile){
        QMessageBox msgBox;
         msgBox.setText("Error!");
         msgBox.setInformativeText("Error parsing courses file. The program will now exit.");
         msgBox.setIcon(QMessageBox::Critical);
         msgBox.exec();
         exit (EXIT_FAILURE);
    }

    while(coursesFile){
        string courseId;
        string noNodes;

        getline(coursesFile, courseId, ' ');
        getline(coursesFile, noNodes, ' ');
        if(!courseId.empty()){
            int intNoNodes = atoi(noNodes.c_str());
            Course* newCourse = new Course(courseId);
            string nodeNo;
            for(int i = 0; i<(intNoNodes); i++){
                if(i<(intNoNodes-1))
                    getline(coursesFile, nodeNo, ' ');
                else
                    getline(coursesFile, nodeNo);
                Node* nodeToAdd = getNode(atoi(nodeNo.c_str()));
                if(nodeToAdd!=NULL){
                    (*newCourse).addCheckpoint(nodeToAdd);
                }
            }
            this->courses.push_back((*newCourse));
        }
    }
}

void CheckpointManager::parseTimesFile(){
    resetEntrants();

    ifstream timesFile(timesFilePath.c_str());

    if (!timesFile){
        QMessageBox msgBox;
         msgBox.setText("Error!");
         msgBox.setInformativeText("Error parsing times file. The program will now exit.");
         msgBox.setIcon(QMessageBox::Critical);
         msgBox.exec();
         exit (EXIT_FAILURE);
    }

    while(timesFile){
        string nodeType, nodeId, entrantId, time;
        getline(timesFile, nodeType, ' ');
        getline(timesFile, nodeId, ' ');
        getline(timesFile, entrantId, ' ');
        getline(timesFile, time);
        if(!nodeType.empty()){
            int intEntrantId = atoi(entrantId.c_str());
            if((nodeType.compare("T")==0)||(nodeType.compare("D")==0)){
                Entrant * entrant = getEntrant(intEntrantId);
                if(entrant!=NULL){
                    (*entrant).incrementVisitedNodes();
                    if((*entrant).nextNode()==NULL){
                        removeEntrant((*entrant).getId());
                    }
                }
            }else if(nodeType.compare("I")==0){
                removeEntrant(intEntrantId);
            }
        }
    }
    timesFile.close();
}



//Deconstuctor
CheckpointManager::~CheckpointManager(){
    delete ui;
}
