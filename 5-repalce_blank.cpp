#include <iostream>
#include <exception>
using std::clog;
using std::endl;
/**
 * replace the blank in the string with the "%20"
 * caution: the cover in the memory | O(n)
 * @param str
 * @param length
 */
void replace_blank(char str[],int length){
    //extend the string
    int sum_blank=0;
    for(int i=0;i<length;i++){
        if(str[i]==' '){
            ++sum_blank;
        }
//        clog<<i<<endl;
    }
//    clog<<sum_blank<<endl;
    if(sum_blank==0){
        return;
    }
    int new_length=length+sum_blank*2;
    int i=length;
    int j=new_length;
    while(i>=0&&j>i){
        if(str[i]==' '){
            --i;
            str[j--]='0';
            str[j--]='2';
            str[j--]='%';
        } else {
            str[j--] = str[i--];
        }
    }
}

int main() {
    char str[20]=" we are happy";
//    for(char& i:str){
//        std::clog<<i<<std::endl;
//    }
    replace_blank(str,12);
//    clog<< sizeof(str)<<endl;
    for(char& i:str){
        std::clog<<i<<std::endl;
    }
//    clog<<str[14]<<endl;
    return 0;
}