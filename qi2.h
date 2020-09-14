#ifndef QI2_H
#define QI2_H

#include <QWidget>
#include<QPushButton>
#include"fault.h"
#include"jie.h"

class qi2 : public QWidget
{
    Q_OBJECT
public:
    explicit qi2(QWidget *parent = nullptr);
    int z[23][23];
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*e);

signals:
    void signal1();

public slots:

private:
    QPushButton p1;
    QPushButton p2;
    int flag=1;

    int xx,yy;
    const int SIZE=20;
    const int WIDTH=40;
    const int x=40,y=40;
    fault fa;
    jie ji;
};
#endif // QI2_H
