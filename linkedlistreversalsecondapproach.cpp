#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class linkedlist{
    Node* head;


public:
int a[4];
int i=0;
int size=0;
linkedlist():head(NULL)
{}
void insertatbeginning(int value){
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=NULL;
    head=newnode;
}
void insertatend(int value){
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=NULL;
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
}
void display(){
    Node* temp=head;
    cout<<"linkedlist: ";
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void linkedlistsize(){
    Node* temp=head;
    while(temp){
        temp=temp->next;
        size++;

    }
    cout<<"The size of the linkedlist is: "<<size<<endl;
}

void reverselinkedlist2() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    cout << "Linked List after reversal: ";
    display();
}
};
int main(){
    linkedlist l;
    l.insertatbeginning(2);
    l.insertatend(3);
    l.insertatend(4);
    l.insertatend(5);
    l.display();
    cout<<endl;
    l.linkedlistsize();
    cout<<endl;
    l.reverselinkedlist2();
}