#ifndef QUREN_H
#define QUREN_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include"jie.h"

class quren : public QWidget
{
    Q_OBJECT
public:
    explicit quren(QWidget *parent = nullptr);

protected:


signals:
    void signal2();


public slots:

private:
    QPushButton ok;
    QPushButton no;
    QLabel fgg;
    jie ji;
};

#endif // QUREN_H
