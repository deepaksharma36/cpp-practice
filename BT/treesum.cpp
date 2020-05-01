#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

struct BTNode{
    int val;
    BTNode* left;
    BTNode* right;
};

int FindSumE(BTNode* node, int num){
    if(node)
        num = (num<<1)|node->val;
    if(!node ||(!node->left && !node->right)){
        cout<<num<<endl;
        //nums.push_back(num);}
        retu num;}
    else{
    return FindSumE(node->left, num) + FindSumE(node->right, num);
}}

void FindSum(BTNode* node, int num, vector<int>& nums){
    if(node)
        num = (num<<1)|node->val;
    if(!node ||(!node->left && !node->right)){
        cout<<num<<endl;
        nums.push_back(num);}
    else{
    FindSum(node->left, num, nums);
    FindSum(node->right, num, nums);
}}

BTNode* Construct(){
    BTNode* head = new BTNode{1, nullptr, nullptr};
    BTNode* n1 = new BTNode{1, nullptr, nullptr};
    BTNode* n2 = new BTNode{0, nullptr, nullptr};
    BTNode* n3 = new BTNode{0, nullptr, nullptr};
    BTNode* n4 = new BTNode{1, nullptr, nullptr};

    head->left = n1; head->right = n2;
    n1->left = n3; n1->right = n4;

    return head;
}

int main(){
    BTNode* head = Construct();
    vector<int> sums;
    FindSum(head, 0, sums);
    cin.get();
    for(size_t i=0; i<sums.size(); i++)
        cout<<bitset<8>(sums[i])<<endl;
    cout<<FindSumE(head, 0)<<endl;
}
