class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool found = false;
        if(!array.empty()){
            int cow = 0;
            int cows = array.size();
            int columns = array[0].size();
            int column = columns-1;
            while(cow<cows&&column>=0){
                if(array[cow][column]==target){
                    found = true;
                    break;
                }
                if(array[cow][column]<target){
                    ++cow;
                }else{
                    --column;
                }
            }
        }
        return found;
    }
};
