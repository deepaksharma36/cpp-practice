#include<iostream>
#include<vector>

using namespace std;

void FindSubSetHelper(vector<int>& input, int idx, vector<vector<int>>& powerset){
    if(idx == input.size())
        return;
    else{
        FindSubSetHelper(input, idx+1, powerset);
        int size = powerset.size();
        for(size_t i=0; i<size; i++){
            vector<int> newset = powerset[i];
            newset.push_back(input[idx]);
            powerset.emplace_back(newset);}
    }
}


void FindSubSetHelperE(vector<int>& input, int idx,
        vector<int>& selectedsofar, vector<vector<int>>& powerset){
    if(idx == input.size())
        powerset.emplace_back(selectedsofar);
    else{
        selectedsofar.emplace_back(input[idx]);
        FindSubSetHelperE(input, idx+1, selectedsofar, powerset);
        selectedsofar.pop_back();
        FindSubSetHelperE(input, idx+1, selectedsofar, powerset);}
}

void FindSubSetHelperK(vector<int>& input, int idx,
        vector<int>& selectedsofar, vector<vector<int>>& powerset, int k){
    if(idx == input.size())
        powerset.emplace_back(selectedsofar);
    else{
        selectedsofar.emplace_back(input[idx]);
        if(selectedsofar.size() + input.size() - idx > k)
            FindSubSetHelperK(input, idx+1, selectedsofar, powerset, k);
        selectedsofar.pop_back();
        if(selectedsofar.size() + input.size() - idx > k)
            FindSubSetHelperK(input, idx+1, selectedsofar, powerset, k);}
}
vector<vector<int>> FindSubSet(vector<int>& input){
    vector<vector<int>> powerset;//(1, vector<int>(1, -1));
    vector<int> selectedsofar;
    //FindSubSetHelper(input, 0, powerset);
    //FindSubSetHelperE(input, 0, selectedsofar, powerset);
    FindSubSetHelperK(input, 0, selectedsofar, powerset, 2);
    return powerset;
}


int main(){
    vector<int> input{1,2,3};
    vector<vector<int>> powerset = FindSubSet(input);
    for(int i=0; i<powerset.size(); i++){
        for(int j=0; j<powerset[i].size(); j++)
            cout<<powerset[i][j]<<", ";
        cout<<"\n";
    }

}
