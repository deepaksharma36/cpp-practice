#include<iostream>
#include<vector>

using namespace std;

//Not working
int Justlarge(vector<int>& a, int token){
    int L=0, U=a.size()-1, M;
    while(U-L> 1){
        M = L + (U-L)/2;
        if(token < M)
            U = M;
        else// if(token >= M)
            L = M+1;
        //else if(token == a[M] && U < a.size())
        //    U++;

    }
    return L;
}

int JustlargeC(vector<int>& a, int token){
    int L=0, U=a.size()-1, M, result;
    while(U>= L){
        M = L + (U-L)/2;
       if(token < a[M]){
            U = M-1;
            result = M;}
        else               // if(token >= M)
            L = M+1;
    }
    return result;
}
int main(){
    vector<int> aa = {2,4,6,7, 8,10, 15};
    vector<int> a = {5, 8, 9};
    cout<<Justlarge(a, 7)<<endl;
    cout<<JustlargeC(a, 7)<<endl;
}
