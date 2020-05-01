#include<iostream>
#include<cmath>
#include<stack>
#include<utility>
#include<exception>
#include<stdexcept>
#include<string>
using namespace std;

class stackw{
    private:
        stack<pair<int,int>> storage;
    public:
        bool isEmpty(){
            return storage.empty();
        }
        int Max(){
            if(isEmpty())
                throw length_error("max(): empty stack");
            return storage.top().second;
        }
        void push(int val){
            storage.emplace(val,isEmpty()?val:std::max(val, Max()));
        }
        int pop(){
            if(isEmpty())
                throw length_error("Pop(): empty stack");
            int top = storage.top().first;
            storage.pop();
            return top;
        }
};


int main(){
    stack<int> app;
    stackw a;
    a.push(5);
    a.push(5);
    a.push(8);
    a.push(4);
    a.push(9);
    cout<<a.Max()<<endl;
    a.pop();
    cout<<a.Max()<<endl;
}
