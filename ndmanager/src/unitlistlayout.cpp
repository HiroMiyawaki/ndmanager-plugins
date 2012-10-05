/****************************************************************************
** Form implementation generated from reading ui file '/home/lynn/CMBN/NDManager/ndmanager/src/unitlistlayout.ui'
**
** Created: jeu sep 6 14:47:39 2007
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.7   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "unitlistlayout.h"
#include "unittable.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <q3table.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>

#include <qimage.h>
#include <qpixmap.h>
//Added by qt3to4:
#include <QGridLayout>


/*
 *  Constructs a UnitListLayout as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
UnitListLayout::UnitListLayout(QWidget* parent, const char* name)
    : QWidget( parent, name )
{
    if ( !name )
        setName( "UnitListLayout" );
    UnitListLayoutLayout = new QGridLayout( this);

    layout21 = new QGridLayout;

    layout20 = new QGridLayout;
    spacer10_2_3_2 = new QSpacerItem( 354, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout20->addItem( spacer10_2_3_2, 0, 1 );

    layout19 = new QGridLayout;
    spacer10_2_2 = new QSpacerItem( 20, 16, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout19->addItem( spacer10_2_2, 0, 0 );
    spacer10_2_2_2 = new QSpacerItem( 20, 16, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout19->addItem( spacer10_2_2_2, 0, 2 );
    spacer10_2_3 = new QSpacerItem( 136, 16, QSizePolicy::Expanding, QSizePolicy::Minimum );
    layout19->addItem( spacer10_2_3, 0, 4 );

    addUnitButton = new QPushButton( this, "addUnitButton" );
    addUnitButton->setSizePolicy( QSizePolicy( (QSizePolicy::Policy)0, (QSizePolicy::Policy)0, 0, 0, addUnitButton->sizePolicy().hasHeightForWidth() ) );
    addUnitButton->setMinimumSize( QSize( 104, 0 ) );
    addUnitButton->setMaximumSize( QSize( 104, 32767 ) );

    layout19->addWidget( addUnitButton, 0, 1 );

    removeUnitButton = new QPushButton( this, "removeUnitButton" );
    removeUnitButton->setSizePolicy( QSizePolicy( (QSizePolicy::Policy)0, (QSizePolicy::Policy)0, 0, 0, removeUnitButton->sizePolicy().hasHeightForWidth() ) );
    removeUnitButton->setMinimumSize( QSize( 104, 0 ) );
    removeUnitButton->setMaximumSize( QSize( 104, 32767 ) );

    layout19->addWidget( removeUnitButton, 0, 3 );

    layout20->addMultiCellLayout( layout19, 3, 3, 0, 1 );

    unitTable = new UnitTable( this );
    unitTable->setNumCols( unitTable->numCols() + 1 );
    unitTable->horizontalHeader()->setLabel( unitTable->numCols() - 1, tr( "Group" ) );
    unitTable->setNumCols( unitTable->numCols() + 1 );
    unitTable->horizontalHeader()->setLabel( unitTable->numCols() - 1, tr( "Cluster" ) );
    unitTable->setNumCols( unitTable->numCols() + 1 );
    unitTable->horizontalHeader()->setLabel( unitTable->numCols() - 1, tr( "Structure" ) );
    unitTable->setNumCols( unitTable->numCols() + 1 );
    unitTable->horizontalHeader()->setLabel( unitTable->numCols() - 1, tr( "Type" ) );
    unitTable->setNumCols( unitTable->numCols() + 1 );
    unitTable->horizontalHeader()->setLabel( unitTable->numCols() - 1, tr( "I.D." ) );
    unitTable->setNumCols( unitTable->numCols() + 1 );
    unitTable->horizontalHeader()->setLabel( unitTable->numCols() - 1, tr( "Quality" ) );
    unitTable->setNumCols( unitTable->numCols() + 1 );
    unitTable->horizontalHeader()->setLabel( unitTable->numCols() - 1, tr( "Notes" ) );
    unitTable->setSizePolicy( QSizePolicy( (QSizePolicy::Policy)7, (QSizePolicy::Policy)7, 0, 0, unitTable->sizePolicy().hasHeightForWidth() ) );
    unitTable->setMinimumSize( QSize( 200, 100 ) );
    unitTable->setVScrollBarMode( Q3Table::Auto );
    unitTable->setNumRows( 0 );
    unitTable->setNumCols( 7 );
    unitTable->setSelectionMode( Q3Table::Multi );

    layout20->addMultiCellWidget( unitTable, 1, 1, 0, 1 );

    textLabel4_2_2_4_2_2_2 = new QLabel( this, "textLabel4_2_2_4_2_2_2" );

    layout20->addWidget( textLabel4_2_2_4_2_2_2, 0, 0 );
    spacer96 = new QSpacerItem( 16, 19, QSizePolicy::Minimum, QSizePolicy::Fixed );
    layout20->addItem( spacer96, 2, 0 );

    layout21->addMultiCellLayout( layout20, 0, 1, 2, 2 );
    spacer10_2_3_3 = new QSpacerItem( 30, 16, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout21->addItem( spacer10_2_3_3, 1, 1 );

    UnitListLayoutLayout->addLayout( layout21, 0, 0 );
    languageChange();
    resize( QSize(678, 218).expandedTo(minimumSizeHint()) );

    // tab order
    setTabOrder( unitTable, addUnitButton );
    setTabOrder( addUnitButton, removeUnitButton );
}

/*
 *  Destroys the object and frees any allocated resources
 */
UnitListLayout::~UnitListLayout()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void UnitListLayout::languageChange()
{
    setWindowTitle( tr( "Unit List" ) );
    addUnitButton->setText( tr( "&Add" ) );
    removeUnitButton->setText( tr( "Rem&ove" ) );
    unitTable->horizontalHeader()->setLabel( 0, tr( "Group" ) );
    unitTable->horizontalHeader()->setLabel( 1, tr( "Cluster" ) );
    unitTable->horizontalHeader()->setLabel( 2, tr( "Structure" ) );
    unitTable->horizontalHeader()->setLabel( 3, tr( "Type" ) );
    unitTable->horizontalHeader()->setLabel( 4, tr( "I.D." ) );
    unitTable->horizontalHeader()->setLabel( 5, tr( "Quality" ) );
    unitTable->horizontalHeader()->setLabel( 6, tr( "Notes" ) );
    textLabel4_2_2_4_2_2_2->setText( tr( "Units" ) );
}

#include "unitlistlayout.moc"
