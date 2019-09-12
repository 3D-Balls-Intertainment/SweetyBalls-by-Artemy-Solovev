#include "txlib.h"
#include <time.h>
#include <iostream>
#include <cmath>
void drawColoredBall(int x, int y, int r, int R,int G,int B);  //������ 3D-��� ������� r � ������� � (x,y) ����� (R,G,B)

void drawOrientedBall(int x, int y, int lX, int lY, int r, int R,int G,int B); /*������ 3D-��� ������� r � ������� � (x,y),
                                                                                ������ (R,G,B) � ������ � ������� ��������� � ������������ (lX, lY) */

int get_rand(int min, int max);  //��� ��������� ��������� ��������� � �����

void drawRingyBackground(int X, int Y, int size); //������ ��� � ����� �� ��������� (not done yet)

int main()
{
    int num, rad, sizeX, sizeY, lghtX, lghtY;
    std::cout << "window size: ";                 //���� ������� ����
    std::cin >> sizeX >> sizeY;
    std::cout << "number of sweety balls: ";  //���� ���������� �����
    std::cin >> num;
    std::cout << "light position: ";     //���� ��������� ��������� �����
    std::cin >> lghtX >> lghtY;


    txCreateWindow(sizeX,sizeY);           //������� ����
    srand(time_t(0));
    int trueX, trueY, x1, y1, colR, colG, colB;
    for( int i = 0; i < num; i++)
    {
        colR = get_rand(50, 255);
        colG = get_rand(50, 255);
        colB = get_rand(50, 255);
        rad = get_rand(50, 100);                 // ���������� ���� ���� � ��� ����������
        trueX = abs(sizeX-rad);
        trueY = abs(sizeY-rad);                 // trueX, trueY ��� ��������� ����
        x1 = get_rand(rad, trueX);              // ������� � ����
        y1 = get_rand(rad, trueY);
        for (double q = 0.0; q < 100.0; q+=1) {                    //������ ��� + �������� �������� �� ���� ����������
            txSetFillColor(RGB(0,0,0));
            txClear();
            drawOrientedBall(floor(100*cos(2*3.14*q/360))+x1, floor(100*sin(2*3.14*q/360))+y1,lghtX, lghtY, rad, colR, colG, colB);
            txSleep(0.001);
            }
        }

    return 0;
}

void drawRingyBackground(int X, int Y, int size) {
    drawColoredBall(X,Y, 2*size, 255, 255, 255);
}
void drawColoredBall(int x, int y, int r, int R,int G,int B)
{
for(int i = r; i>0; i--)
    {
        txSetColor(RGB(R-(200*i*R)/(r*255), G-(G*i*200)/(r*255), B-(B*i*200)/(r*255)));
        txSetFillColor(RGB(R-(200*i*R)/(r*255), G-(G*i*200)/(r*255), B-(B*i*200)/(r*255)));
        txCircle(x, y, i);
    }
}
void drawOrientedBall(int x, int y, int lX, int lY, int r, int R,int G,int B)
{
for(int i = r; i>0; i--)
    {
        txSetColor(RGB(R-(220*i*R)/(r*255), G-(G*i*220)/(r*255), B-(B*i*220)/(r*255)));
        txSetFillColor(RGB(R-(220*i*R)/(r*255), G-(G*i*220)/(r*255), B-(B*i*220)/(r*255)));
        double sinus = (lY-y)/sqrt((lX-x)*(lX-x)+(lY-y)*(lY-y));
        double cosinus = (lX-x)/sqrt((lX-x)*(lX-x)+(lY-y)*(lY-y));
        txCircle(x-(i/2)*cosinus, y-(i/2)*sinus, i);
    }
}

int get_rand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

