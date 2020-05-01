#include<iostream>
#include<stack>
#include<string>
#include<sstream>

using namespace std;


int evaluate(string rpn){

    stack<int> evl;
    istringstream iss(rpn);
    string ele;
    while(getline(iss, ele, ',')){
        cout<<ele<<endl;
        if(ele!="+" && ele!= "-" && ele != "*" && ele != "/")
            evl.push(stoi(ele));
        else{
        int x = evl.top();
        evl.pop();
        int y = evl.top();
        evl.pop();

        if(ele == "+")
            evl.push(x+y);
        else if(ele == "_")
            evl.push(x-y);
        else if(ele == "*")
            evl.push(x*y);
        else if(ele == "/")
            evl.push(x/y);
    }
}
    return evl.top();}


int main(){

    string rpn;
    getline(cin, rpn);
    cout<<evaluate(rpn)<<endl;;

    return 0;
}
