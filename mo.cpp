#include "mo.h"
#include<QPainter>
#include<QPushButton>
mo::mo(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("请选择模式");
    this->resize(1200,1200);
    a1.setParent(this);
    a1.setText("人人模式");
    a1.setGeometry(480,110,240,120);
    a2.setParent(this);
    a2.setText("人机模式");
    a2.setGeometry(480,390,240,120);
    a3.setParent(this);
    a3.setText("机机模式");
    a3.setGeometry(480,670,240,120);
    a4.setParent(this);
    a4.setText("返回");
    a4.setGeometry(480,950,240,120);
    connect(&a1,&QPushButton::clicked,this,
            [=]()
            {
                qip.show();
                this->hide();
            });
    connect(&a2,&QPushButton::clicked,this,
            [=]()
            {
                qip2.show();
                this->hide();
            });
    connect(&a3,&QPushButton::clicked,this,
            [=]()
            {
                qip.show();
                this->hide();
            });
    connect(&a4,&QPushButton::clicked,this,
            [=]()
            {
                emit mysignal();
            });
    connect(&qip,&qi::signal1,this,
            [=]()
            {
                qip.hide();
                this->show();
            });

}

void mo::paintEvent(QPaintEvent *)
{
     QPainter q(this);
     q.drawPixmap(rect(),QPixmap(":/new/prefix1/template.png"));
     q.end();
}

