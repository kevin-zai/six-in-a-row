#ifndef JIE_H
#define JIE_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>

class jie : public QWidget
{
    Q_OBJECT
public:
    explicit jie(QWidget *parent = nullptr);
    QLabel fgg;
protected:


signals:
    void mesignal();

public slots:

private:
    QPushButton ok;

};

#endif // JIE_H
