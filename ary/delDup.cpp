#include<iostream>
#include<vector>

using namespace std;

void delDup(vector<int>& a){
    int writeIdx = 1;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=a[writeIdx-1])
            a[writeIdx++] = a[i];}
    cout<<writeIdx<<endl;
}


int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(6);
    //delKey(a, 10);
    delDup(a);
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<endl;
    return 1;
}
