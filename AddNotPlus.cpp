#include <iostream>
using namespace std;

int AddNotPlus(int num1,int num2)
{
	int sum,carry;
	do
	{
		sum = num1^num2;
		carry = (num1&num2)<<1;
		num1 = sum;
		num2 = carry;
	}while(num2!=0);
	//进位！=0 就会一直相加
	return num1;
}

int main()
{
	cout<<AddNotPlus(100,12)<<endl;
	return 0;
}
