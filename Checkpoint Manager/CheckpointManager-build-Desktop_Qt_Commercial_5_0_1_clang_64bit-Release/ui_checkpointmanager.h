/********************************************************************************
** Form generated from reading UI file 'checkpointmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKPOINTMANAGER_H
#define UI_CHECKPOINTMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckpointManager
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblNode;
    QComboBox *inptNode;
    QLabel *lblCheckpointType;
    QLabel *lblEntrant;
    QComboBox *inptEntrant;
    QLabel *lblArrival;
    QTimeEdit *inptArrivalTime;
    QLabel *lblEntrantExcluded;
    QComboBox *inptExcluded;
    QLabel *lblDTime;
    QTimeEdit *inptDTime;
    QLabel *lblCheckpointValue;
    QLabel *lblNote;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CheckpointManager)
    {
        if (CheckpointManager->objectName().isEmpty())
            CheckpointManager->setObjectName(QStringLiteral("CheckpointManager"));
        CheckpointManager->resize(295, 281);
        centralWidget = new QWidget(CheckpointManager);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        lblNode = new QLabel(groupBox);
        lblNode->setObjectName(QStringLiteral("lblNode"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblNode);

        inptNode = new QComboBox(groupBox);
        inptNode->setObjectName(QStringLiteral("inptNode"));

        formLayout->setWidget(0, QFormLayout::FieldRole, inptNode);

        lblCheckpointType = new QLabel(groupBox);
        lblCheckpointType->setObjectName(QStringLiteral("lblCheckpointType"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblCheckpointType);

        lblEntrant = new QLabel(groupBox);
        lblEntrant->setObjectName(QStringLiteral("lblEntrant"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblEntrant);

        inptEntrant = new QComboBox(groupBox);
        inptEntrant->setObjectName(QStringLiteral("inptEntrant"));

        formLayout->setWidget(2, QFormLayout::FieldRole, inptEntrant);

        lblArrival = new QLabel(groupBox);
        lblArrival->setObjectName(QStringLiteral("lblArrival"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblArrival);

        inptArrivalTime = new QTimeEdit(groupBox);
        inptArrivalTime->setObjectName(QStringLiteral("inptArrivalTime"));

        formLayout->setWidget(4, QFormLayout::FieldRole, inptArrivalTime);

        lblEntrantExcluded = new QLabel(groupBox);
        lblEntrantExcluded->setObjectName(QStringLiteral("lblEntrantExcluded"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblEntrantExcluded);

        inptExcluded = new QComboBox(groupBox);
        inptExcluded->setObjectName(QStringLiteral("inptExcluded"));

        formLayout->setWidget(5, QFormLayout::FieldRole, inptExcluded);

        lblDTime = new QLabel(groupBox);
        lblDTime->setObjectName(QStringLiteral("lblDTime"));
        lblDTime->setEnabled(true);

        formLayout->setWidget(6, QFormLayout::LabelRole, lblDTime);

        inptDTime = new QTimeEdit(groupBox);
        inptDTime->setObjectName(QStringLiteral("inptDTime"));

        formLayout->setWidget(6, QFormLayout::FieldRole, inptDTime);

        lblCheckpointValue = new QLabel(groupBox);
        lblCheckpointValue->setObjectName(QStringLiteral("lblCheckpointValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lblCheckpointValue);


        verticalLayout->addLayout(formLayout);

        lblNote = new QLabel(groupBox);
        lblNote->setObjectName(QStringLiteral("lblNote"));

        verticalLayout->addWidget(lblNote);

        lblArrival->raise();
        lblNote->raise();

        horizontalLayout->addWidget(groupBox);

        CheckpointManager->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CheckpointManager);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CheckpointManager->setStatusBar(statusBar);
        QWidget::setTabOrder(inptNode, inptEntrant);
        QWidget::setTabOrder(inptEntrant, inptArrivalTime);
        QWidget::setTabOrder(inptArrivalTime, inptExcluded);
        QWidget::setTabOrder(inptExcluded, inptDTime);

        retranslateUi(CheckpointManager);
        QObject::connect(inptNode, SIGNAL(currentIndexChanged(int)), CheckpointManager, SLOT(checkpointChanged(int)));

        QMetaObject::connectSlotsByName(CheckpointManager);
    } // setupUi

    void retranslateUi(QMainWindow *CheckpointManager)
    {
        CheckpointManager->setWindowTitle(QApplication::translate("CheckpointManager", "Checkpoint Manager", 0));
        groupBox->setTitle(QApplication::translate("CheckpointManager", "Add new entrant time", 0));
        lblNode->setText(QApplication::translate("CheckpointManager", "Checkpoint Number", 0));
        lblCheckpointType->setText(QApplication::translate("CheckpointManager", "Checkpoint Type:", 0));
        lblEntrant->setText(QApplication::translate("CheckpointManager", "Entrant:", 0));
        lblArrival->setText(QApplication::translate("CheckpointManager", "Arrival Time:", 0));
        lblEntrantExcluded->setText(QApplication::translate("CheckpointManager", "Entrant Excluded: ", 0));
        inptExcluded->clear();
        inptExcluded->insertItems(0, QStringList()
         << QApplication::translate("CheckpointManager", "No", 0)
         << QApplication::translate("CheckpointManager", "Yes", 0)
        );
        lblDTime->setText(QApplication::translate("CheckpointManager", "Departure Time:", 0));
        lblCheckpointValue->setText(QString());
        lblNote->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckpointManager: public Ui_CheckpointManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKPOINTMANAGER_H
