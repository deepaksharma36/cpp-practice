#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<algorithm>

using namespace std;

struct HashTuple{
    size_t operator() (const std::tuple<int, int, int>& t){
        return hash<int>()(get<0>(t)) ^ hash<int>()(get<1>(t)) ^ hash<int>()(get<2>(t));
    }
};



bool IsPatternSuffixContainedStartingAtXY(const vector<vector<int>>& grid,
        int x, int y, const vector<int>& pattern, int offset,
        unordered_set<std::tuple<int, int, int>,  HashTuple>& previous_attempts){


    if(pattern.size() == offset)
        return true;

    if(x<0 || x>grid.size() || y<0 || y>grid[x].size() || previous_attempts.find(std::tuple<int, int, int>{x, y, offset}) != previous_attempts.cend()){
        return false;
    }

    if(grid[x][y] == pattern[offset] &&
            IsPatternSuffixContainedStartingAtXY(grid, x-1, y, pattern,
                offset+1, previous_attempts)||
            IsPatternSuffixContainedStartingAtXY(grid, x+1, y, pattern,
                offset+1, previous_attempts)||
            IsPatternSuffixContainedStartingAtXY(grid, x, y-1, pattern,
                offset+1, previous_attempts)||
            IsPatternSuffixContainedStartingAtXY(grid, x, y+1, pattern,
                offset+1, previous_attempts)){
        return true;
    }

    //previous_attempts.emplace_back(std::tuple<int, int, int>{x, y, offset});

    return false;
}

bool IsPatternContainedInGrid(const vector<vector<int>>& grid,
        const vector<int>& pattern){
    unordered_set<tuple<int, int, int>, HashTuple> previous_attempts;

    for(int i=0; i < grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(IsPatternSuffixContainedStartingAtXY(grid, i, j, pattern, 0, previous_attempts)){
                return true;
            }
        }
    }

    return false;
}

int main(){

    return 0;
}
