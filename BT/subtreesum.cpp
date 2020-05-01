#include<iostream>

bool FindSubTree(BTNode*& node,int sum, int targetSum){
    if(!node)
        return false;
    sum+=node->val;
    if(!node->left && !node->right)
        return sum == tragetSum;
    return targetSum == FindSubTree(node->left, sum, targetSum)||
    targetSum = FindSubTree(node->right, sum, targetSum)

}
