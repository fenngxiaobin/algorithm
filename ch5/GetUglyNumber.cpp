#include <iostream>

using namespace std;

int _min(int a,int b,int c)
{
    int d = a<b?a:b;
    return  d<c?d:c;
}

int GetUglyNumber(int index)
{
    if(index<=0)
    {
        return -1;
    }
    int *nNums = new int[index];
    nNums[0]=1;
    int nextIndex = 1;
    int *nNum2 = nNums;
    int *nNum3 = nNums;
    int *nNum5 = nNums;
    
    while(nextIndex<index){
        int min = _min(*nNum2*2,*nNum3*3,*nNum5*5);
        nNums[nextIndex] = min;
        while(*nNum2*2<=nNums[nextIndex])
        {
            nNum2++;
        }
        while(*nNum3*3<=nNums[nextIndex])
        {
            nNum3++;
        }
        while(*nNum5*5<=nNums[nextIndex])
        {
            nNum5++;
        }
        nextIndex++;
    }
    int ugly = nNums[index-1];
    delete[] nNums;
    return ugly;
}


int main()
{
    cout<<GetUglyNumber(3)<<endl;
    cout<<GetUglyNumber(5)<<endl;
    cout<<GetUglyNumber(6)<<endl;
    return 0;
}












