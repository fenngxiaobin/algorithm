#include <iostream>
using namespace std;

/**
** 顺时针打印N*N的矩阵
**/


//打印矩阵外环
void PrintClockWiselyOut(int **p,int row,int column)
{
    for(int i = row;i<=column;i++)
    {
        cout<<p[row][i]<<endl;
    }
    for(int i = row+1;i<=column;i++)
    {
        cout<<p[i][column]<<endl;
    }
    for(int i = column-1;i>=row;i--)
    {
        cout<<p[column][i]<<endl;
    }
    for(int i = column-1;i>=row+1;i--)
    {
        cout<<p[i][row]<<endl;;
    }
}


/**
** 思路递归 终止条件 n == 0 或者 n == 1
**/
void MatrixClockWiselyNN(int **p,int row, int column,int n)
{
    if(n==0)
        return;
    if(n==1)
    {
        cout<<p[row][column]<<endl;
		return;
	}
    PrintClockWiselyOut(p,row,column);
    MatrixClockWiselyNN(p,row+1,column-1,n-2);
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
	cout<<"___________"<<endl;
	MatrixClockWiselyNN(NN,0,4,5);
    return 0;
}
