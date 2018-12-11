#include <iostream>
using namespace std;
#define n 5
/**
** 深度优先搜索或者称为回溯法 解决全排列问题  该问题需要继续扩展
**/
bool *used = new bool[n+1];
int *result = new int[n];

int count = 0;

void make(int c)
{
    for(int i = 1;i<=n;i++)
    {
        if(!used[i])
        {
            used[i]=true;
            result[c]=i;
            make(c+1);
            used[i]=false;
        }
    }
    if(c==n-1)
    {
		count++;
        for(int i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
}

void DFSPermutation()
{
    make(0);
}

int main()
{
    DFSPermutation();
	cout<<"总的排列组合数："<<count<<endl;
    return 0;
}
