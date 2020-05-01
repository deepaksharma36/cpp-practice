#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<exception>
#include<stdexcept>
using namespace std;

vector<string> getSortPath(string& path){
    string token;
    vector<string> sortPath;
    if(path.front() == '/')
        sortPath.emplace_back("/");
    istringstream iss(path);
    while(getline(iss, token, '/')){
        if(token == ".."){
            if(sortPath.empty() || sortPath.back() == "..")
                sortPath.emplace_back("..");
            else{
                if(sortPath.back() == "/")
                    throw invalid_argument("Path error");
                sortPath.pop_back();
        }}

        else if(token != "." && token !="/")
            sortPath.push_back(token);
    }
    return sortPath;
}

int main(){
    string path;
    getline(std::cin, path);
    vector<string> sortPath = getSortPath(path);
    for(int i=0; i<sortPath.size(); i++)
        cout<<sortPath[i]<<endl;

}
