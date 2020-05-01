#include<iostream>
#include<vector>
#include<string>

using namespace std;

void strconv(vector<string>& mapping, string num, int idx,  vector<string>& result, string ps){
    if(idx >= num.size()){
        result.push_back(ps);}
    else
        {
        for(char c: mapping[num[idx]-'0'])
            strconv(mapping, num, idx+1,  result, ps+c);
            }}


int main(){
    vector<string> mapping ={"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i=0; i<mapping.size(); i++)
        cout<<mapping[i]<<endl;
    vector<string> result;
    int idx = 0;
    string num;
    string ps = "";
    getline(cin, num);

    strconv(mapping, num, idx,  result, ps);
    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<endl;

    return 0;
}
