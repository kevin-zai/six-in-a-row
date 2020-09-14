#ifndef QI_H
#define QI_H

#include <QWidget>
#include<QPushButton>
#include"fault.h"
#include"jie.h"
#include<QLabel>

class qi : public QWidget
{
    Q_OBJECT
public:
    explicit qi(QWidget *parent = nullptr);
    int z[23][23];
    int mos;
    QLabel d2;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*e);

signals:
    void signal1();

public slots:

private:
    QPushButton p1;
    QPushButton p2;
    QPushButton p3;
    int flag=1;
    int xx,yy,zero,one,ke;
    const int SIZE=20;
    const int WIDTH=40;
    const int x=40,y=40;
    fault fa;
    jie ji;
    QLabel d1;

};

#endif // QI_H
