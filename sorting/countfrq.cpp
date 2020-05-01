#include<iostream>
#include<algorithm>

using namespace std;

void CountFrq(string& s){

    sort(s.begin(), s.end());
    int current_char_frq =1;
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1])
            current_char_frq++;// = 0;
        else{
        cout<<"Char "<<s[i-1]<<" Frq="<<current_char_frq<<endl;
        current_char_frq = 1;
        //if(i+1 == s.size() || s[i] != s[i+1])
        }
    }
}

int main(){

    string s = "deepaksharma";

    CountFrq(s);
}
