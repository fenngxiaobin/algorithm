#ifndef BITMAP_H_
#define BITMAP_H_

#include <vector>
using namespace std;
class BitMap
{
private:
    vector<size_t> _vec;
public:
    BitMap(size_t num);
    void set(size_t num);
    void reset(size_t num);
    bool isExist(size_t num);
    //~BitMap();
};


#endif
