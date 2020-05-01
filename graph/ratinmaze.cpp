#include<iostream>
#include<array>
#include<vector>

using namespace std;

enum Color{WHITE, BLACK};

struct Coordinate{
    bool operator==(const Coordinate& that) const{
        return that.x==x && that.y==y;
    }

    int x, y;
};

bool IsFeasiable(const vector<vector<Color>>& maze, Coordinate& next){
    if(next.x>-1 && next.y>-1 && next.x<maze.size() && next.y<maze[next.x].size()
            && maze[next.x][next.y] == WHITE)
        return true;
    return false;

}

bool SearchMazeHelper(vector<vector<Color>>& maze, vector<Coordinate>& path,
        Coordinate curr, Coordinate e){
    if(curr==e)
        return true;
    const array<array<int, 2>, 4> kShift = {{{0,1}, {0, -1}, {1, 0}, {-1,0}}};
    for(const array<int, 2>& s: kShift){
        Coordinate next{curr.x+s[0], curr.y+s[1]};
        if(IsFeasiable(maze, next)){
            maze[next.x][next.y] = BLACK;
            path.emplace_back(next);
            return SearchMazeHelper(maze, path, next, e);
        }
        path.pop_back();
    }
}

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, Coordinate s, Coordinate e){
    vector<Coordinate> path;
    path.emplace_back(s);
    if(SearchMazeHelper(maze, path, s, e)){
        return path;
    }
    path.pop_back();
    return path;



}



int main(){

    vector<vector<Color>> maze(10, vector<Color>(10, WHITE));
    Coordinate s{0,0};
    Coordinate e{9,9};
    //vector<Coordinate> path;
    SearchMaze(maze,  s, e );

}
