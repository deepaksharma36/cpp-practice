#include<iostream>

using namespace std;

struct BSTNode{

    int val;
    BSTNode* left;
    BSTNode* right;
};


int FindJustLarger(BSTNode*& node, int token){
    // for invalid inputs it will return intial value of sofarlarge
    // By invalid input I mean token > largest value in BST
    //if(node == nullptr)
    //    return sofarlarge;

    if(node->val > token){
        //sofarlarge = node->val;
        return FindJustLarger(node->left, token);}

    else
        return FindJustLarger(node->right, token);

}

int FindJustLarger(BSTNode*& node, int token, int sofarlarge){
    // for invalid inputs it will return intial value of sofarlarge
    // By invalid input I mean token > largest value in BST
    if(node == nullptr)
        return sofarlarge;

    else if(node->val > token){
        sofarlarge = node->val;
        return FindJustLarger(node->left, token, sofarlarge);}

    else
        return FindJustLarger(node->right, token, sofarlarge);

}

int main(){
    BSTNode* head = new BSTNode{5, nullptr, nullptr};
    FindJustLarger(head, 5, NULL);
    delete head;
    return 0;
}
