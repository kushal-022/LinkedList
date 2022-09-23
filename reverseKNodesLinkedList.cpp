#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head , int val){
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return ;
    }

    node* temp = head ;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n ;
}

void insertAtHead(node* &head , int val){
    node* n = new node(val);
    n->next = head ;
    head = n;
}

node* reverseK(node* &head , int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;

    while(currptr!=NULL && count < k){
        nextptr = currptr->next ;
        currptr->next = prevptr ;
        prevptr = currptr ;
        currptr = nextptr ;
        count++ ;
    }

    if(nextptr != NULL){
        head->next = reverseK(nextptr , k);
    }
    
    return prevptr ;
}

void display(node* head){
    node* temp = head ;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}



int main()
{

    node* head = NULL ;
    insertAtTail(head , 1);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 6);
    display(head);
    //cout<<search(head , 4)<<endl;
    int k = 2;
    node* newhead = reverseK(head , k);
    display(newhead);


    return 0;
}