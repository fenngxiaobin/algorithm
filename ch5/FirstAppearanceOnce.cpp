#include <iostream>
#include <string>
using namespace std;
#define MAX 1000000

char FirstAppearanceOnce(string seq)
{
    int hashTable[256];
	for(size_t k = 0;k<256;k++)
	{
		hashTable[k] = -1;
		cout<<hashTable[k]<<endl;
	}
    for(size_t i = 0; i < seq.size(); i++)
    {
        if(hashTable[seq.at(i)] == -1)
        {
            hashTable[seq.at(i)] = i;
        }
        else
        {
            hashTable[seq.at(i)] = -2;
        }
    }

    size_t min = MAX;
    for(size_t j=0;j<256;j++)
    {
        if(hashTable[j]>=0 && hashTable[j] < min)
        {
            min = j;
        }
    }
	
	for(size_t k = 0;k<256;k++)
	{
		cout<<hashTable[k]<<endl;
	}
    if(min>=0&&min!=MAX){
		cout<<min<<endl;
        return (char)min;
    }
    return '\0';

}

int main()
{
    string s("wweea1wwqq");
    cout<<FirstAppearanceOnce(s)<<endl;
    return 0;
}
