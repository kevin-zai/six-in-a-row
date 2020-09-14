#include "jie.h"
#include<QPushButton>

jie::jie(QWidget *parent) : QWidget(parent)
{
    ok.setParent(this);
    ok.setText("ok");
    setWindowTitle("结束");
    this->resize(400,400);
    ok.move(150,250);
    fgg.setStyleSheet("font: bold 30px;");
    connect(&ok,&QPushButton::clicked,this,
            [=]()
            {
                emit mesignal();
            });
    fgg.resize(300,100);
    fgg.setParent(this);
    fgg.move(100,100);
}
