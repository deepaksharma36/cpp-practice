#include<iostream>
#include<stack>
#include<sstream>
#include<utility>
#include<vector>

using namespace std;

vector<int> ExamineBuildingWithSunSet(istringstream& sin){

    int building_height = 0;
    int building_idx = 0;
    int max_height = 0;
    stack<pair<int, int>> allowed_buildings;
    while(sin>>building_height){
        while(!allowed_buildings.empty() && building_height> allowed_buildings.top().first)
            {
                allowed_buildings.pop();
            }
            allowed_buildings.emplace(building_height, building_idx++);
    }
    vector<int> build_idx;
    while(!allowed_buildings.empty()){
        build_idx.push_back(allowed_buildings.top().second);
        allowed_buildings.pop();
    }
    return build_idx;


}

int main(){
    string buildings;
    getline(cin, buildings);
    istringstream sin(buildings);
    vector<int> build_idx = ExamineBuildingWithSunSet(sin);
    for(int i=0; i<build_idx.size(); i++)
        cout<<build_idx[i]<<endl;
    return 0;
}
