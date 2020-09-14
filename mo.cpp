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
    a1.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a2.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a3.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    a4.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    connect(&a1,&QPushButton::clicked,this,
            [=]()
            {
                for(int i=1;i<22;i++)for(int j=1;j<22;j++)qip.z[i][j]=0;
                for(int i=1;i<22;i++){qip.z[i][0]=2;qip.z[i][22]=2;}
                for(int i=1;i<22;i++){qip.z[0][i]=2;qip.z[22][i]=2;}
                qip.mos=1;
                qip.d2.setText("白棋：player2");
                qip.show();
                this->hide();
            });
    connect(&a2,&QPushButton::clicked,this,
            [=]()
            {
                for(int i=1;i<22;i++)for(int j=1;j<22;j++)qip.z[i][j]=0;
                for(int i=1;i<22;i++){qip.z[i][0]=2;qip.z[i][22]=2;}
                for(int i=1;i<22;i++){qip.z[0][i]=2;qip.z[22][i]=2;}
                qip.mos=2;
                qip.d2.setText("白棋：PC");
                qip.show();
                this->hide();
            });
    connect(&a3,&QPushButton::clicked,this,
            [=]()
            {
        for(int i=1;i<22;i++)for(int j=1;j<22;j++)qip2.z[i][j]=0;
        for(int i=1;i<22;i++){qip2.z[i][0]=2;qip2.z[i][22]=2;}
        for(int i=1;i<22;i++){qip2.z[0][i]=2;qip2.z[22][i]=2;}
        qip2.start=1;
        qip2.show();
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
    connect(&qip2,&qi2::signal1,this,
            [=]()
            {
                qip2.hide();
                this->show();
            });

}

void mo::paintEvent(QPaintEvent *)
{
     QPainter q(this);
     q.drawPixmap(rect(),QPixmap(":/new/prefix1/template.png"));
     q.end();
}

