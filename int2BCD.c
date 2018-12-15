#include <stdio.h>
#include <stdlib.h>
unsigned int iv,i;
unsigned char BCD[5];//定长10位BCD码
unsigned char sv[11];
int main() {
    iv=129956789;//最大10位无符号正整数
	//INT2BCD
	sprintf(sv,"%010u",iv);
	for (i=0;i<10;i+=2) 
	{
		BCD[i/2]=(sv[i]<<4)|(sv[i+1]&0x0F);
	}
	printf("BCD=%02x%02x%02x%02x%02x\n",BCD[0],BCD[1],BCD[2],BCD[3],BCD[4]);
	//BCD2INT
	for (i=0;i<10;i+=2) {
		sv[i]='0'|(BCD[i/2]>>4);
		sv[i+1]='0'|(BCD[i/2]&0x0F);
	}
	sscanf(sv,"%010u",&iv);
	printf("iv=%010u\n",iv);
	return 0;
}
