#pragma once

#include <QHeaderView>
#include <QMessageBox>
#include <QObject>
#include <QtGui>
#include <iostream>

class myHeaderView : public QHeaderView
{
Q_OBJECT
public:
      myHeaderView():QHeaderView(Qt::Horizontal)
      {
    setClickable(true);
    connect(this,SIGNAL(sectionClicked(int)),this,SLOT(sectionClicked(int)));
      };
      ~myHeaderView(){};

public slots:
      void sectionClicked(int index)
      {
    QMessageBox::about(this,"Hi! Header Click Detected!"
              ,"Index:"+QString::number(index));
      };

};
