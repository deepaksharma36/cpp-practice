#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string changeBase(string& s, int b1, int b2){
    int b10 = 0;
    int mul = 1;
    //for(int i=s.length()-1; i>=0; i--){
    for(int i=0; i<s.length(); i++){
        b10 *= b1;
        //b10 += (s[i] >= '0' && s[i] <='9')?s[i]-'0':s[i]-'A'+10;
        b10 += isdigit(s[i])?s[i]-'0':s[i]-'A'+10;
    }
    string result = "";
    int rem = 0;
    cout<<b10<<endl;
    while(b10){
        rem = b10%b2;
        result += rem<10?'0'+rem:'A'+(rem-10);
        b10 = b10/b2;
    }
    reverse(result.begin(), result.end());
    return result;
}


int main(){
    string s("FF");
    int b1 = 16;
    int b2 = 2;
    cout<<changeBase(s, b1, b2)<<endl;

}
