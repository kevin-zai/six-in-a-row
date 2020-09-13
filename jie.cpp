#include "jie.h"
#include<QPushButton>

jie::jie(QWidget *parent) : QWidget(parent)
{
    ok.setParent(this);
    ok.setText("ok");
    setWindowTitle("结束");
    this->resize(400,400);
    ok.move(150,250);
    connect(&ok,&QPushButton::clicked,this,
            [=]()
            {
                emit mesignal();
            });
    fgg.setParent(this);
    fgg.move(80,100);
}
