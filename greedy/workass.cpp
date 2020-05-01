#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<pair<int, int>> AssignWork(vector<int>& time){
    int i=0;
    int j=time.size()-1;
    vector<pair<int, int>> result;
    while(i<j){
        result.emplace_back(pair<int, int>(i, j));
        i++;
        j--;

    }

    return result;
}


int main(){
    vector<int> time{1,2,3,4,5,6,7,8};
    auto result= AssignWork(time);
    for(auto p: result){
        cout<<p.first<<", "<<p.second<<endl;
    }
}
