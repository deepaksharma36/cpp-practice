#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

    priority_queue<int> g;
    g.push(5);
    g.push(3);
    g.push(95);
    g.push(65);
    g.push(43);
    g.push(33);
    cout<<g.top()<<endl;
    g.pop();
    cout<<g.top()<<endl;
    eturn 0;
}





