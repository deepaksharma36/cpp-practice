#include<iostream>
#include<utility>

struct BTNode{

    int val;
    BTNode* left;
    BTNode* right;
};

struct Result{
    BTNode* LCA;
    bool first;
    bool second;
};


Result* FindLCA(BTNode* itr, BTNode* n1, BTNode* n2){
    Result* r = new Result{itr, false, false};
    if(itr == nullptr)
        return r;

    if(itr == n1)
        r->first = true;
    else if(itr == n2)
        r->second = true;


    Result* r1 = FindLCA(itr->left, n1, n2);
    Result* r2 = FindLCA(itr->right, n1, n2);

    if(r1->first && r1->second)
        return r1;

    if(r2->first && r2->second)
        return r2;

    if((r1->first || r->first || r2->first))
        r->first = true;
    if((r->second || r1->second || r2->second))
        r->second = true;
    return r;

}

BTNode* Construct(BTNode*& n1, BTNode*& n2){

    BTNode* n3 = new BTNode{3, nullptr, nullptr};
    BTNode* n4 = new BTNode{4, nullptr, nullptr};
    BTNode* n5 = new BTNode{5, nullptr, nullptr};
    BTNode* n6 = new BTNode{6, nullptr, nullptr};

    BTNode* head = new BTNode{0, nullptr, nullptr};

    head->left = n3;
    head->right = n4;

    n3->left = n2;
    //n3->right = n2;

    n2->right = n5;

    n4->right = n6;

    return head;

}


int main(){

    BTNode* n1 = new BTNode{1, nullptr, nullptr};
    BTNode* n2 = new BTNode{2, n1, nullptr};
    BTNode* head = Construct(n1, n2);
    Result* r = FindLCA(head, n1, n2);
    std::cout<<r->first<<r->second<<std::endl;
    std::cout<<r->LCA->val <<std::endl;




}


