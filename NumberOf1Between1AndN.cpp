#include <iostream>
using namespace std;

int NumberOf1Between1AndN_Solution1(int n) {
	if(n <= 0) return 0;
	int result = 0;
	int loc = 1;	//当前位数
	int high = 0;	//高位数字（多位）
	int now = 0;	//当前位数字（1位）
	int low = 0;	//低位数字（多位）
	
	while(n / loc > 0){
		high = n / (loc * 10);
		now = n / loc % 10;
		low = n % loc;
		
		if(now == 0){
			result += high * loc;
		}
		else if(now == 1){
			result += high * loc + low + 1;
		}
		else if(now >= 1){
			result += (high + 1) * loc;
		}
		
		loc *= 10;
	}
	
	return result;
}

int main()
{
	cout<<NumberOf1Between1AndN_Solution1(15)<<endl;
	cout<<NumberOf1Between1AndN_Solution1(13)<<endl;
	return 0;
}
