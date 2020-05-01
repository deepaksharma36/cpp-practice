#include<iostream>

struct Node{
    int val;
    Node* left;
    Node* right;
};


int construct_child(Node*& itr, int i){

    if(i<10)
        std::cout<<i<<std::endl
        itr-> left = new Node{i++, nullptr, nullptr};
        itr-> right = new Node{i++, nullptr, nullptr};
        construct_child(itr->left, i++);
        construct_child(itr->right, i++);





}


Node*& construct(){
    Node* root = new Node{0, nullptr, nullptr};
    Node* itr = root;
    construct_child(itr, 1);

}

int main(){

    Node* left1 = new Node{2, nullptr, nullptr};
    Node* right1 = new Node{3, nullptr, nullptr};
    Node* root = new Node{1, left1, right1};
    Node* head = construct();

}
