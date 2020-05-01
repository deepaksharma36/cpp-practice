#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

bool IsPalindromic(string str){
    unordered_map<char, int> map;
    for(char c: str){
        if(map.find(c) == map.end())
            map[c] = 1;
        else
            map[c]++;
    }

    int numOdd = 0;
    for(const pair<char, int>& p : map){
        if((p.second%2) && ++numOdd>1)
         return false;
    }
    return true;
}

int main(){

    string s("ffucckk");
    cout<<IsPalindromic(s)<<endl;
}
