#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void printLayer(vector<vector<int>>& mat, int offset){
    for(int col=offset; col<mat.size()-offset; col++)
        cout<<mat[offset][col]<<"\t";
    for(int row=offset+1; row<mat.size()-offset; row++)
        cout<<mat[row][mat.size()-offset-1]<<"\t";

    for(int col=mat.size()-offset-2; col>=offset; col--)
        cout<<mat[mat.size()-offset-1][col]<<"\t";

    for(int row=mat.size()-offset-2; row>offset; row--)
        cout<<mat[row][offset]<<"\t";
}

void printSeq(vector<vector<int>>& mat){
    for(int offset=0; offset<ceil(.5*mat.size()); offset++)
        printLayer(mat, offset);
        cout<<"\n"<<endl;
}

int main(){
    vector<vector<int>> a;
    for(int i=0; i<4; i++){
        vector<int> b;
        a.push_back(b);
        for(int j=0; j<4; j++){
            a[i].push_back(i*4+j);

        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<a[i][j]<<"\t";

        }
        cout<<"\n"<<endl;
    }
    printSeq(a);

    return 0;
}
