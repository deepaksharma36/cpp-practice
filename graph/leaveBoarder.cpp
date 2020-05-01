#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<array>

using namespace std;

struct Coordinate{
    int x;
    int y;
};

bool IsValidCoordinate(pair<int, int>& p, vector<vector<int>>& grid){
    if(p.first>=0 && p.second>=0 && p.first< grid.size() && p.second < grid[p.first].size())
        return true;
    return false;
}

void RemoveConnectedWhites(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
    queue<pair<int, int>> connected;
    vector<pair<int, int>> connected_buff;
    connected.emplace(pair<int, int>(i, j));
    array<array<int, 2>, 4> dirs{{{0,1}, {1,0}, {-1.0}, {0.-1}}};
    bool isOnBoarders = false;
    while(!connected.empty()){
        auto curr = connected.front();
        connected_buff.emplace_back(curr);
        connected.pop();
        visited[curr.first][curr.second] = 1;
        cout<<curr.first<<","<<curr.second<<" ";
        cout<<grid[curr.first][curr.second]<<endl;
        cout<<"size"<<grid.size()<<endl;
        cout<<(curr.second==(grid.size()-1))<<endl;
        if(grid[curr.first][curr.second]==1 && (curr.first==0 || curr.first==grid.size()-1 || curr.second==0 || curr.second==grid[curr.first].size()-1))
            isOnBoarders=true;
        cout<<isOnBoarders<<endl;
        for(array<int, 2> dir: dirs){
            pair<int, int> neighbour{curr.first+dir[0], curr.second+dir[1]};
            if(IsValidCoordinate(neighbour, grid) && grid[neighbour.first][neighbour.second]==1 && visited[neighbour.first][neighbour.second]==0)
                connected.emplace(neighbour);

        }

    }

    if(!isOnBoarders){

        for(auto p: connected_buff){
            grid[p.first][p.second] = 0;
        }

    }
}


void RemoveWhites(vector<vector<int>>& grid){

    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));


    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid.size(); j++){
            if(grid[i][j]==1 && !visited[i][j] && grid[i][j]==1)
                RemoveConnectedWhites(grid, visited, i, j);
        }
    }


}


int main(){

    vector<vector<int>> grid{{{0, 0, 0, 0}, {1, 0, 1, 1}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}};
    for(auto row: grid){
        for(auto tup: row)
            cout<<tup<<" ";
    cout<<"\n";
    }
    cout<<"*************"<<endl;
    RemoveWhites(grid);
    for(auto row: grid){
        for(auto tup: row)
            cout<<tup<<" ";
    cout<<"\n";
    }


}

