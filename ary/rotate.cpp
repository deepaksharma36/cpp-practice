#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void rotateLayer(vector<vector<int>>& mat, int offset){
    for(int col=offset; col<mat.size()-offset-1; col++){
        int t1 = mat[offset][col];
        int t2 = mat[col][mat.size()-1-offset];
        int t3 = mat[mat.size()-1-offset][mat.size()-1-col];
        int t4 = mat[mat.size()-1-col][offset];
        mat[col][mat.size()-1-offset] = t1;
        mat[mat.size()-1-offset][mat.size()-1-col] = t2;
        mat[mat.size()-1-col][offset] = t3;
        mat[offset][col] = t4;


    }
}

void rotateMat(vector<vector<int>>& mat){
    for(int offset=0; offset< ceil(.5*mat.size()); offset++)
        rotateLayer(mat, offset);
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
    cout<<"\n"<<endl;
    rotateMat(a);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<a[i][j]<<"\t";

        }
        cout<<"\n"<<endl;
    }
    return 0;
}
