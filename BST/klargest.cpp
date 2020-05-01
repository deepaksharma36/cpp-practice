#include<iostream>
#include<memory>
#include<vector>

using namespace std;

template<typename T>

struct BSTNode{
    T data;
    unique_ptr<BSTNode<T>> left;
    unique_ptr<BSTNode<T>> right;
};

void FindKLargestElementsHelper(unique_ptr<BSTNode<int>>& node, vector<int>& klarge, int k){

    if(node == nullptr)
        return;

    cout<<"gu"<<node->data<<endl;
    FindKLargestElementsHelper(node->right, klarge, k);
    //cout<<node->data<<endl;
    if(klarge.size()<k){
        klarge.push_back(node->data);
        FindKLargestElementsHelper(node->left, klarge, k);}}


vector<int> FindKLargestElements(unique_ptr<BSTNode<int>>& node, int k){

    vector<int> klarge;
    FindKLargestElementsHelper(node, klarge, k);
    return klarge;

}


unique_ptr<BSTNode<int>> Construct(){

    BSTNode* b1 = new BSTNode<int>{3, nullptr, nullptr};

    unique_ptr<BSTNode<int>> ub1(b1);
    unique_ptr<BSTNode<int>> ub2(new BSTNode<int>{7, nullptr, nullptr});
    unique_ptr<BSTNode<int>> ub3(new BSTNode<int>{2, nullptr, nullptr});
    unique_ptr<BSTNode<int>> ub4(new BSTNode<int>{4, nullptr, nullptr});
    unique_ptr<BSTNode<int>> uhead(new BSTNode<int>{5, nullptr, nullptr});

    ub1->left = move(ub3);
    cout<<"gone"<<endl;
    //ub1->right.reset(b4);
    //ub1->left.reset(b3);
    ub1->right = move(ub4);
    cout<<"gone"<<endl;
    //uhead->left.reset(b1);
    uhead->left = move(ub1);
    cout<<"gone"<<endl;
    cout<<uhead->left->data<<endl;
    //uhead->right.reset(b2);
    uhead->right = move(ub2);
    cout<<"gone"<<endl;
    cout<<uhead->data<<endl;
    //cout<<ub1->data<<endl;
    //cout<<ub2->data<<endl;
    cout<<ub3->data<<endl;
    cout<<ub4->data<<endl;
    return uhead;}

int main(){

    unique_ptr<BSTNode<int>> head;
    head = Construct();
    vector<int> klarge = FindKLargestElements(head, 3);
    for(size_t i=0; i<klarge.size(); i++)
        cout<<"ele: "<<klarge[i]<<endl;

    return 0;
}
