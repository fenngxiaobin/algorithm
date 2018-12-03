#include "BitMap.h"

BitMap::BitMap(size_t num)
{
    _vec.resize(num>>5+1);
}

void BitMap::set(size_t num)
{
    _vec[num>>5]|=1<<(num%32);
}

void BitMap::reset(size_t num)
{
    _vec[num>>5] &= ~(1<<(num%32));
}

bool BitMap::isExist(size_t num)
{
    if(_vec[num>>5] & 1<<(num%32))
    {
        return true;
    }
    return false;
}

