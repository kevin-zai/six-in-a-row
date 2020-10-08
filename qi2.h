#ifndef QI2_H
#define QI2_H

#include <QWidget>
#include<QPushButton>
#include"fault.h"
#include"jie.h"
#include<QLabel>

class qi2 : public QWidget
{
    Q_OBJECT
public:
    explicit qi2(QWidget *parent = nullptr);
    int z[23][23];
    int start=1;
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);

signals:
    void signal1();

public slots:

private:
    QPushButton p1;
    QPushButton p2;
    QPushButton p3;
    QPushButton p4;
    QPushButton p5;
    int cx[500];
    int cy[500];
    int cc=0;
    int flag=1;
    int xx,yy,zero,one;

    const int SIZE=20;
    const int WIDTH=40;
    const int x=40,y=40;
    fault fa;
    jie ji;
    QLabel d1;
    QLabel d2;

};
#endif // QI2_H
