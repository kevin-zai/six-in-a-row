#ifndef MO_H
#define MO_H

#include <QWidget>
#include<QPushButton>
#include"qi.h"

class mo : public QWidget
{
    Q_OBJECT
public:
    explicit mo(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

signals:
    void mysignal();

public slots:

private:
    QPushButton a1;
    QPushButton a2;
    QPushButton a3;
    QPushButton a4;
    qi qip;
};

#endif // MO_H
