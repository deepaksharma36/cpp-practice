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

Node* appendNode(Node*& tail, int val){
        tail->next = new Node{val, NULL};
        tail = tail->next;}

Node* sum(Node*& head1, Node*& head2){
    int c = 0;
    Node* result_tail = new Node{-1, NULL};
    Node* result_head = result_tail;
    while(head1 || head2 || c){
       int e1 = head1?head1->val:0;
       int e2 = head2?head2->val:0;
       appendNode(result_tail,(e1 + e2 + c)%10);
       c = (e1 + e2 + c)/10;
       if(head1)
            head1 = head1->next;
       if(head2)
            head2 = head2->next;
    }
    return result_head->next;
}
int main(){

    Node* head = NULL;
    insert(head,4);
    insert(head,1);
    insert(head,3);

    Node* head2 = NULL;
    insert(head2,9);
    insert(head2,0);
    insert(head2,7);
    show(head2);
    Node* sumN = sum(head, head2);
    show(sumN);
}
