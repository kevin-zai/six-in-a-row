#include "fault.h"
#include<QPushButton>

fault::fault(QWidget *parent) : QWidget(parent)
{
    ok.setParent(this);
    ok.setText("ok");
    setWindowTitle("错误");
    this->resize(400,400);
    ok.move(150,250);
    connect(&ok,&QPushButton::clicked,this,&fault::close);
    fg.setParent(this);
    fg.setText("操作错误，您不能下在那里！");
    fg.move(80,100);
}
