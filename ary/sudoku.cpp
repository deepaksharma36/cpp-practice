#include<iostream>
#include<vector>
#include<deque>
#include<cmath>

using namespace std;

bool isValidBlock(const vector<vector<int>>& partial, int x1, int x2, int y1, int y2){
    deque<bool> exists(partial.size()+1, false);
    for(int row=x1; row<x2; row++){
        for(int col=y1; col<y2; col++){
                if(partial[row][col]!=0 && exists[partial[row][col]])
                    return false;
                exists[partial[row][col]] = true;
        }
    }
    return true;
}


bool isValidSudoku(const vector<vector<int>>& partial){

    for(int row=0; row<partial.size(); row++){
        if(!isValidBlock(partial, row, row+1, 0, partial.size()))
            return false;
    }
    for(int col=0; col<partial.size(); col++){
        if(!isValidBlock(partial, 0, partial.size(), col, col+1))
            return false;
    }
    int region_size = sqrt(partial.size());

    for(int row=0; row<region_size; row++){
        for(int col=0; col<region_size; col++){
            if(!isValidBlock(partial, row*region_size, row*(region_size+1), col*region_size, col*(region_size+1)))
                return false; }}
    return true;
}

int main(){
    return 0;
}
