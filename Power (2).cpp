#include <iostream>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

bool IsInvalidInput = false;

const float EPSION = 0.000001;

double PowerWithUnsignedExpRecurse(double base, int absExp)
{
	if(absExp==0)
	{
		return 1.0;
	}
	if(absExp==1)
	{
		return base;
	}
	double result = PowerWithUnsignedExpRecurse(base,absExp>>1);
	result *= result;
	if(absExp&0x1==1)
	{
		result *= base;
	}
	return result;
}

double PowerWithUnsignedExp(double base, int absExp)
{
    double num = 1.0;
    for(int i = 0;i<absExp;i++)
    {
        num *= base;
    }
    return num;
}

double Power(double base, int exp)
{
    IsInvalidInput = false;
    if(base == 0.0&& exp <= 0)
    {
        IsInvalidInput = true;
		return 0.0;
    }

    double absExp = (unsigned int)exp;
    if(exp < 0)
    {
        absExp = (unsigned int)(-exp);
    }

    double result = PowerWithUnsignedExpRecurse(base,absExp);
    if(exp < 0)
        result = 1.0/result;
    return result;
}

int main()
{
	assert(abs(Power(1.0,0)-0)<EPSION&&!IsInvalidInput);
	if(abs(Power(2,2)-4)<EPSION&&!IsInvalidInput){
		cout<<"ok2.."<<endl;
	}
	if(abs(Power(-2,-2)-0.25)<EPSION&&!IsInvalidInput){
		cout<<"ok3.."<<endl;
	}
	if(abs(Power(0,0)-0)<EPSION&&!IsInvalidInput){
		cout<<"error4.."<<endl;
	}
    return 0;
}
