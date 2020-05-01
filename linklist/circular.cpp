#include<iostream>

using namespace std;

struct Node{

    int val;
    Node* next;};

Node* insert(Node*& head, int val){
    head = new Node{val, head};}


void show(Node*& head){
    Node* head_itr = head;
    while(head_itr){
        cout<<head_itr->val<<"->";
        head_itr = head_itr->next;
    }
    cout <<"\n"<<endl;}


bool isCirculer(Node*& head){
    Node* itr1 = head;
    Node* itr2 = head;

    while(itr1 != NULL && itr2 != NULL){
        itr1 = itr1->next;
        itr2 = itr2->next;
        if(itr2 == NULL)
            return false;
        itr2 = itr2->next;
        if(itr1 == itr2)
            return true;
    }
    return false;}


    void giveOffset(Node*& head, int offset){
            while(offset--){head = head->next;}
    }

 Node* whereY(Node*& head1, Node*& head2){
    int offset = 0;
    Node* itr1 = head1;
    Node* itr2 = head2;

    while(itr1!= NULL || itr2!= NULL){
        if(itr1 != NULL)
            itr1 = itr1->next;
        if(itr2 != NULL)
            itr2 = itr2->next;
        if(itr1 == NULL or itr2 == NULL){
            offset++;
            Node* longer = itr1==NULL?head1:head2;

        }

    }
    itr1 = head1; itr2 = head2;
    giveOffset(longer==itr1?itr1:itr2);

        while(itr1 != itr2){
            itr1 = itr1->next;
            itr2 = itr2->next;
        }

    return itr1;



    }


int main(){
    Node* head=NULL;

    insert(head, 11);
    Node* tail = head;
    for(int i=10; i>0 ; i--)
        insert(head, i);
    show(head);

    //tail->next = head;

    cout<< isCirculer(head)<<endl;




}
