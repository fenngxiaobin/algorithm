#include <iostream>
#include <list>
using namespace std;

/**
* 此处方便计算 默认4bit
*/
size_t findLostNumber(list<size_t> li)
{
    list<size_t> tmplist;
    size_t bit = 4;
    list<size_t> onelist;
    list<size_t> zerolist;
    size_t number=0;
    while(bit--)
    {
        onelist.clear();
        zerolist.clear();
        for(list<size_t>::iterator it = li.begin();it != li.end(); it++)
        {
            if((*it)&(1<<bit))
            {
                onelist.push_back(*it);2
            }
            else
            {
                zerolist.push_back(*it);
            }
        }
        if (onelist.size()>zerolist.size())
        {
            std::copy(zerolist.begin(), zerolist.end(), std::back_inserter(tmplist));
            number |= 0<<bit; //此处比较多此一举，但是思路清晰
        }else{
            std::copy(onelist.begin(), onelist.end(), std::back_inserter(tmplist));
            number |= 1<<bit;
        }
    }
    return number;
}


int main()
{
    list<size_t> li= {0,1,2,3,4,5,6,7,8,9,11,12,13,14,15};
    cout<<findLostNumber(li)<<endl;
    return 0;
}