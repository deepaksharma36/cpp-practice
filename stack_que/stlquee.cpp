#include<iostream>
#include<queue>

using namespace std;

void showq(queue<int> gq){

    queue<int> g = gq;
    while(!g.empty()){
        cout << '\t' << g.front();
        g.pop();
    }
    cout << "\n";
}

int main(){
    queue <int> gquiz;

    gquiz.push(10);
    gquiz.push(20);
    cout<<"queue is ";
    showq(gquiz);

    gquiz.pop();
    showq(gquiz);
    return 0;
}
