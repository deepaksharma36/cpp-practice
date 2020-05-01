#include<iostream>
#include<memory>
#include<utility>

using namespace std;

template<typename T>
struct BTNode{
    T data;
    unique_ptr<BTNode<T>> left, right;
};

pair<bool, int> CheckBalance(const unique_ptr<BTNode<int>>& tree){

    if(tree == nullptr){
        return {true, -1};
    }

    int l_height;
    bool is_l_balance;
    tie(is_l_balance, l_height) = CheckBalance(tree->left);
    if(!is_l_balance)
        return {false, 0};
    int r_height;
    bool is_r_balance;
    tie(is_r_balance, r_height) = CheckBalance(tree->right);
    if(!is_r_balance)
        return {false, 0};
    bool is_balance = abs(l_height - r_height) <= 1;
    int height = max(l_height, r_height) + 1;
    return {is_balance, height};
}


bool IsBalance(const unique_ptr<BTNode<int>>& tree){
    return CheckBalance(tree).first;
}

BTNode<int>* Construct(){
    BTNode<int>* btn1 = new BTNode<int>{1, nullptr, nullptr};
    unique_ptr<BTNode<int>> ubtn1(btn1);
    BTNode<int>* btn2 = new BTNode<int>{1, move(ubtn1), nullptr};
    unique_ptr<BTNode<int>> ubtn2(btn2);
    BTNode<int>* head = new BTNode<int>{2, move(ubtn2), nullptr};
    //unique_ptr<BTNode<int>> uhead(head);
    return head;
    //return btn;

    //unique_ptr<BTNode<int>> ubtn(btn);
    //head->left = ubtn;


}

int main(){
    unique_ptr<BTNode<int>> head(Construct());
    //IsBalance();
    cout<<IsBalance(head)<<endl;
    return 0;
}

