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

    ui->setupUi(this);

    parseNodesFile();

    hideElements();
    loadNodes();

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

    ui->lblDTime->setVisible(false);
    ui->inptDTime->setVisible(false);

    ui->lblNote->setVisible(false);
}

void CheckpointManager::loadNodes(){
    ui->inptNode->addItem("Select a checkpoint", QVariant(-1));
    for(vector<Node>::iterator node = nodes.begin(); node!=nodes.end(); ++node){
        ui->inptNode->addItem(QString::number((*node).getNumber()), QVariant((*node).getNumber()));
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

        ui->lblCheckpointType->setVisible(true);
        ui->lblCheckpointValue->setVisible(true);
    }
}

Node * CheckpointManager::getNode(int nodeNumber){
    for(vector<Node>::iterator node = nodes.begin(); node!=nodes.end(); ++node){
        if((*node).getNumber()==nodeNumber)
            return &(*node);
    }
    return NULL;
}

//Deconstuctor
CheckpointManager::~CheckpointManager(){
    delete ui;
}
