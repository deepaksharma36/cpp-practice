#include<iostream>
#include<vector>


bool IsExist(vector<vector<int>>& mat, int num){

    int col = mat[0].size()-1;
    int row =0;

    while(col>0 && row<mat.size()){
        if(mat[row][col]==num)
            return true;
        else if(mat[row][col] > num)
            col--;
        else if(mat[row][col] < num)
            row++;
    }

    return false;
}
