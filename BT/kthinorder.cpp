#include<iostream>
using namespace std;

struct BTNode{
    int val;
    int subsize;
    BTNode *left, *right;

};

BTNode* FindKth(BTNode* node,int k){
    if(k > node->subsize){
        cout<<"Invalid"<<endl;
        return nullptr;}

    int left_size = node->left?node->left->subsize:0;
    if(k<=left_size)
        return FindKth(node->left, k);
    else if(k==left_size+1)
        return node;
    else //if(k>left_size+1)
        return FindKth(node->right, k-(left_size+1));


}

int main(){

    BTNode* head = new BTNode{1, 1, nullptr, nullptr};
    BTNode* target = FindKth(head, 3);
    cout<<target->val<<endl;

}
