#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

    vector<vector<int>> a;
    vector<int> b;
    b.push_back(1);
    a.push_back(b);
    int n=5;
    for(int i=1; i<n; i++){
        vector<int> b;
        a.push_back(b);
        for(int j=0; j<=i; j++){
            int pl = j-1>=0?a[i-1][j-1]:0;
            int pr = j<a[i-1].size()?a[i-1][j]:0;
            a[i].push_back(pl+pr);
        }
    }

    for(int i=0; i<n; i++){
        string k("\t", (n-i)/2);
        cout<<k;
        for(int j=0; j<=i; j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }

    return 0;
}
