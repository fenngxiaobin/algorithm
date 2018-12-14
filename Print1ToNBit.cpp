/**
** 打印1到n位数的数字
** 涉及到大数 所以考虑数组和递归
**/

#include <iostream>
using namespace std;

void Print(char* number,int length)
{
    bool IsBeginWith0 = true;
    for(int i=0;i<length;i++)
    {
        if(IsBeginWith0&&number[i]!='0')
            IsBeginWith0 = false;
        if(!IsBeginWith0)
            cout<<number[i]<<" ";
    }
    cout<<endl;
}

void Print1ToNBitRecurse(char* number,int length,int index)
{
    if(index==(length-1))
    {
        Print(number,length);
        return;
    }
    for(int i=0;i<10;i++)
    {
        number[index+1]=i+'0';
        Print1ToNBitRecurse(number,length,index+1);
    }
}

void Print1ToNBit(int n)
{
    if(n<=0)
        return;
    char* number =new char[n+1];
    number[n]='\0';
    for(int i=0;i<10;i++)
    {
        number[0]=i+'0';
        Print1ToNBitRecurse(number,n,0);
    }
}

int main()
{
    Print1ToNBit(10);
    return 0;
}
