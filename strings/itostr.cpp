#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int strToInt(string& s){
    bool isNeg = false;
    if(s[0] == '-')
        isNeg = true;
    int result = 0;
    for(int i=isNeg?1:0 ; i<s.length();  i++){
        result*=10;
        result+=s.at(i)-'0';}
    if(isNeg)
        result*=-1;
    return result;

}

string intToStr(int num){
    string s="";
    num = abs(num);
    while(num){
       s+=('0'+num%10);
       num/=10;
    }
    reverse(s.begin(), s.end());
    if(num<0)
        s="-"+s;
    return s;
}

int main(){

    string s = "-1234";
    cout<<strToInt(s)<<endl;
    cout<<intToStr(-1234)<<endl;
    return 0;
}
