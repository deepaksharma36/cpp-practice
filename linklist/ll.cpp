#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node* next;
};

void insert(Node*& head, int val){
    head = new Node{val, head};
}

void show(Node*& head){

    Node* p = head;

    while(p){
        cout << p->val <<endl;
        p = p->next;
    }

}

int main(){

    Node* head, tail;

    for(int i=1; i<6; i++)
        insert(head, i);

    show(head);

    Node  n1, n2;
    n1.val = 5;
    n2.val = 3;

    n1.next = &n2;

    //cout << n1.val <<endl;
    //cout << n1.next->val <<endl;
    n2.next = NULL;
    //cout << n2.next==NULL?1:0;
}
