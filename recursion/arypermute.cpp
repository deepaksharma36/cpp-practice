#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void FindPermutationE(vector<int>& a, vector<vector<int>>& result,  int idx){

    vector<int> acp(a);
    if(idx==a.size()-1){
        result.push_back(acp);
    }
    else{
    for(size_t i=idx; i<a.size(); i++){
        swap(a[i], a[idx]);
        cout<<"\n"<<endl;
        cout<<"With idx"<<idx<<endl;
        FindPermutationE(a, result, idx+1);
        swap(a[idx], a[i]);
    }
}}

void FindPermutation(vector<int>& a, vector<vector<int>>& result, vector<int>& partial, int idx){

    vector<int> acp(a);
    if(idx==a.size()-1){
        partial.push_back(acp[idx]);
        result.push_back(partial);
    }
    else{
    for(size_t i=idx; i<a.size(); i++){
        //swap(a[i], a[idx]);
        int temp = acp[i];
        acp[i] = acp[idx];
        acp[idx] = temp;
        vector<int> p(partial);
        for(int i=0; i<a.size(); i++)
            cout<<acp[i];
        p.push_back(acp[idx]);
        cout<<"\n"<<endl;
        cout<<"With idx"<<idx<<endl;
        FindPermutation(acp, result, p, idx+1);
    }
}}


int main(){
    vector<int> a{1,2,3,4};
    vector<vector<int>> result;
    vector<int> partial;
    int idx=0;
    //FindPermutation(a, result, partial, idx);
    FindPermutationE(a, result, idx);
    for(auto vec: result){
        for(auto v: vec)
            cout<<v<<" ";
        cout<<"\n";
    }
}
