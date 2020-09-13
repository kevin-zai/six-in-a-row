#include "qi2.h"
#include<QPainter>
#include<QPushButton>
#include <QMouseEvent>
#include<QDebug>

qi2::qi2(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("游戏");
    this->resize(1200,1200);
    p1.setParent(this);
    p1.setText("返回");
    p1.setGeometry(1100,1010,80,80);
    connect(&p1,&QPushButton::clicked,this,
                    [=]()
                    {
                        emit signal1();
                    });
    p2.setParent(this);
    p2.setText("认输");
    p2.setGeometry(850,1010,80,80);

    for(int i=1;i<22;i++)for(int j=1;j<22;j++)z[i][j]=0;

    connect(&ji,&jie::mesignal,this,
            [=]()
            {
                ji.hide();
                emit signal1();
            });
    connect(&p2,&QPushButton::clicked,this,
            [=]()
            {
                if(flag==1)ji.fgg.setText("黑棋认输");
                else ji.fgg.setText("白棋认输");
                ji.show();
            });

}

void qi2::mousePressEvent(QMouseEvent *e ){
    xx=e->x();
    yy=e->y();
    if(xx>=WIDTH&&xx<=WIDTH*21&&yy>=WIDTH&&yy<=WIDTH*21){
    int a=xx%WIDTH;
    int b=yy%WIDTH;
    if(a>WIDTH/2)xx=xx/WIDTH+1;
    else xx=xx/WIDTH;
    if(b>WIDTH/2)yy=yy/WIDTH+1;
    else yy=yy/WIDTH;
    if(z[xx][yy]!=0)fa.show();
    else{z[xx][yy]=flag;
    flag=-flag;}}
    update();

//    int personNum=0;
//    int botNum=0;
//    int  emptyNum=0;
//    int score[22][22];
//    for(int i=1;i<22;i++)
//        for(int y=1;y<22;y++)score[i][j]=0;

//    for (int row = 0; row < 22; row++)
//            for (int col = 0; col < 22; col++)
//            {
//                // 空白点就算
//                if (row > 0 && col > 0 &&
//                    z[row][col] == 0)
//                {
//                    // 遍历周围八个方向
//                    for (int y = -1; y <= 1; y++)
//                        for (int x = -1; x <= 1; x++)
//                        {
//                            // 重置
//                            personNum = 0;
//                            botNum = 0;
//                            emptyNum = 0;

//                            // 原坐标不算
//                            if (!(y == 0 && x == 0))
//                            {
//                                // 每个方向延伸4个子

//                                // 对玩家白子评分（正反两个方向）
//                                for (int i = 1; i <= 4; i++)
//                                {
//                                    if (row + i * y > 0 && row + i * y < 22 &&
//                                        col + i * x > 0 && col + i * x < 22 &&
//                                        z[row + i * y][col + i * x] == 1) // 玩家的子
//                                    {
//                                        personNum++;
//                                    }
//                                    else if (row + i * y > 0 && row + i * y < 22 &&
//                                             col + i * x > 0 && col + i * x < 22 &&
//                                             z[row + i * y][col + i * x] == 0) // 空白位
//                                    {
//                                        emptyNum++;
//                                        break;
//                                    }
//                                    else            // 出边界
//                                        break;
//                                }

//                                for (int i = 1; i <= 4; i++)
//                                {
//                                    if (row - i * y > 0 && row - i * y < 22 &&
//                                        col - i * x > 0 && col - i * x < 22 &&
//                                        z[row - i * y][col - i * x] == 1) // 玩家的子
//                                    {
//                                        personNum++;
//                                    }
//                                    else if (row - i * y > 0 && row - i * y < 22 &&
//                                             col - i * x > 0 && col - i * x < 22 &&
//                                             z[row - i * y][col - i * x] == 0) // 空白位
//                                    {
//                                        emptyNum++;
//                                        break;
//                                    }
//                                    else            // 出边界
//                                        break;
//                                }

//                                if (personNum == 1)                      // 杀二
//                                    score[row][col] += 10;
//                                else if (personNum == 2)                 // 杀三
//                                {
//                                    if (emptyNum == 1)
//                                       score[row][col] += 30;
//                                    else if (emptyNum == 2)
//                                        score[row][col] += 40;
//                                }
//                                else if (personNum == 3)                 // 杀四
//                                {
//                                    // 量变空位不一样，优先级不一样
//                                    if (emptyNum == 1)
//                                        score[row][col] += 60;
//                                    else if (emptyNum == 2)
//                                        score[row][col] += 110;
//                                }
//                                else if (personNum == 4)                 // 杀五
//                                   score[row][col] += 10100;

//                                // 进行一次清空
//                                emptyNum = 0;

//                                // 对AI黑子评分
//                                for (int i = 1; i <= 4; i++)
//                                {
//                                    if (row + i * y > 0 && row + i * y < 22 &&
//                                        col + i * x > 0 && col + i * x < 22 &&
//                                        z[row + i * y][col + i * x] == 1) // 玩家的子
//                                    {
//                                        botNum++;
//                                    }
//                                    else if (row + i * y > 0 && row + i * y < 22 &&
//                                             col + i * x > 0 && col + i * x < 22 &&
//                                             z[row +i * y][col + i * x] == 0) // 空白位
//                                    {
//                                        emptyNum++;
//                                        break;
//                                    }
//                                    else            // 出边界
//                                        break;
//                                }

//                                for (int i = 1; i <= 4; i++)
//                                {
//                                    if (row - i * y > 0 && row - i * y < 22 &&
//                                        col - i * x > 0 && col - i * x < 22 &&
//                                        z[row - i * y][col - i * x] == -1) // AI的子
//                                    {
//                                        botNum++;
//                                    }
//                                    else if (row - i * y > 0 && row - i * y <22 &&
//                                             col - i * x > 0 && col - i * x < 22&&
//                                             z[row - i * y][col - i * x] == 0) // 空白位
//                                    {
//                                        emptyNum++;
//                                        break;
//                                    }
//                                    else            // 出边界
//                                        break;
//                                }

//                                if (botNum == 0)                      // 普通下子
//                                    score[row][col] += 5;
//                                else if (botNum == 1)                 // 活二
//                                    score[row][col] += 10;
//                                else if (botNum == 2)
//                                {
//                                    if (emptyNum == 1)                // 死三
//                                       score[row][col] += 25;
//                                    else if (emptyNum == 2)
//                                        score[row][col] += 50;  // 活三
//                                }
//                                else if (botNum == 3)
//                                {
//                                    if (emptyNum == 1)                // 死四
//                                        score[row][col] += 55;
//                                    else if (emptyNum == 2)
//                                        score[row][col] += 100; // 活四
//                                }
//                                else if (botNum >= 4)
//                                    score[row][col] += 10000;   // 活五

//                            }
//                        }

//                }
//            }
//    }



//    int maxs=0;


//    for(int i=1;i<22;i++)
//        for(int y=1;y<22;y++)
//        {
//            if(z[i][j]==0)
//            {
//                if(score[i][j])
//            }
//        }

//    flag=-flag;
//    update();

}

void qi2::paintEvent(QPaintEvent *)
{
    this->update();
    QPainter pp(this);
    pp.drawPixmap(rect(),QPixmap(":/new/prefix1/template.png"));
    pp.setPen(QPen(Qt::lightGray,2,Qt::SolidLine));//钢笔工具：颜色，线号，实线

    //画SIZE+1条横线
    for(int i=0;i<SIZE+1;i++)
      {
        pp.drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);//画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
      }
    //画SIZE+1条竖线
    for(int i=0;i<SIZE+1;i++)
      {
        pp.drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
      }
    for(int i=1;i<22;i++)for(int j=1;j<22;j++){
    if(z[i][j]==1){pp.setBrush(QBrush(Qt::black,Qt::SolidPattern));//毛刷：颜色，实图案
        pp.drawEllipse(i*WIDTH-10,j*WIDTH-10,WIDTH/2,WIDTH/2);//画椭圆：中心点X,Y,宽度，高度
    }
    if(z[i][j]==-1){pp.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    pp.drawEllipse(i*WIDTH-10,j*WIDTH-10,WIDTH/2,WIDTH/2);//画椭圆：中心点X,Y,宽度，高度
    }
    }
    int mm=0;
    //if(flag==-1){

    //}

    if(mm==0){
    for (int i = 0; i < 6; i++)
       {
           // 往左5个，往右匹配4个子，20种情况
           if (yy - i > 0 &&
               yy - i + 5 < 22 &&
               z[xx][yy - i] == z[xx][yy - i + 1] &&
               z[xx][yy - i] == z[xx][yy - i + 2] &&
               z[xx][yy - i] == z[xx][yy - i + 3] &&
               z[xx][yy - i] == z[xx][yy - i + 4] &&
               z[xx][yy - i] == z[xx][yy - i + 5]){
               mm=1;break;}
       }

       // 竖直方向(上下延伸4个)
       for (int i = 0; i < 6; i++)
       {
           if (xx - i > 0 &&
               xx - i + 5 < 22 &&
               z[xx - i][yy] == z[xx - i + 1][yy] &&
               z[xx - i][yy] == z[xx - i + 2][yy] &&
               z[xx - i][yy] == z[xx - i + 3][yy] &&
               z[xx - i][yy] == z[xx - i + 4][yy] &&
               z[xx - i][yy] == z[xx - i + 5][yy]){
               mm=1;break;}
       }

       // 左斜方向
       for (int i = 0; i < 6; i++)
       {
           if (xx + i < 22 &&
               xx + i - 5 > 0 &&
               yy - i > 0 &&
               yy - i + 5 < 22 &&
               z[xx + i][yy - i] == z[xx + i - 1][yy - i + 1] &&
               z[xx + i][yy - i] == z[xx + i - 2][yy - i + 2] &&
               z[xx + i][yy - i] == z[xx + i - 3][yy - i + 3] &&
               z[xx + i][yy - i] == z[xx + i - 4][yy - i + 4] &&
               z[xx + i][yy - i] == z[xx + i - 5][yy - i + 5]){
               mm=1;break;}
       }

       // 右斜方向
       for (int i = 0; i < 6; i++)
       {
           if (xx - i > 0 &&
               xx - i + 5 < 22 &&
               yy - i > 0 &&
               yy - i + 5 < 22 &&
               z[xx - i][yy - i] == z[xx - i + 1][yy - i + 1] &&
               z[xx - i][yy - i] == z[xx - i + 2][yy - i + 2] &&
               z[xx - i][yy - i] == z[xx - i + 3][yy - i + 3] &&
               z[xx - i][yy - i] == z[xx - i + 4][yy - i + 4] &&
               z[xx - i][yy - i] == z[xx - i + 5][yy - i + 5]){
               mm=1;break;}
       }
       }
    //和
    if(mm==0){int ytr=0;
    for (int i = 1; i <22; i++){
            for (int j = 1; j < 22; j++)
            {
                if (z[i][j]==0)
                    ytr++;
            }
    if(ytr!=0)break;
    }
    if(ytr==0)mm=4;
    }
    if(mm==1){
        if(flag==1)
            ji.fgg.setText("白子胜利");
        else ji.fgg.setText("黑子胜利");

        ji.show();
    }
    if(mm==4){
        ji.fgg.setText("和棋");
        ji.show();
    }




}

