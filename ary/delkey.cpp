#include<iostream>
#include<vector>
using namespace std;
void delKey(vector<int>& a, int key){
    int explored = 0;
    int find = 0;
    while(explored<a.size()){
        while(a[explored]==key && explored+find<a.size())
        {
            a[explored]=a[explored+find];
            a[explored+find]=key;
            find++;
        }
        explored++;
    }
    while(find--)
        a.pop_back();}

void delKeyE(vector<int>& a, int key){
    int i=0;
    int skip = 0;
    while(i+skip<a.size()){
        if(a[i+skip]==key)
            skip++;
        if(i+skip < a.size() && a[i+skip]!=key){
            a[i] = a[i+skip];
            i++;}
    }
    while(skip--)
        a.pop_back();
    }

void delKeyEE(vector<int>& a, int key){
    int writeIdx = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=key){
            a[writeIdx] = a[i];
            writeIdx++;
        }}
    int nDup = a.size()-writeIdx;
    while(nDup--)
        a.pop_back();

    //return writeIdx;
}

int main(){
    vector<int> a;
    a.push_back(10);
    a.push_back(1);
    a.push_back(10);
    a.push_back(1);
    a.push_back(10);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(10);
    a.push_back(10);
    a.push_back(10);
    a.push_back(10);
    a.push_back(1);
    a.push_back(10);
    //delKey(a, 10);
    delKeyEE(a, 10);
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<endl;
    return 1;
}
