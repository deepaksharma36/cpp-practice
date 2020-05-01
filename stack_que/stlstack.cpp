#include<iostream>
#include<stack>
#include<utility>

using namespace std;

//#define LOG(a){cout<<a<<endl;}

int main(){

    stack<int> a;
    a.push(5);
   a.push(2);
    a.push(1);
    a.push(6);
    a.push(8);

    //LOG(a.top);
    cout<< a.top()<<endl;

    stack<pair<int,int>> b;
    b.emplace(1,3);
    b.emplace(2,2);
    b.emplace(3,1);

    cout<< b.top().first<<endl;

}
