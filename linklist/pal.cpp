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
        cout<<itr->val<<"->";//<<endl;
        itr =itr->next;
    }
    cout <<"\n";
}

Node* reverse(Node*& head, Node*& pre){
    if(!head)
        return pre;
    Node* next = head->next;
    head->next = pre;
    return reverse(next, head);


}

Node* reverseNW(Node*& head){
    Node* dummyHead = new Node{-1, NULL};
    dummyHead->next = head;
    Node* itr = dummyHead->next;
    while(itr->next){
        Node* temp = itr->next;
        itr->next = temp->next;
        temp->next = dummyHead->next;
        dummyHead->next = temp;

        Node* itr2 = dummyHead;
        //while(itr2){
       //     cout<<itr2->val;
       //     itr2 = itr2->next;
       // }
    }
    return dummyHead->next;
}

bool isPal(Node*& head){

    Node* itr = head;
    int i = 0;
    while(itr){
        itr = itr->next;
        i++;
    }
    itr = head;
    i = i/2;
    while(i-->1){
        itr = itr->next;
    }
    Node* temp = itr->next;
    itr->next = NULL;
    cout<<itr->val<<endl;
    Node* tail = NULL;
    Node* head2 = reverse(temp, tail );
    show(head);
    show(head2);
    itr = head;
    Node* itr2 = head2;
    bool flag = true;
    while(itr){
        if(itr->val != itr2->val)
            flag = false;
        itr = itr->next;
        itr2 = itr2->next;
    }
    itr = head;
    while(itr->next)
        itr = itr->next;
    Node* s = NULL;
    head2 = reverse(head2, s);
    itr->next = head2;
    return flag;




}

int main(){

    Node* head = NULL;
    for(int i=5; i>0; i--)
        insert(head, i);
    //for(int i=1; i<12; i++)
    //    insert(head, i);
    show(head);
    Node* sudoTail = NULL;
    //head = reverse(head, sudoTail);
    //head = reverseNW(head);
    //for(int i=1; i<12; i++){
    //    cout<<head->val<<endl;
    //    head = head->next;}
    show(head);
    cout<<isPal(head)<<endl;
    //show(head);


}
