/***************************************************************************
 *   Copyright (C) 2004 by Lynn Hazan                                      *
 *   lynn.hazan@myrealbox.com                                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
//include files for the application
#include "parameterpage.h"

// include files for QT
#include <qwidget.h>
#include <q3table.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <QComboBox>
//Added by qt3to4:
#include <QEvent>
#include <QVector>
#include <QList>
#include <QDebug>

ParameterPage::ParameterPage(bool expertMode,QWidget *parent)
    : ParameterLayout(parent),
      valueModified(false),
      descriptionModified(false)
{
    status<<tr("Mandatory")<<tr("Optional")<<tr("Dynamic");
    ddList.append(2);
#ifdef KDAB_PENDING


    for(int i = 0;i<parameterTable->numCols();++i)
        parameterTable->setColumnStretchable(i,true);
#endif


    //If the export mode is not set, only the value column is editable
    if(!expertMode){
       //KDAB_PENDING parameterTable->setColumnReadOnly(0,true);
        //KDAB_PENDING parameterTable->setColumnReadOnly(2,true);

        addButton->setEnabled(false);
        removeButton->setEnabled(false);
        nameLineEdit->setReadOnly(true);
    }
    else{
        connect(addButton,SIGNAL(clicked()),this,SLOT(addParameter()));
        connect(removeButton,SIGNAL(clicked()),this,SLOT(removeParameter()));
        connect(nameLineEdit,SIGNAL(returnPressed()),this,SLOT(changeCaption()));
        connect(nameLineEdit,SIGNAL(lostFocus()),this,SLOT(changeCaption()));
    }

    //install a filter on the groupTable in order to validate the entries
    parameterTable->installEventFilter(this);


    connect(parameterTable, SIGNAL(cellChanged(int,int)),this, SLOT(propertyModified(int,int)));//does not seem to work (see the hack with the eventfiler)
}


ParameterPage::~ParameterPage(){}

bool ParameterPage::eventFilter(QObject* object,QEvent* event){
    QString name = object->objectName();
#ifdef KDAB_PENDING
    //hack, if the event is KeyRelease this means that there was a modification
    if(name.indexOf("parameterTable") != -1 && event->type() == QEvent::KeyRelease){
        if(parameterTable->currentColumn() == 1)
            valueModified = true;
        else
            descriptionModified = true;

        return true;
    }
    else return QWidget::eventFilter(object,event);
#endif
}

void ParameterPage::propertyModified(int, int column){
    if(column == 1)
        valueModified = true;
    else
        descriptionModified = true;
}

QMap<int, QStringList > ParameterPage::getParameterInformation(){
    QMap<int, QStringList > parameterInformation;
    int paramNb = 1;
    for(int i =0; i<parameterTable->rowCount();++i){
        QStringList information;
        QString item = parameterTable->item(i,0)->text();
        QString name = item.simplified();
        if(name == " ")
            continue;
        information.append(name);
        for(int j = 1;j < parameterTable->columnCount(); ++j){
            QString text;
            if(ddList.contains(j)) {
                text = (static_cast<QComboBox*>(parameterTable->cellWidget(i,j)))->currentText();
            }
            else
                text = parameterTable->item(i,j)->text();
            information.append(text.simplified());
        }

        parameterInformation.insert(paramNb,information);
        paramNb++;
    }
    return parameterInformation;
}

void ParameterPage::setParameterInformation(const QMap<int, QStringList >& parameters){
    //Clean the parameterTable, just in case, before creating empty rows.
    parameterTable->clearContents();
    parameterTable->setRowCount(parameters.count());

    QMap<int,QStringList >::ConstIterator iterator;
    //The iterator gives the keys sorted.
    for(iterator = parameters.constBegin(); iterator != parameters.constEnd(); ++iterator){
        const QStringList parameterInfo = iterator.data();

        for(uint i=0;i<parameterInfo.count();++i){
            if(ddList.contains(i)){
                QComboBox *combo = new QComboBox;
                combo->addItems(status);
                parameterTable->setCellWidget(iterator.key(),i,combo);
            } else {
                parameterTable->setItem(iterator.key(),i,new QTableWidgetItem(parameterInfo[i]));
            }

            //parameterTable->adjustColumn(i);
        }
    }//end of parameters loop
}


void ParameterPage::addParameter(){
    descriptionModified = true;
    parameterTable->insertRow(parameterTable->rowCount());

    parameterTable->setItem(parameterTable->rowCount() - 1,0,new QTableWidgetItem());

    parameterTable->setItem(parameterTable->rowCount() - 1,1,new QTableWidgetItem());

    //Add the comboxItem in the status column
    QComboBox *combo = new QComboBox;
    combo->addItems(status);
    parameterTable->setCellWidget(parameterTable->rowCount() - 1,2,combo);
}

void ParameterPage::removeParameter(){
    #ifdef KDAB_PENDING
    descriptionModified = true;
    int nbSelections = parameterTable->numSelections();
    if(nbSelections > 0){
        QList< QVector<int> > rowsToRemove;
        //Look up the rows to be removed
        for(int j = 0; j < nbSelections;++j){
            Q3TableSelection selection = parameterTable->selection(j);
            bool active = selection.isActive();
            if(active){
                int nbRows = selection.bottomRow() - selection.topRow() + 1;
                QVector<int> rows(nbRows);
                for(int i = 0; i < nbRows;++i){
                    rows[i] = selection.topRow() + i;
                }
                rowsToRemove.append(rows);
            }
        }
        //Actually remove the rows
        QList< QVector<int> >::iterator iterator;
        for(iterator = rowsToRemove.begin(); iterator != rowsToRemove.end(); ++iterator) parameterTable->removeRows(*iterator);
    }
#endif
}

void ParameterPage::changeCaption()
{
    QString name = nameLineEdit->text();
    if(name.isEmpty() && !name.contains("New Script-"))
        emit nameChanged(tr("Unknown"));
    else
        emit nameChanged(name);
}



#include "parameterpage.moc"
