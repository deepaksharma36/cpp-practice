#include<iostream>
#include<vector>

using namespace std;

int FindNumEqualIdx(vector<int>& a){
    int L=0, U=a.size()-1, M;
    while(U>=L){
        M = L + (U-L)/2;
        if(a[M] > M)
            U = M-1;
        else if(a[M] < M)
            L = M+1;
        else // a[M] == M
            return M;
    }
    return -1;
}


int main(){
    vector<int> a{-2,-1,0,3,5, 8};
    cout<<FindNumEqualIdx(a)<<endl;
}
