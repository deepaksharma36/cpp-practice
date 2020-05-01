#include<iostream>
#include<memory>

using namespace std;

template<typename T>
struct BTNode{
 T data;
 unique_ptr<BTNode<T>> left, right;
};


bool CheckMirror(unique_ptr<BTNode<int>>& left, unique_ptr<BTNode<int>>& right){

    if(left==nullptr && right==nullptr)
        return true;

    if(left!=nullptr && right!=nullptr)
        return left->data == right->data && CheckMirror(left->left, left->right) && CheckMirror(right->left, right->right);

    return false;

}

bool IsMirror(unique_ptr<BTNode<int>>& tree){

    return CheckMirror(tree->left, tree->right);

}
unique_ptr<BTNode<int>>& Construct(){

    BTNode<int>* b1 = new BTNode<int>{1, nullptr, nullptr};
    BTNode<int>* b2 = new BTNode<int>{2, nullptr, nullptr};
    BTNode<int>* head = new BTNode<int>{2, nullptr, nullptr};

    unique_ptr<BTNode<int>> ub1(b1);
    unique_ptr<BTNode<int>> ub2(b2);
    unique_ptr<BTNode<int>> uhead(head);

    //uhead->left = move(b1);
    //uhead->right = move(b2);
    return uhead;



}

int main(){

    unique_ptr<BTNode<int>> tree = move(Construct());
    cout<<IsMirror(tree)<<endl;
    cin.get();


}
