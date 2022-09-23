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

void display(node* head){
    node* temp = head ;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverse(node* &head){
    node* prevptr = NULL ;
    node* currptr = head ;
    node* nextptr ;

    while(currptr != NULL){

        nextptr = currptr->next ;  //initialization of next pointer as next pointer  comes after current pointer . order-> pervious , current , next ;
        currptr->next = prevptr ;  //changing the link;

        prevptr = currptr ;  //increasing all pointers to the right side by 1 point ;
        currptr = nextptr ;
    }
    return prevptr ;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next = head ;  //refer to the video at timeline 7:00 minutes if u dont understand ;
    head->next = NULL;

    return newhead;
}

int main()
{

    node* head = NULL ;
    insertAtTail(head , 1);
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    display(head);
    //cout<<search(head , 4)<<endl;
    node* newhead = reverse(head);
    display(newhead);

    return 0;
}
