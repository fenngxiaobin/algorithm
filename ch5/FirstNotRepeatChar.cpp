#include <istream>
using namespace std;

char FisrtNotRepeatingChar(char* pString)
{
    if(pString == NULL)
    {
        return '\0';
    }
    const int tableSize = 256;
    size_t hashTable[tableSize];
    for(size_t i = 0;i<tableSize;i++)
    {
        hashTable[i] = 0;
    }
    char *head = pString;
    while(*head != '\0')
    {
        hashTable[*head]++;
        head++;
    }
    head = pString;
    while(*head != '\0')
    {
        if(hashTable[*head] == 1)
        {
            return *head;
        }
        head++;
    }
    return '\0';
}


int main()
{
    char* p = "sasasaqqsasaosddsads";
    cout<<FisrtNotRepeatingChar(p)<<endl;
    return 0;
}
