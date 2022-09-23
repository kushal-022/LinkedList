#include<iostream>
using namespace std;

class node{
    public:
    int data ;
    node* next ;

    node(int val){
        data = val;
        next = NULL;
    }
};


void insertAtTail(node* &head , int val){
    node* n = new node(val);

    if(head==NULL){
        head = n ;
        return ;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next  = n ;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp-> next ;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(node* &head , int val){
    node* n = new node(val);
    n->next = head;
    head=n;
}


int length(node* head){
    int l = 0  ; 
    node* temp = head ;
    while(temp!=NULL){
        l++;
        temp = temp->next ;
    }
    return l;
}

node* kappend(node* &head , int k){
    node* newhead;
    node* newtail;
    node* tail = head ;
    
    int l = length(head);
    int count = 1;

    while(tail->next!=NULL){
        if(count==l-k){
            newtail = tail ;
        }
        if(count==l-k+1){
            newhead = tail ;
        }
        tail = tail->next ;
        count ++ ;
    }

    newtail->next = NULL ;
    tail->next = head ;

    return newhead ;
}


int main()
{ 
    node* head = NULL;
    insertAtTail(head , 1);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 6);
    display(head);
    node* newhead = kappend(head , 3);
    display(newhead);


    return 0;
}