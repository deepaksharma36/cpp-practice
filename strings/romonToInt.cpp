#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int romtodec(string& s){
    //reverse(s.begin(), s.end());
    unordered_map<char, int>  h = {{'I', 1}, {'V', 5},
                                   {'X', 10}, {'L', 50},
                                   {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;
    for(size_t i=0; i<s.size()-1; i++){
        if(h[s[i]] < h[s[i+1]])
            result -= h[s[i]];
        else
            result += h[s[i]];
    }

    result += h[s[s.size()-1]];
    return result;
}

int main(){
    string s;
    getline(cin, s);
    cout<<romtodec(s)<<endl;
    return 0;
}
