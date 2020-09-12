#include "widget.h"
#include<QPainter>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("六子旗");
    this->resize(1200,1200);
    bu1.setParent(this);
    bu2.setParent(this);
    bu1.setText("开始");
    bu2.setText("退出");
    bu1.setGeometry(480,200,240,120);
    bu2.setGeometry(480,800,240,120);
    connect(&bu2,&QPushButton::clicked,this,&Widget::close);
    connect(&bu1,&QPushButton::clicked,this,
            [=]()
            {
            this->hide();
            o.show();
            });
    connect(&o,&mo::mysignal,this,
            [=]()
            {
                o.hide();
                this->show();
            });
}

void Widget::paintEvent(QPaintEvent *)
{
     QPainter p(this);
     p.drawPixmap(rect(),QPixmap(":/new/prefix1/template.png"));
     p.end();
}

Widget::~Widget()
{

}
