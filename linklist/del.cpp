#include<iostream>

using namespace std;
struct Node{
    int val;
    Node* next;
};


void insert(Node*& head, int val){
    head = new Node{val, head};

}


void show(Node* head_itr){
    while(head_itr){
        cout<<head_itr->val<<"->";
        head_itr = head_itr->next;
    }
    cout<<"\n";
}


void del(Node*& aNode, Node* head_itr){

    if(aNode->next){
        aNode->val = aNode->next->val;
        Node* nextNode = aNode->next->next;
        aNode->next = nextNode;}
}


void delKthLast(Node*& head, int k){
    Node* itr1 = head;
    Node* itr2 = head;
    int i = 0;
    while(i++ <= k)
        itr1 = itr1->next;
    while(itr1){
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    itr2->next = itr2->next->next;}



void delDup(Node*& head){
    Node* itr = head;
    while(itr && itr->next){
        cout<<itr->val<<endl;
        if(itr->val == itr->next->val)
            itr->next = itr->next->next;
        itr = itr->next;
    }
}

int main(){

    Node* head = NULL;
    Node* delN = NULL;
    for(int i=10;i>0;i--){
        insert(head, i);
        insert(head, i);
        if(i==3)
            delN = head;
    }
    show(head);
    //del(delN, head);
    //delKthLast(head, 3);
    delDup(head);
    //show(head);


}
