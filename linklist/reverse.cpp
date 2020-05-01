#include<iostream>

using namespace std;

struct Node{

    int val;
    struct Node* next;


};

void insert(Node*& head, int val){

    head =  new Node{val, head}; //C++ 11 compliler std-c++11 flag
}

void show(Node* head){
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"\n";
}


Node* reverse(Node* head){
    Node* nextNode = head->next;
    Node* preNode = NULL;
    while(nextNode){
        head->next = preNode;
        preNode = head;
        //cout<<preNode->val<<endl;
        head = nextNode;
        nextNode = nextNode->next;
    }
    head->next = preNode;
    return head;
}

Node* reverse(Node* curr, Node* prev){

    if(!curr)
        return prev;

    Node* next = curr->next;
    curr->next = prev;
    reverse(next, curr);
    //prev = curr;
}

Node* reverseph(Node* curr, Node* prev, Node* last){

    if(curr==last)
        return prev;

    Node* next = curr->next;
    cout<<next->val<<endl;
    curr->next = prev;
    reverseph(next, curr, last);
    //prev = curr;
}


void reverse_partialNR(Node*& head, int s, int e){
    int idx =1;
    Node* p_head =  head;
    Node* sub_head_pre = new Node{-1, NULL};
    Node* result =  sub_head_pre;
    sub_head_pre->next = head;
    while(idx<s){
        //sub_head_pre = p_head;
        sub_head_pre = sub_head_pre->next; idx++;
         }
    cout<< sub_head_pre->val<<endl;
    Node* pre_head = NULL;
    Node* sub_head = sub_head_pre->next;
    Node* iter_head = sub_head;
    while(idx<=e){
        Node* next = iter_head->next;
        iter_head->next = pre_head;
        pre_head = iter_head;
        iter_head = next;
        idx++;
    }
    cout<< pre_head->val<<endl;
    cout<< sub_head_pre->val<<endl;
    sub_head_pre->next = pre_head;
    sub_head->next = iter_head;
    //head = s==1? sub_head_pre->next:head;
    head = result->next;

}

Node* reverse_partialSE(Node* head, int s, int e){
    int idx = 1;
    Node* dummyHead = new Node{-1, head};
    Node* sublist_head = dummyHead;
    while(idx++ < s){
        sublist_head = sublist_head->next;
    }

    Node* sublist_itr = sublist_head->next;
    while(idx++ < e){
        Node* temp = sublist_itr -> next;
        sublist_itr->next = temp->next;
        temp->next = sublist_head->next;
        sublist_head->next = temp;
        //sublist_itr = sublist_itr->next;

    }
    return dummyHead->next;


}

void reverse_partial(Node* head, int s, int e){
    int idx = 1;
    Node* tail;
    while(idx<s-1){
        head = head->next;
        idx++; }
    tail = head;
    while(idx<=e){
        tail = tail->next;
        idx++;
    }
    cout <<"head"<< head->val <<endl;
    cout <<"tail"<< tail->val <<endl;
    //Node* reversetail = head->next;
    Node* prl = reverseph(head->next, tail, tail);
    cout<<"reverse"<<endl;
    cout<<prl->val<<endl;
    cout<<prl->next->val<<endl;
    cout<<prl->next->next->val<<endl;
    cout<<prl->next->next->next->val<<endl;
    //reversetail->next = tail;
    head->next =prl;
    //show();


}

int main(){

    Node* head =  NULL;

    for(int i=10; i>0; i--)
        insert(head, i);
    show(head);
    //head = reverse(head);
    //head = reverse(head, NULL);
    //reverse_partial(head, 1, 9);
    //reverse_partialNR(head, 1, 4);
    head = reverse_partialSE(head, 5, 8);
    show(head);

    return 0;
}
