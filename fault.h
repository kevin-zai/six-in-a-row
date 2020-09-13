#ifndef FAULT_H
#define FAULT_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>

class fault : public QWidget
{
    Q_OBJECT
public:
    explicit fault(QWidget *parent = nullptr);

protected:


signals:

public slots:

private:
    QPushButton ok;
    QLabel fg;
};


#endif // FAULT_H
