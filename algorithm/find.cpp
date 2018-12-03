#include <iostream>
#include <exception>
/**
 * find a target num in a 2-D array, the 2-D array increase from left to right and from up to down
 * caution: the rows and the cols can not be larger than the matrix
 * @param matrix
 * @param rows
 * @param cols
 * @param target
 * @return
 */
bool find(int** matrix,int rows,int cols,int target){
//    std::clog<<*matrix[0]<<" "<<*matrix[2]<<" "<<std::endl;
    bool found= false;
    try {
        if(matrix!= nullptr&&rows>0&&cols>0){
            int row=0,column=cols-1;
            while(row<rows&&column>=0){
                if(matrix[row][column]==target){
                    found = true;
                    break;
                } else if(matrix[row][column]>target){
                    --column;
                } else{
                    ++row;
                }
            }
        }
    }catch (std::exception &e){
        std::clog<<"越界异常:"<<e.what()<<std::endl;
    }


    return found;
}




int main() {
    const int rows=4;
    const int cols=4;
    //在堆上创建二维数组
    int** matrix=new int* [rows];
    for(int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }
    matrix[0][0]=1;
    matrix[0][1]=2;
    matrix[0][2]=8;
    matrix[0][3]=9;
    matrix[1][0]=2;
    matrix[1][1]=4;
    matrix[1][2]=9;
    matrix[1][3]=12;
    matrix[2][0]=4;
    matrix[2][1]=7;
    matrix[2][2]=10;
    matrix[2][3]=13;
    matrix[3][0]=6;
    matrix[3][1]=8;
    matrix[3][2]=11;
    matrix[3][3]=15;
    std::clog<<"find?:"<<find(matrix,4,4,19)<<std::endl;
    std::clog<<"find?:"<<find(nullptr,4,4,19)<<std::endl;
    std::clog<<"find?:"<<find(matrix,100,100,19)<<std::endl;



    for (int j = 0; j < rows; ++j) {
        delete matrix[j];
        matrix[j]= nullptr;
    }
    delete matrix;
    return 0;
}