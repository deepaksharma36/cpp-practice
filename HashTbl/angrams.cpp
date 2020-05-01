#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

unordered_map<string, vector<string>> FindAngrames(vector<string> an){

    unordered_map<string, vector<string>> map;
    for(string s: an){
        cout<<s<<endl;
        string org = s;
        sort(s.begin(), s.end());
        cout<<s<<endl;
        //if(map.find(s) != map.end())
        map[s].push_back(org);
        //else{
        //vector<string> set{org};
        //map.insert({s,  set});
    //}
    }

    return map;


}


int main(){

    vector<string> an{string("iloveu"), string("uliove"), string("fuck"), string("fcuk"), string("kucf")};
    //unordered_map<string, vector<string>> FindAngrames(an);
    auto result = FindAngrames(an);

    for(string s: result[string("eilouv")])
        cout<<s<<endl;
    cout<<"\n"<<endl;
    for(string s: result[string("cfku")])
        cout<<s<<endl;
}
