#include<iostream>
#include<sstream>
#include<stack>
#include<string>

using namespace std;

bool isBalanced(string& braces){
    //istringstream iss(braces);
    //string token;
    //while(getline(iss, token, '')
    stack<char> left_braces;
    for(int i=0; i<braces.size(); i++){
        if(braces[i]=='(' || braces[i] == '{' || braces[i]=='[')
            left_braces.push(braces[i]);
        else if(braces[i]==')' || braces[i]=='}' || braces[i]==']'){
            char left_brace = left_braces.top();
            if(left_brace=='(' && braces[i] != ')')
                return false;
            if(left_brace=='{' && braces[i] != '}')
                return false;
            if(left_brace=='[' && braces[i] != ']')
                return false;
            left_braces.pop();
        }

    }
    return true;
}


int main(){

    string braces;
    getline(cin, braces);
    cout<<isBalanced(braces)<<endl;

}
