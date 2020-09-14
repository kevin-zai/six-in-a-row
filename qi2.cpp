#include "qi2.h"
#include<QPainter>
#include<QPushButton>
#include <QMouseEvent>
#include<QDebug>
#include <QTime>

qi2::qi2(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("游戏");
    this->resize(1200,1200);
    d1.setParent(this);
    d2.setText("白棋 PC");
    d1.setText("黑棋：PC");
    d1.move(900,200);
    d2.setParent(this);
    d2.move(900,600);
    d1.resize(300,100);
    d1.resize(300,100);
    d2.setStyleSheet("color:white;font: bold 30px;");
    d1.setStyleSheet("color:white;font: bold 30px;");
    p1.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    p2.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    p3.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    p1.setParent(this);
    p1.setText("返回");
    p1.setGeometry(1100,1010,80,80);
    p4.setParent(this);
    p4.setText("和棋");
    p4.setGeometry(320,1010,80,80);
    p4.setStyleSheet("color:blue;font: bold 30px;background-color: yellow;");
    connect(&p4,&QPushButton::clicked,this,
            [=](){
        ji.fgg.setText("和        棋");
        ji.show();
    });
    connect(&p1,&QPushButton::clicked,this,
                    [=]()
                    {
                        emit signal1();
                    });
    p2.setParent(this);
    p2.setText("认输");
    p2.setGeometry(850,1010,80,80);
    p3.setParent(this);
    p3.setText("重玩");
    p3.setGeometry(580,1010,80,80);

    for(int i=1;i<22;i++)for(int j=1;j<22;j++)z[i][j]=0;
    for(int i=1;i<22;i++){z[i][0]=2;z[i][22]=2;}
    for(int i=1;i<22;i++){z[0][i]=2;z[22][i]=2;}

    connect(&ji,&jie::mesignal,this,
            [=]()
            {   flag=1;
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
    connect(&p3,&QPushButton::clicked,this,
            [=]()
            {
                 flag=1;
                 start=1;
                 for(int i=1;i<22;i++)for(int j=1;j<22;j++)z[i][j]=0;
                 for(int i=1;i<22;i++){z[i][0]=2;z[i][22]=2;}
                 for(int i=1;i<22;i++){z[0][i]=2;z[22][i]=2;}
            });

}

void qi2::mousePressEvent(QMouseEvent * ){
    if(start){
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        xx = qrand() % 21+1;
        yy = qrand() % 21+1;
        z[xx][yy]=flag;
        flag=-flag;
        start=0;
    }
    else{

            int personNum=0;
            int botNum=0;
            int  emptyNum=0;
            int score[22][22];
            for(int i=1;i<22;i++)
                for(int y=1;y<22;y++)score[i][y]=0;

            for (int row = 0; row < 22; row++)
                    for (int col = 0; col < 22; col++)
                    {
                        // 空白点就算
                        if (row > 0 && col > 0 &&
                            z[row][col] == 0)
                        {
                            // 遍历周围八个方向
                            for (int y = -1; y <= 1; y++)
                                for (int x = -1; x <= 1; x++)
                                {
                                    // 重置
                                    personNum = 0;
                                    botNum = 0;
                                    emptyNum = 0;

                                    // 原坐标不算
                                    if (!(y == 0 && x == 0))
                                    {
                                        // 每个方向延伸5个子

                                        // 对玩家评分（正反两个方向）
                                        for (int i = 1; i <= 5; i++)
                                        {
                                            if (row + i * y > 0 && row + i * y < 22 &&
                                                col + i * x > 0 && col + i * x < 22 &&
                                                z[row + i * y][col + i * x] == 1) // 玩家的子
                                            {
                                                personNum++;
                                            }
                                            else if (row + i * y > 0 && row + i * y < 22 &&
                                                     col + i * x > 0 && col + i * x < 22 &&
                                                     z[row + i * y][col + i * x] == 0) // 空白位
                                            {
                                                emptyNum++;
                                                break;
                                            }
                                            else            // 出边界
                                                break;
                                        }

                                        for (int i = 1; i <= 5; i++)
                                        {
                                            if (row - i * y > 0 && row - i * y < 22 &&
                                                col - i * x > 0 && col - i * x < 22 &&
                                                z[row - i * y][col - i * x] == 1) // 玩家的子
                                            {
                                                personNum++;
                                            }
                                            else if (row - i * y > 0 && row - i * y < 22 &&
                                                     col - i * x > 0 && col - i * x < 22 &&
                                                     z[row - i * y][col - i * x] == 0) // 空白位
                                            {
                                                emptyNum++;
                                                break;
                                            }
                                            else            // 出边界
                                                break;
                                        }

                                        if (personNum == 1)                      // 杀二
                                            score[row][col] += 10;
                                        else if (personNum == 2)                 // 杀三
                                        {
                                            if (emptyNum == 1)
                                               score[row][col] += 30;
                                            else if (emptyNum == 2)
                                                score[row][col] += 40;
                                        }
                                        else if (personNum == 3)                 // 杀四
                                        {
                                            // 量变空位不一样，优先级不一样
                                            if (emptyNum == 1)
                                                score[row][col] += 60;
                                            else if (emptyNum == 2)
                                                score[row][col] += 110;
                                        }
                                        else if (personNum == 4){                 // 杀五
                                            if (emptyNum == 1)
                                                score[row][col] += 1000;
                                            else if (emptyNum == 2)
                                                score[row][col] += 2000;}
                                        else if(personNum == 5)
                                            score[row][col] += 100000;


                                        // 进行一次清空
                                        emptyNum = 0;

                                        // 对AI评分
                                        for (int i = 1; i <= 5; i++)
                                        {
                                            if (row + i * y > 0 && row + i * y < 22 &&
                                                col + i * x > 0 && col + i * x < 22 &&
                                                z[row + i * y][col + i * x] == 1) // 玩家的子
                                            {
                                                botNum++;
                                            }
                                            else if (row + i * y > 0 && row + i * y < 22 &&
                                                     col + i * x > 0 && col + i * x < 22 &&
                                                     z[row +i * y][col + i * x] == 0) // 空白位
                                            {
                                                emptyNum++;
                                                break;
                                            }
                                            else            // 出边界
                                                break;
                                        }

                                        for (int i = 1; i <= 5; i++)
                                        {
                                            if (row - i * y > 0 && row - i * y < 22 &&
                                                col - i * x > 0 && col - i * x < 22 &&
                                                z[row - i * y][col - i * x] == -1) // AI的子
                                            {
                                                botNum++;
                                            }
                                            else if (row - i * y > 0 && row - i * y <22 &&
                                                     col - i * x > 0 && col - i * x < 22&&
                                                     z[row - i * y][col - i * x] == 0) // 空白位
                                            {
                                                emptyNum++;
                                                break;
                                            }
                                            else            // 出边界
                                                break;
                                        }

                                        if (botNum == 0)                      // 普通下子
                                            score[row][col] += 5;
                                        else if (botNum == 1)                 // 活二
                                            score[row][col] += 10;
                                        else if (botNum == 2)
                                        {
                                            if (emptyNum == 1)                // 死三
                                               score[row][col] += 25;
                                            else if (emptyNum == 2)
                                                score[row][col] += 50;  // 活三
                                        }
                                        else if (botNum == 3)
                                        {
                                            if (emptyNum == 1)                // 死四
                                                score[row][col] += 55;
                                            else if (emptyNum == 2)
                                                score[row][col] += 100; // 活四
                                        }
                                        else if (botNum >= 4){
                                            if (emptyNum == 1)
                                                score[row][col] += 990;
                                            else if (emptyNum == 2)
                                                score[row][col] += 1990;  // 活五
                                        }
                                        else if (botNum >= 5)
                                               score[row][col] += 101000;
                                    }
                                }

                        }
                    }





            int maxs=0;

            for(int i=1;i<22;i++)
                for(int y=1;y<22;y++)
                {
                    if(z[i][y]==0)
                    {
                        if(score[i][y]>maxs){maxs=score[i][y];xx=i;yy=y;}
                    }
                }
            z[xx][yy]=flag;
            flag=-flag;
            update();

        }
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
        if(xx!=0){


        for (int i = 0; i < 6; i++)
           {
               // 往左5个，往右匹配4个子，20种情况
               if (yy - i > 0 &&
                   yy - i + 5 < 22 &&
                   z[xx][yy-i]!=0 &&
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
                       z[xx-i][yy]!=0 &&
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
                       z[xx+i][yy-i]!=0 &&
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
                       z[xx-i][yy-i]!=0 &&
                   z[xx - i][yy - i] ==  z[xx - i+1][yy - i+1] &&
                   z[xx - i+1][yy - i+1] == z[xx - i + 2][yy - i + 2] &&
                   z[xx - i+1][yy - i+1] == z[xx - i + 3][yy - i + 3] &&
                   z[xx - i+1][yy - i+1] == z[xx - i + 4][yy - i + 4] &&
                   z[xx - i+1][yy - i+1] == z[xx - i + 5][yy - i + 5]){
                   mm=1;break;}
           }


        //jinshou
        if(mm==0){
            if(flag==-1){
                int ges=0;
                int ge1=0,ge2=0,ge3=0,ge4=0;
                for (int i = 0; i < 4; i++)
                   {
                       if (yy - i - 1 > 0 &&
                           yy - i + 4 < 22 &&
                               z[xx][yy-i]!=0 &&
                           z[xx][yy - i] == z[xx][yy - i + 1] &&
                           z[xx][yy - i] == z[xx][yy - i + 2] &&
                           z[xx][yy - i] == z[xx][yy - i + 3] &&
                           z[xx][yy - i - 1] == z[xx][yy - i + 4]&&
                           z[xx][yy - i -1] == 0)
                       {
                           ges++;ge1=1;break;}
                }

                   // 竖直方向(上下延伸4个)
                   for (int i = 0; i < 4; i++)
                   {
                       if (xx - i -1> 0 &&
                           xx - i + 4 < 22 &&
                           z[xx - i-1][yy] == 0 &&
                               z[xx-i][yy]!=0 &&
                           z[xx - i][yy] == z[xx - i + 1][yy] &&
                           z[xx - i+1][yy] == z[xx - i + 3][yy] &&
                           z[xx - i+1][yy] == z[xx - i + 2][yy] &&
                           z[xx - i-1][yy] == z[xx - i + 4][yy]){
                           ges++;ge2=1;break;}
                   }

                   // 左斜方向
                   for (int i = 0; i < 4; i++)
                   {
                       if (xx + i +1 < 22 &&
                           xx + i - 4 > 0 &&
                           yy - i -1 > 0 &&
                           yy - i + 4 < 22 &&
                           z[xx + i+1][yy - i-1] == 0 &&
                               z[xx+i][yy-i]!=0 &&
                           z[xx + i-1][yy - i+1] == z[xx + i ][yy - i ] &&
                           z[xx + i-1][yy - i+1] == z[xx + i - 3][yy - i + 3] &&
                           z[xx + i-1][yy - i+1] == z[xx + i - 2][yy - i + 2] &&
                           z[xx + i+1][yy - i-1] == z[xx + i - 4][yy - i + 4]){
                           ges++;ge3=1;break;}
                   }

                   // 右斜方向
                   for (int i = 0; i < 4; i++)
                   {
                       if (xx - i -1 > 0 &&
                           xx - i + 4 < 22 &&
                           yy - i -1 > 0 &&
                           yy - i + 4 < 22 &&
                           z[xx - i-1][yy - i-1] == 0 &&
                               z[xx-i][yy-i]!=0 &&
                           z[xx - i+1][yy - i+1] == z[xx - i ][yy - i ] &&
                           z[xx - i+1][yy - i+1] == z[xx - i + 3][yy - i + 3] &&
                           z[xx - i+1][yy - i+1] == z[xx - i + 2][yy - i + 2] &&
                           z[xx - i-1][yy - i-1] == z[xx - i + 4][yy - i + 4]){
                           ges++;ge4=1;break;}
                   }

                   //bu lianxu
                   if(ge1==0){
                   zero=0;one=0;
                   for (int i = 0; i < 5; i++)
                      {
                          if (yy - i - 1 > 0 &&
                              yy - i + 5 < 22 &&
                              z[xx][yy - i - 1] == z[xx][yy - i + 5]&&
                                  z[xx][yy - i -1] == 0){
                              for(int l=0;l<=4;l++){
                              if(z[xx][yy-i+l]==0)zero++;
                              if(z[xx][yy-i+l]==1) one++;
                          }
                          if(one==4&&zero==1){
                              ges++;break;}
                   }
                   }
                   }

                      // 竖直方向(上下延伸4个)
                   if(ge2==0){
                   zero=0;one=0;
                      for (int i = 0; i < 5; i++)
                      {
                          if (xx - i -1 > 0 &&
                              xx - i + 5 < 22 &&
                              z[xx - i-1][yy] == 0 &&
                              z[xx - i-1][yy] == z[xx - i + 5][yy]){
                              for(int l=0;l<=4;l++){
                              if(z[xx-i+l][yy]==0)zero++;
                              if(z[xx-i+l][yy]==1) one++;
                          }
                              if(one==4&&zero==1){
                                  ges++;break;}

                      }
                   }
                   }

                      // 左斜方向
                   if(ge3==0){
                   zero=0;one=0;
                      for (int i = 0; i < 5; i++)
                      {
                          if (xx + i +1 < 22 &&
                              xx + i - 5 > 0 &&
                              yy - i -1 > 0 &&
                              yy - i + 5 < 22 &&
                              z[xx + i+1][yy - i-1] == 0 &&
                              z[xx + i+1][yy - i-1] == z[xx + i - 5][yy - i + 5]){
                              for(int l=0;l<=4;l++){
                              if(z[xx+i-l][yy-i+l]==0)zero++;
                              if(z[xx+i-l][yy-i+l]==1) one++;
                          }
                              if(one==4&&zero==1){
                                  ges++;break;}
                      }
                   }
                   }

                      // 右斜方向
                   if(ge4==0){
                   zero=0;one=0;
                      for (int i = 0; i < 5; i++)
                      {
                          if (xx - i > 0 &&
                              xx - i + 5 < 22 &&
                              yy - i > 0 &&
                              yy - i + 5 < 22 &&
                              z[xx - i-1][yy - i-1] == 0 &&
                              z[xx - i-1][yy - i-1] == z[xx - i + 5][yy - i + 5]){
                              for(int l=0;l<=4;l++){
                              if(z[xx-i+l][yy-i+l]==0)zero++;
                              if(z[xx-i+l][yy-i+l]==1) one++;
                          }
                              if(one==4&&zero==1){
                                  ges++;break;}
                      }
                   }
                   }
                   if(ges>=2)mm=2;
                }
           }
        if(mm==0){
            if(flag==-1){
                int ges=0;
                int ge1=0,ge2=0,ge3=0,ge4=0;
                for (int i = 0; i < 5; i++)
                   {
                       if (yy - i  > 0 &&
                           yy - i + 4 < 22 &&
                               z[xx][yy-i]!=0 &&
                           z[xx][yy - i] == z[xx][yy - i + 1] &&
                           z[xx][yy - i] == z[xx][yy - i + 2] &&
                           z[xx][yy - i] == z[xx][yy - i + 3] &&
                           z[xx][yy - i] == z[xx][yy - i + 4]&&
                           (z[xx][yy - i -1] == 0||z[xx][yy-i+5]==0))
                       {
                           ges++;ge1=1;break;}
                }

                   // 竖直方向(上下延伸4个)
                   for (int i = 0; i < 5; i++)
                   {
                       if (xx - i > 0 &&
                           xx - i + 4 < 22 &&
                            z[xx-i][yy]!=0 &&
                           z[xx - i][yy] == z[xx - i + 1][yy] &&
                           z[xx - i+1][yy] == z[xx - i + 3][yy] &&
                           z[xx - i+1][yy] == z[xx - i + 2][yy] &&
                           z[xx - i][yy] == z[xx - i + 4][yy]&&
                           (z[xx- i -1][yy ] == 0||z[xx-i+5][yy]==0))
                       {
                           ges++;ge2=1;break;}
                   }

                   // 左斜方向
                   for (int i = 0; i <5; i++)
                   {
                       if (xx + i < 22 &&
                           xx + i - 4 > 0 &&
                           yy - i > 0 &&
                           yy - i + 4 < 22 &&
                               z[xx+i][yy-i]!=0 &&
                           z[xx + i-1][yy - i+1] == z[xx + i ][yy - i ] &&
                           z[xx + i-1][yy - i+1] == z[xx + i - 3][yy - i + 3] &&
                           z[xx + i-1][yy - i+1] == z[xx + i - 2][yy - i + 2] &&
                           z[xx + i][yy -i] == z[xx + i - 4][yy - i + 4]&&
                           (z[xx+i +1][yy - i-1] == 0||z[xx+i-5][yy-i+5]==0)){
                           ges++;ge3=1;break;}
                   }

                   // 右斜方向
                   for (int i = 0; i < 5; i++)
                   {
                       if (xx - i > 0 &&
                           xx - i + 4 < 22 &&
                           yy - i > 0 &&
                           yy - i + 4 < 22 &&
                               z[xx-i][yy-i]!=0 &&
                           (z[xx - i-1][yy - i-1] == 0 || z[xx - i + 5][yy - i + 5]==0)&&
                           z[xx - i+1][yy - i+1] == z[xx - i ][yy - i ] &&
                           z[xx - i+1][yy - i+1] == z[xx - i + 3][yy - i + 3] &&
                           z[xx - i+1][yy - i+1] == z[xx - i + 2][yy - i + 2] &&
                           z[xx - i][yy - i] == z[xx - i + 4][yy - i + 4]){
                           ges++;ge4=1;break;}
                   }

                   //bu lianxu
                   if(ge1==0){
                   zero=0;one=0;
                   for (int i = 0; i < 6; i++)
                      {
                          if (yy - i  > 0 &&
                              yy - i + 5 < 22 ){
                              for(int l=0;l<=5;l++){
                              if(z[xx][yy-i+l]==0)zero++;
                              if(z[xx][yy-i+l]==1) one++;
                          }
                          if(one==5&&zero==1){
                              ges++;break;}
                   }
                   }
                   }

                      // 竖直方向(上下延伸4个)
                   if(ge2==0){
                   zero=0;one=0;
                      for (int i = 0; i < 6; i++)
                      {
                          if (xx - i > 0 &&
                              xx - i + 5 < 22 )

                              for(int l=0;l<=5;l++){
                              if(z[xx-i+l][yy]==0)zero++;
                              if(z[xx-i+l][yy]==1) one++;
                          }
                              if(one==5&&zero==1){
                                  ges++;break;}

                      }
                   }


                      // 左斜方向
                   if(ge3==0){
                   zero=0;one=0;
                      for (int i = 0; i < 6; i++)
                      {
                          if (xx + i < 22 &&
                              xx + i - 5 > 0 &&
                              yy - i > 0 &&
                              yy - i + 5 < 22  ){
                              for(int l=0;l<=5;l++){
                              if(z[xx+i-l][yy-i+l]==0)zero++;
                              if(z[xx+i-l][yy-i+l]==1) one++;
                          }
                              if(one==5&&zero==1){
                                  ges++;break;}
                      }
                   }
                   }

                      // 右斜方向
                   if(ge4==0){
                   zero=0;one=0;
                      for (int i = 0; i < 6; i++)
                      {
                          if (xx - i > 0 &&
                              xx - i + 5 < 22 &&
                              yy - i > 0 &&
                              yy - i + 5 < 22 ){
                              for(int l=0;l<=5;l++){
                              if(z[xx-i+l][yy-i+l]==0)zero++;
                              if(z[xx-i+l][yy-i+l]==1) one++;
                          }
                              if(one==5&&zero==1){
                                  ges++;break;}
                      }
                   }
                   }
                   if(ges>=2)mm=3;
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


           //jieguo
           if(mm==1){
               if(flag==1)
                   ji.fgg.setText("白 子 胜 利");
               else ji.fgg.setText("黑 子 胜 利");

               ji.show();
           }
           if(mm==2){
               ji.fgg.setText("四四禁手 白子胜");
               ji.show();
           }
            if(mm==3){

                ji.fgg.setText("五五禁手 白子胜");
                ji.show();
            }
           if(mm==4){
               ji.fgg.setText("和     棋");
               ji.show();
           }



    }

    }
