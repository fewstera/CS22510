/********************************************************************************
** Form generated from reading UI file 'checkpointmanager.ui'
**
** Created: Fri Mar 22 13:57:14 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKPOINTMANAGER_H
#define UI_CHECKPOINTMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckpointManager
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblNode;
    QComboBox *inptNode;
    QLabel *lblCheckpointType;
    QLabel *lblCheckpointValue;
    QLabel *lblEntrant;
    QComboBox *inptEntrant;
    QLabel *lblArrival;
    QTimeEdit *inptArrivalTime;
    QLabel *lblEntrantExcluded;
    QComboBox *inptExcluded;
    QLabel *lblDTime;
    QTimeEdit *inptDTime;
    QPushButton *inptSubmit;
    QLabel *lblNote;

    void setupUi(QWidget *CheckpointManager)
    {
        if (CheckpointManager->objectName().isEmpty())
            CheckpointManager->setObjectName(QString::fromUtf8("CheckpointManager"));
        CheckpointManager->resize(295, 306);
        horizontalLayout = new QHBoxLayout(CheckpointManager);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(CheckpointManager);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        lblNode = new QLabel(groupBox);
        lblNode->setObjectName(QString::fromUtf8("lblNode"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblNode);

        inptNode = new QComboBox(groupBox);
        inptNode->setObjectName(QString::fromUtf8("inptNode"));

        formLayout->setWidget(0, QFormLayout::FieldRole, inptNode);

        lblCheckpointType = new QLabel(groupBox);
        lblCheckpointType->setObjectName(QString::fromUtf8("lblCheckpointType"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblCheckpointType);

        lblCheckpointValue = new QLabel(groupBox);
        lblCheckpointValue->setObjectName(QString::fromUtf8("lblCheckpointValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lblCheckpointValue);

        lblEntrant = new QLabel(groupBox);
        lblEntrant->setObjectName(QString::fromUtf8("lblEntrant"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblEntrant);

        inptEntrant = new QComboBox(groupBox);
        inptEntrant->setObjectName(QString::fromUtf8("inptEntrant"));

        formLayout->setWidget(2, QFormLayout::FieldRole, inptEntrant);

        lblArrival = new QLabel(groupBox);
        lblArrival->setObjectName(QString::fromUtf8("lblArrival"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblArrival);

        inptArrivalTime = new QTimeEdit(groupBox);
        inptArrivalTime->setObjectName(QString::fromUtf8("inptArrivalTime"));
        inptArrivalTime->setTime(QTime(0, 0, 0));

        formLayout->setWidget(4, QFormLayout::FieldRole, inptArrivalTime);

        lblEntrantExcluded = new QLabel(groupBox);
        lblEntrantExcluded->setObjectName(QString::fromUtf8("lblEntrantExcluded"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblEntrantExcluded);

        inptExcluded = new QComboBox(groupBox);
        inptExcluded->setObjectName(QString::fromUtf8("inptExcluded"));

        formLayout->setWidget(5, QFormLayout::FieldRole, inptExcluded);

        lblDTime = new QLabel(groupBox);
        lblDTime->setObjectName(QString::fromUtf8("lblDTime"));
        lblDTime->setEnabled(true);

        formLayout->setWidget(6, QFormLayout::LabelRole, lblDTime);

        inptDTime = new QTimeEdit(groupBox);
        inptDTime->setObjectName(QString::fromUtf8("inptDTime"));

        formLayout->setWidget(6, QFormLayout::FieldRole, inptDTime);

        inptSubmit = new QPushButton(groupBox);
        inptSubmit->setObjectName(QString::fromUtf8("inptSubmit"));

        formLayout->setWidget(7, QFormLayout::FieldRole, inptSubmit);


        verticalLayout->addLayout(formLayout);

        lblNote = new QLabel(groupBox);
        lblNote->setObjectName(QString::fromUtf8("lblNote"));
        lblNote->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        lblNote->setWordWrap(true);

        verticalLayout->addWidget(lblNote);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(CheckpointManager);
        QObject::connect(inptNode, SIGNAL(currentIndexChanged(int)), CheckpointManager, SLOT(checkpointChanged(int)));
        QObject::connect(inptEntrant, SIGNAL(currentIndexChanged(int)), CheckpointManager, SLOT(entrantChanged()));
        QObject::connect(inptExcluded, SIGNAL(currentIndexChanged(int)), CheckpointManager, SLOT(entrantExcludedChanged()));
        QObject::connect(inptSubmit, SIGNAL(clicked()), CheckpointManager, SLOT(submitPressed()));

        QMetaObject::connectSlotsByName(CheckpointManager);
    } // setupUi

    void retranslateUi(QWidget *CheckpointManager)
    {
        CheckpointManager->setWindowTitle(QApplication::translate("CheckpointManager", "Checkpoint Manager", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CheckpointManager", "Add new entrant time", 0, QApplication::UnicodeUTF8));
        lblNode->setText(QApplication::translate("CheckpointManager", "Checkpoint Number", 0, QApplication::UnicodeUTF8));
        lblCheckpointType->setText(QApplication::translate("CheckpointManager", "Checkpoint Type:", 0, QApplication::UnicodeUTF8));
        lblCheckpointValue->setText(QString());
        lblEntrant->setText(QApplication::translate("CheckpointManager", "Entrant:", 0, QApplication::UnicodeUTF8));
        lblArrival->setText(QApplication::translate("CheckpointManager", "Arrival Time:", 0, QApplication::UnicodeUTF8));
        lblEntrantExcluded->setText(QApplication::translate("CheckpointManager", "Entrant Excluded: ", 0, QApplication::UnicodeUTF8));
        inptExcluded->clear();
        inptExcluded->insertItems(0, QStringList()
         << QApplication::translate("CheckpointManager", "No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CheckpointManager", "Yes", 0, QApplication::UnicodeUTF8)
        );
        lblDTime->setText(QApplication::translate("CheckpointManager", "Departure Time:", 0, QApplication::UnicodeUTF8));
        inptSubmit->setText(QApplication::translate("CheckpointManager", "Submit", 0, QApplication::UnicodeUTF8));
        lblNote->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckpointManager: public Ui_CheckpointManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKPOINTMANAGER_H
