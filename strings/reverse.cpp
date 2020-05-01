#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void reverseLineSimple(string& s){
    reverse(s.begin(), s.end());
    size_t start=0, end;
    while(end = s.find(" ", start) != string::npos){
        reverse(s.begin()+start, s.end()+end);
        start = end + 1;
    }
    reverse(s.begin()+start, s.end());}


void subReverse(string& s, int i, int j){
    char temp;
    while(i<j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; j--;
    }
}

void reverseLine(string& s){
    int i = 0;
    int j = s.size()-1;
    subReverse(s, i, j);
    cout<<s<<endl;
    i = 0;
    j=0;

    while(i<s.size()){
        while(s[j] != ' ' && j<s.size())
            j++;
        subReverse(s, i, j-1);
        cout<<s<<endl;
        while(s[j] == ' ')
            j++;
        i=j;

    }
}

int main(){
    string input;
    getline(cin, input);
    //input = "I love my India";
    reverseLine(input);
    reverseLineSimple(input);
    cout<<input<<endl;
    reverseLineSimple(input);
    cout<<input<<endl;
    return 0;
}
