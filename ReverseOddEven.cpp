#include <iostream>
using namespace std;

void ReverseOddEven(int* num,int length)
{
    int low = 0;
    int high = length-1;
    while(low<high)
    {
		//注意运算符的先后顺序 要加上小括号
        while(low<high&&((num[low]&0x1)!=0))
        {
            //判断是奇数
            low++;
        }
        while(low<high&&((num[high]&0x1)==0))
        {
            high--;
        }
        if(low<high)
        {
            int temp = num[low];
            num[low] = num[high];
            num[high] = temp;
        }
    }
}

int main()
{
    int* num = new int[5];
    num[0]=9;
    num[1]=2;
    num[2]=4;
    num[3]=3;
    num[4]=1;
    for(int i = 0;i<5;i++)
    {
        cout<<num[i]<<endl;
    }
    ReverseOddEven(num,5);
    for(int i = 0;i<5;i++)
    {
        cout<<num[i]<<endl;
    }
    return 0;
}
