#include<iostream>
#include<stack>
#include<sstream>
#include<string>

std::stack<int> load(std::istringstream& iss){
    int val;
    std::stack<int> stk;
    while(iss >> val){
        stk.push(val);
    }
    return stk;
}

void swap(int& a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

void insert(std::stack<int>& stk, int top){
    if(stk.empty() || stk.top() < top)
        stk.push(top);
    else{
        int sec_top = stk.top();
        stk.pop();
        //if(sec_top > top){
        //stk.pop();
        //swap(sec_top, top);
        insert(stk, top);
        stk.push(sec_top);
    }
}

void sort(std::stack<int>& stk){
    if(!stk.empty()){
    int top = stk.top();
    stk.pop();
    sort(stk);
    insert(stk, top);

}}

int main(){
    std::string vals;
    getline(std::cin, vals);
    std::istringstream iss(vals);
    std::stack<int> stk = load(iss);
    sort(stk);
    while(!stk.empty()){
        std::cout<<stk.top()<<std::endl;
        stk.pop();
    }

    return 0;

}
