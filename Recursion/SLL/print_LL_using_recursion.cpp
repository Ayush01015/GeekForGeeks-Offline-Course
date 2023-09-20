#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class SLL{
    private:
        node *start;
    public:
        SLL();
        ~SLL();
        void view();
        void viewUsingRecursion();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* searchNode(int);
        int deleteLastNode();
        void deleteFirstNode();
        int deleteNode(node*);
        int printKthNodeFromLast(int);
        void reverseLLusingRecursion();
        SLL AddTwoNumbersLL(int,int);
};
SLL::SLL(){
    start = NULL;
}
SLL::~SLL(){
    while(start)
        deleteFirstNode();
}
void SLL::view(){
    if(start==NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(t!=NULL){
            cout<<t->item<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}
void SLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    n->next = NULL;
    if(start == NULL)
        start = n;
    else{
        node *t = start;
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
    }
}
void SLL::insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    n->next = start;
    start = n;
}
void SLL::insertAfter(node *r,int data){
    node *n = new node;
    n->item = data; 
    n->next = r->next;
    r->next = n;
}
node* SLL :: searchNode(int data){
    node *t = start;
    while(t!=NULL){
        if(t->item == data)
            return t;
        t = t->next;
    }
    cout<<"Node Not Found\n";
    return NULL;
}
int SLL :: deleteLastNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else if(start->next == NULL){
        delete start;
        start = NULL;
    }
    else{
        node *t = start;
        while(t->next->next!=NULL)
            t=t->next;
        int deletedItem = t->item; 
        delete t->next;
        t->next=NULL;
        return deletedItem;
    }
}
void SLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        start = t->next;
        delete t;
    }
}
int SLL::deleteNode(node *r){ 
    //function to delete node and it also return deleted value
    node *t = start;
    if(start == NULL){
        cout<<"List is Empty\n";
        return -1;
    }
    else if(start == r){
        start = r->next;
    }
    else{
        while(r!=t->next)
            t=t->next;
        t->next = r->next;
    }
    int deletedValue = r->item;
    delete r;
    return deletedValue;
}

/*******************
Rercursive functions
********************/

void print(node *t){
    if(t==NULL)
        return;
    cout<<t->item<<" ";
    print(t->next);
}
void SLL::viewUsingRecursion(){
    if(start==NULL){
        cout<<"List is Empty\n";
        return;
    }
        print(start);
}

void printKthNode(node *t,int &k){
    if(t==NULL)
        return;
    printKthNode(t->next,k);
    k--;
    if(k == 0)
        cout<<t->item<<endl;
}

int SLL::printKthNodeFromLast(int k){
    printKthNode(start,k);
}

node* reverseLL(node *head){
    if(head==NULL || head->next == NULL)
        return head;
    node *newHead = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void SLL::reverseLLusingRecursion(){
    node *revStart = reverseLL(start);
    start = revStart; // new reversed start
}

/*
    Add two numbers represented by LL
    INPUT
    43  4->3->NULL
    345 3->4->5->NULL
    OUTPUT
    388 3->8->8->NULL
*/
// SLL SLL :: AddTwoNumbersLL(int a,int b){
//     SLL l;
//     int val,sum = a + b;
//     while(sum){
//         val = sum % 10;
//         l.insertAtFirst(val);
//         sum = sum / 10;
//     }
//     return l;
// }
void rec(SLL &l,int sum){
    if(sum == 0)
        return;
    int val = sum % 10;
    l.insertAtFirst(val);
    rec(l,sum/10);
}
SLL SLL :: AddTwoNumbersLL(int a,int b){
    SLL l;
    int sum = a + b;
    rec(l,sum);
    return l;
}

int main(){
    SLL l;
    l.insertAtLast(10);
    l.insertAtLast(20);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(50);
    l.viewUsingRecursion();
    cout<<endl;
    // l.printKthNodeFromLast(4);
    l.reverseLLusingRecursion();
    l.view();
    SLL l2 = l.AddTwoNumbersLL(100000,300);
    l2.view();

    return 0;
}
