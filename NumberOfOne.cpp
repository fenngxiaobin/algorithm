#include <iostream>
using namespace std;
/**
** 如果是负数，右移高位补符号位1，运算错误
** 只能从低位往高位 左移
**/

int NumberOfOne_1(int num)
{
    int count = 0;
    size_t flag = 1;
    while(flag)
    {
        if(flag&num)
        {
            count++;
        }
        flag = flag<<1;
    }
    return count;
}


/**
** 求数a二进制中1的个数 公式结论：(a&(a-1))!=0 ==> count++;
**/
int NumberOfOne_2(int num)
{
    int count = 0;
    while(num)
    {
        count++;
        num = (num&(num-1));
    }
    return count;
}

/**
** 判断一个数 是不是2的指数次幂
**/
bool Judge2(int num)
{
	if(num&(num-1))
	{
		return false;
	}
	return true;
}
int main()
{
    size_t flag = 1;
    for(int i=0;i<35;i++){
        flag = flag<<1;
        cout<<hex<<flag<<endl;
    }
    cout<<hex<<28<<endl;
    cout<<"二进制中1的个数："<<NumberOfOne_1(28)<<endl;
    cout<<"二进制中1的个数："<<NumberOfOne_2(28)<<endl;
    cout<<"二进制中1的个数："<<NumberOfOne_1(289)<<endl;
    cout<<"二进制中1的个数："<<NumberOfOne_2(289)<<endl;
    cout<<"二进制中1的个数："<<NumberOfOne_1(832943924)<<endl;
    cout<<"二进制中1的个数："<<NumberOfOne_2(832943924)<<endl;
    cout<<Judge2(8)<<endl;
	cout<<Judge2(7)<<endl;
	return 0;
}
