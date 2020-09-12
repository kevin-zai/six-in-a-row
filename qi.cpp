#include "qi.h"
#include<QPainter>
#include<QPushButton>
qi::qi(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("游戏");
    this->resize(1200,1200);
    p1.setParent(this);
    p1.setText("返回");
    p1.setGeometry(1100,1010,80,80);
    connect(&p1,&QPushButton::clicked,this,
                    [=]()
                    {
                        emit signal1();
                    });
}

void qi::paintEvent(QPaintEvent *)
{
    QPainter pp(this);
    pp.drawPixmap(rect(),QPixmap(":/new/prefix1/template.png"));
    pp.setPen(QPen(Qt::lightGray,2,Qt::SolidLine));//钢笔工具：颜色，线号，实线
    const int SIZE=10;
    const int WIDTH=80;
    const int x=80,y=80;
    //画SIZE+1条横线
    for(int i=0;i<SIZE+1;i++)
      {
        pp.drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);//画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
      }
    //画SIZE+1条竖线
    for(int i=0;i<SIZE+1;i++)
      {
        pp.drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
      }
     pp.end();
}
