#include <iostream>
using namespace std;

/**
** 顺时针打印N*N的矩阵
**/


//打印矩阵外环
void PrintClockWiselyOut(int **p,int x1, int y1,int x2,int y2)
{
    for(int i = y1;i<=y2;i++)
    {
        cout<<p[x1][i]<<endl;
    }
    for(int i = x1+1;i<=x2;i++)
    {
        cout<<p[i][y2]<<endl;
    }
    for(int i = y2-1;i>=y1;i--)
    {
        cout<<p[x2][i]<<endl;
    }
    for(int i = x2-1;i>=x1+1;i--)
    {
        cout<<p[i][y1]<<endl;;
    }
}


/**
** 思路递归 终止条件 n == 0 或者 n == 1
**/
void MatrixClockWiselyMN(int **p,int x1, int y1,int x2,int y2)
{
    if(x1>x2&&y1>y2)
        return;
    if(x1==x2&&y1==y2)
    {
        cout<<p[x1][y1]<<endl;
        return;
    }
    if(x1==x2&&y1<y2)
    {
        for(int i = y1;i<=y2;i++)
        {
            cout<<p[x1][i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(y1==y2&&x1<x2)
    {
        for(int i = x1;i<x2;i++)
        {
            cout<<p[i][y1]<<" ";
        }
        cout<<endl;
        return;
    }
    PrintClockWiselyOut(p,x1,y1,x2,y2);
    MatrixClockWiselyMN(p,x1+1,y1+1,x2-1,y2-1);
}

int main()
{
    int **NN;
    NN = new int* [5];
    int c = 1;
    for(int i = 0;i<5;i++)
    {
        NN[i] = new int[5];
        for(int j = 0;j<5;j++)
        {
            NN[i][j] = j + c;
        }
        c++;
    }

    for(int i = 0;i<5;i++)
    {
        for(int j = 0;j<5;j++)
        {
            cout<<NN[i][j]<<" ";
        }
        cout<<endl;
    }
    MatrixClockWiselyMN(NN,0, 0,4,4);
    return 0;
}
