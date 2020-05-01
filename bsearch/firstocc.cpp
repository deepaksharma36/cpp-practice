#include<iostream>
#include<vector>

using namespace std;

int bsearch(vector<int>& a, int t){
    int L=0, U=a.size()-1, M, result=-1;
    while(L<U){
        M = (L+U)/2;
        if(t > a[M])
            L = M+1;
        else if(t < a[M])
            U = M-1;
        else if(t == a[M]){
            result = M;
            U = M;
        }}


    return result;
}

int main(){

    //vector<int> a{1,4,6,8,8,8,8,8,8,14,16,18,19};
    vector<int> a{8, 8};
    cout<<bsearch(a, 8)<<endl;


}


