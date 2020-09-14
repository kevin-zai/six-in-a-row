#include "quren.h"
#include<QPushButton>

quren::quren(QWidget *parent) : QWidget(parent)
{
    ok.setParent(this);
    ok.setText("是");
    no.setParent(this);
    no.setText("否");
    setWindowTitle("和棋");
    this->resize(400,400);
    ok.move(75,250);
    no.move(200,250);
    connect(&ok,&QPushButton::clicked,this,
            [=]()
            {
                this->close();
                ji.fgg.setText("和      棋");
                ji.show();
            });
    connect(&no,&QPushButton::clicked,this,
            [=]()
            {
                this->close();
            });
    fgg.setParent(this);
    fgg.move(100,100);
    fgg.setText("对方请求和棋，是否同意");

    connect(&ji,&jie::mesignal,this,
            [=]()
            {
                emit signal2();
            });
}
