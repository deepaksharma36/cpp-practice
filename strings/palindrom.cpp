#include<iostream>
#include<string>

using namespace std;

bool isPalindrom(string& s){
    int i = 0;
    int j = s.size()-1;
    while(i<j){
        while(!isalnum(s[i]) && i<j)
            i++;
        while(!isalnum(s[j]) && i<j)
            j--;
        if(tolower(s[i]) != tolower(s[j]))
            return false;
        i++; j--;}
    return true;}


int main(){

    string input;
    getline(cin, input);
    cout<<isPalindrom(input)<<endl;


}
