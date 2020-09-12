#ifndef QI_H
#define QI_H

#include <QWidget>
#include<QPushButton>


class qi : public QWidget
{
    Q_OBJECT
public:
    explicit qi(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

signals:
    void signal1();

public slots:

private:
    QPushButton p1;

};

#endif // QI_H
