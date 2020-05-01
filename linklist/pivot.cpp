appendNode#include<iostream>

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
        cout<<itr->val<<"->";//<<endl;
        itr =itr->next;
    }
    cout <<"\n";
}

Node* pivotingNotWorking(Node*& head, int pivot){
    Node* dummyHead = new Node{-1, NULL};
    dummyHead->next = head;
    Node* small = dummyHead;
    Node* large = head;
    Node* itr = head;
    while(itr){
        if(itr->val < pivot){
            int temp = large->val;
            large->val = itr->val;
            itr->val = temp;
            large = large->next;
            small = small->next;
        }
        if(itr->val == pivot){
            Node* temp = itr;
            itr = itr->next;
            temp->next = large;
            small->next = temp;
        }
        itr = itr->next;
    }
}

Node* appendNode(Node*& node, Node* &tail){
        tail->next = node;
        tail = tail->next;}

Node* pivoting(Node*& head, int pivot){

    Node* small_tail = new Node{-1, NULL};
    Node* equal_tail = new Node{-1, NULL};
    Node* large_tail = new Node{-1, NULL};
    Node* small_head = small_tail;
    Node* equal_head = equal_tail;
    Node* large_head = large_tail;
    Node* itr = head;
    while(itr){
        if(itr->val==pivot)
            appendNode(itr, equal_tail);
        else
            appendNode(itr, itr->val<pivot?small_tail:large_tail);
        itr = itr->next;
    }
    large_tail->next = NULL;
    small_tail->next = equal_head->next;
    equal_tail->next = large_head->next;
    return small_head->next;


}

int main(){

    Node* head = NULL;
    for(int i=1; i<10 ; i++){
        insert(head, i);
    }
    Node* head2 = NULL;
    insert(head2,11);
    insert(head2,5);
    insert(head2,7);
    insert(head2,11);
    insert(head2,2);
    insert(head2,2);
    insert(head2,3);
    show(head2);
    pivoting(head2, 5);
    show(head2);
}
