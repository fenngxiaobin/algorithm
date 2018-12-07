#include <iostream>
using namespace std;

int GetMissingNumber(const int* numbers,int length)
{
    if(length<=0||numbers==nullptr)
    {
        return -1;
    }
    int left = 0;
    int right = length - 1;
    while(left<=right)
    {
        int mid = left + (right - left)>>1;
        if(numbers[mid] == mid)
        {
            return mid;
        }
        else if(numbers[mid]>mid)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int *data = new int[6];
    data[0]=0;
    data[1]=1;
    data[2]=3;
    data[3]=4;
    data[4]=5;
    data[5]=6;
    cout<<GetMissingNumber(data,6)<<endl;
    return 0;
}
