#include<iostream>
#include<stack>

using namespace std;

struct Node{
    int order = -1;
    Node* next = NULL;
    Node* jump = NULL;
};

void show(Node* itr){
    while(itr){
        cout<<itr->order<<"->";
        itr = itr->next;
    }

    cout<<"\n";
}


void jumpOrder(Node*& head){

    stack<Node*> visited;
    //head->order = 1;
    //visited.push(head);
    int order = 1;
    Node* curr = head;
    do{
        if(!curr || curr->order != -1){
            curr = visited.top()->next;
            visited.pop();
        }
        if(curr && curr->order == -1){
            curr->order = order++;
            visited.push(curr);
            curr = curr->jump;
        }
    }while(!visited.empty());

}


int main(){
    Node* d = new Node;
    Node* c = new Node;
    Node* b = new Node;
    Node* a = new Node;
    d->next = NULL;
    d->jump = d;


    c->next = d;
    b->next = c;
    a->next = b;

    a->jump = c;
    b->jump = d;
    c->jump = b;


    jumpOrder(a);
    show(a);
    return 0;



}
