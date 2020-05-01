#include<iostream>

using namespace std;

struct Node{

    int val;
    Node* next;
};


void insert(Node*& head, int val){
    head = new Node{val, head};

}

void show(Node* itr){
    while(itr){
        cout<<itr->val;
        itr = itr->next;
    }
    cout<<"\n";
}

Node* rightSift(Node*& head, int k){
    Node* itr1 = head;
    Node* itr2 = head;
    while(k-- && itr1){
        itr1 = itr1->next;
    }
    while(itr1->next){
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    cout<<itr1->val<<endl;
    cout<<itr2->val<<endl;

    itr1->next = head;
    Node* newHead = itr2->next;
    itr2->next = NULL;
    return newHead;

}

int main(){

    Node* head = NULL;
    for(int i=10; i>0; i--)
        insert(head, i);
    show(head);
    head = rightSift(head, 3);
    show(head);

}
