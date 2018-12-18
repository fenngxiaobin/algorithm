#include <iostream>
using namespace std;

int MoreThanHalf(int* numbers , int length)
{
    if(numbers==nullptr||length<=0)
    {
        return 0;
    }

    int num = numbers[0];
    int times = 1;
    for(int i = 1;i<length;i++)
    {
        if(times == 0)
        {
            num = numbers[i];
            times = 1;
        }
        else if(num == numbers[i])
        {
            times++;
        }
        else
        {
            times--;
        }
        
    }
    int count =0;
    for(int i = 0;i<length;i++)
    {
        if(numbers[i]==num)
        {
            count++;
        }
    }
    if(count>length/2)
    {
        return num;
    }
    return 0;
}

int main()
{
    int str[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout<<MoreThanHalf(str,9)<<endl;
    return 0;
}
