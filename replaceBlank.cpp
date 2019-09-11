class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==nullptr||length<=0) return;
        int numBlank = 0;
        int i = 0;
        while(str[i]!='\0'){
            if(str[i]==' ') ++numBlank;
            ++i;
        }
        int originLength = i;
        int newLength = originLength + numBlank*2;
        if(newLength>length) return;
        if(newLength == originLength) return;
        int indexOfNew = newLength;
        int indexOfOrigin = originLength;
        while(indexOfOrigin >=0 && indexOfNew>indexOfOrigin){
            if(str[indexOfOrigin] == ' '){
                str[indexOfNew--]='0';
                str[indexOfNew--]='2';
                str[indexOfNew--]='%';
            }
            else{
                str[indexOfNew--] = str[indexOfOrigin];
            }
            indexOfOrigin--;
        }
	}
};
