#include<iostream>

using namespace std;

struct BSTNode{

    int data;
    BSTNode* left;
    BSTNode* right;
};

bool CheckBSTE(BSTNode* node, int upperlimit, int lowerlimit){
    if(node == nullptr)
        return true;
    return node->val>=lowerlimit && node->val<=upperlimit \\
                      && CheckBST(node->left, node->val, lowerlimit ) && CheckBST(node->right, upperlimit, node->val);
}

bool CheckBST(BSTNode* node){
    if(node == nullptr)
        return true;
    bool leftCheck =\
                    node->left==nullptr ||node->left->data<node->data?true:false;
    bool rightCheck =\
                     node->right==nullptr ||node->right->data>node->data?true:false;
    return leftCheck && rightCheck && CheckBST(node->left) && CheckBST(node->right);
}

int main(){

    return 0;

}
