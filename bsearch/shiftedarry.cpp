#include<iostream>
#include<vector>

using namespace std;

int FindSmallestHelperC(vector<int>& a, int L, int U){
    int M = L + (U-L)/2;
    cout<<M<<","<<L<<","<<U<<endl;
    if(U<=L){
        return a[U];//<a[U]?a[L]:a[U];
    }
    int left = FindSmallestHelperC(a, L, M);
    int right = FindSmallestHelperC(a, M+1, U);
    cout<<left<<endl;
    cout<<right<<endl;
    return left<right?left:right;

}

int FindSmallestHelperC2(vector<int>& a, int L, int U){
    int M = L + (U-L)/2;
    cout<<M<<","<<L<<","<<U<<endl;
    if(U<=L){
        cout<<"here"<<endl;
        return a[U];//<a[U]?a[L]:a[U];
    }
    int left = FindSmallestHelperC(a, L, M);
    int right = FindSmallestHelperC(a, M+1, U);
    cout<<left<<endl;
    cout<<right<<endl;
    return left<right?left:right;

}
int FindSmallestHelper(vector<int>& a, int L, int U){
    int M = L + (U-L)/2;
    cout<<M<<","<<L<<","<<U<<endl;
    if(U-L<=1)
        return a[L]<a[U]?a[L]:a[U];
    if(M+1<a.size() && M-1>-1){
        if(a[M+1]>a[M] && a[M-1]>a[M])
            return a[M];}
    int left = FindSmallestHelper(a, L, M-1>0?M-1:0);
    int right = FindSmallestHelper(a, M+1<a.size()?M+1:M, U);
    cout<<left<<endl;
    cout<<right<<endl;
    return left<right?left:right;

}

int FindSmallestTheRightWay(vector<int>& a, int L, int U){
    int M = L + (U-L)/2;
    if(L >= U)
        return a[L];
    if(a[M] > a[U])
        FindSmallestTheRightWay(a, M+1, U);
    else if(a[M] < a[U])
        FindSmallestTheRightWay(a, L, M);
    else{
        int right = FindSmallestTheRightWay(a, M+1, U);
        int left = FindSmallestTheRightWay(a, L, M);
        return right<left?right:left;
    }


}

int main(){

    //vector<int> a{10, 11, 15, 1, 4, 5, 7, 8};
    vector<int> a{1,5,};
    cout<<FindSmallestHelperC(a, 0, a.size()-1)<<endl;
}
