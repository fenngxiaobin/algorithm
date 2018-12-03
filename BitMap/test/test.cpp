#include "../BitMap.h"

#include <iostream>

int main()
{
    BitMap bitmap(8000000);
    bitmap.set(19922);
    cout<<bitmap.isExist(19922)<<endl;
    cout<<bitmap.isExist(19921)<<endl;
    bitmap.reset(19922);
    cout<<bitmap.isExist(19922)<<endl;
    return 0;
}
