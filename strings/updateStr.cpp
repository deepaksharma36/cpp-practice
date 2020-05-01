#include<iostream>
#include<string>
#include<vector>

using namespace std;

void updateStr(string& s){
    int newLen = 0;
    int oldLen = s.size();
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'a')
            newLen += 2;
        else if(s[i] != 'b')
            newLen += 1;
    }
    cout << newLen <<endl;
    s.resize(newLen);
    int writeIdx = newLen-1;
    int i = oldLen-1;
    while(writeIdx >= 0){
        cout<<i<<s[i]<<writeIdx<<endl;
       if(s[i] != 'b' && s[i] != 'a')
           s[writeIdx--] = s[i--];
       else if(s[i--] == 'a'){
           s[writeIdx--] = 'd';
           s[writeIdx--] = 'd';}
        else
            i--;}

}

int main(){

    string s;
    getline(cin, s);
    updateStr(s);
    cout<<s<<endl;
    return 0;
}
