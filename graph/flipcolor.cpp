#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Coordinate{
    int X;
    int Y;
};

bool IsValidCoordinate(Coordinate& p, vector<vector<int>>& grid){
    if(p.X>=0 && p.Y>=0 && p.Y < grid.size()  && p.X <grid[p.Y].size())
        return true;
    return false;
}

void FlipColor(vector<vector<int>>& grid, const Coordinate& p ){

    queue<Coordinate> neighbours;
    neighbours.emplace(p);
    int color = grid[p.Y][p.X];
    vector<vector<int>> offset{{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}};
    while(neighbours.size()>0){
        Coordinate curr = neighbours.front();
        neighbours.pop();
        grid[curr.Y][curr.X] = (color+1)%2;
        for(vector<int> o: offset){
            Coordinate neighbour{curr.X+o[0], curr.Y+o[1]};
            if(IsValidCoordinate(neighbour, grid) && grid[neighbour.Y][neighbour.X]==color){
                neighbours.emplace(neighbour);
                cout<<neighbour.Y<<","<<neighbour.X<<endl;

            }
        }

        cout<<"*************"<<endl;

    }
}


int main(){

    vector<vector<int>> grid(4, vector<int>(4, 0));
    for(int i=1; i<grid.size()-1; i++){
        for(int j=1; j<grid[i].size()-1; j++){
                grid[i][j] = 1;
        }
    }
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
                cout<<grid[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"******************"<<endl;
    //void FlipColor(vector<vector<int>>& grid, Coordinate& p ){
    FlipColor(grid, Coordinate{2,2});
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
                cout<<grid[i][j]<<"  ";
        }
        cout<<"\n";
    }



}
