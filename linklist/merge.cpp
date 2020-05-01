#include<iostream>


using namespace std;


struct Node{
    int val;
    struct Node* next;
};

//Node* mergeR(Node* head1, Node* head2);


void insert(Node*& head, int val){
   head =  new Node{val, head};
}

void show(Node*& head){
    Node* p = head;
    int x;
    while(p){
        cout<<p->val<<"->";
        p = p->next;
        cin>>x;
    }
    cout<<"\n";
}

void appendNode(Node*& nextNode, Node*& tail){

    tail->next = nextNode;
    nextNode = nextNode->next; //head1 or 2 are moved ahead
    tail = tail->next;
}


Node* mergeE(Node* head1, Node* head2){
    Node dummyHead{-1, NULL};
    Node* tail = &dummyHead;
    while(head1 && head2){
        appendNode(head1->val>head2->val?head1:head2, tail);
    }
    tail = head1?head1:head2;
    return dummyHead.next;

}

Node* merge(Node* head1, Node* head2){ // 8 and 9

    //extending head1
    Node* mergeHead = new Node{-1, NULL};// = head1.val<head2.val?head1:head2;
    Node* p = mergeHead;
    while(head1 && head2){
        Node* mergingNode = head1->val>head2->val?head1:head2; //9 8
        if(head1 == mergingNode){
            head1 = head1->next; //8 // 6
            //cout<< "head1 movded"<<endl;
            }
        else{
            head2 = head2->next; //7 //7
            //cout<< "head2 moved"<<endl;
            }
        /*if(!p){
                p = mergingNode; //9
                mergeHead = p; //9
                cout<<mergeHead->val<<endl;//9
       }
        else{*/
        p->next = mergingNode; //8
        //cout<<"merging node"<<mergingNode->val<<endl;
        p = p->next; //6
        //}

        //cout<<head1==mergingNode <<endl;
        //cout << head1->val <<" "<<head2->val<<" "<<mergingNode<<endl;
    }
    p->next = head1?head1:head2;
    //return mergeHead;
    return mergeHead->next;

}


Node* mergeR(Node* head1, Node* head2){
    Node* result = NULL;

    if(head1 == NULL){
        return head2;
    }

    else if(head2 == NULL){
        return head1;
    }

    else if(head1->val > head2->val){
        result = head1;
        result->next = mergeR(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeR(head1, head2->next);

    }
    return result;


}

int main(){
   Node* head1 = NULL;
   Node* head2 = NULL;

   for(int i=0; i<10; i=i+2)
       insert(head1, i);
   show(head1);
   for(int i=1; i<10; i=i+2)
       insert(head2, i);
   show(head2);
   //Node* mergeHead = merge(head1, head2);
   //Node* mergeHeadR = mergeR(head1, head2);
   Node* mergeHead = mergeE(head1, head2);
   show(mergeHead);
   //show(head1);
   //show(head2);
   //show(mergeHeadR);
}
