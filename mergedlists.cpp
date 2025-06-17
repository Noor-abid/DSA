#include<iostream>
using namespace std;
struct Node {
Node *next;
int data;
};
class Linkedlist{
    Node* head;
    int size=0;
    public:
    Linkedlist(){
        head=NULL;
    }
     void addatbeginning(int value ){
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=head;
        head=newnode;
    }
    void addatend(int value){
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
        while(temp){
            cout<<temp->data<<"-> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    void merge(Linkedlist & list2){
        if(!head){
            head=list2.head;
            return;
        }
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=list2.head;
    }
};
int main(){
    Linkedlist list1;
    list1.addatbeginning(2);
    list1.addatend(3);
    list1.addatend(4);
    list1.addatend(5);

    Linkedlist list2;
    list2.addatbeginning(6);
    list2.addatend(7);
    list2.addatend(8);
    list2.addatend(9);

    cout<<"List 1: ";
    list1.display();
    cout<<endl;

    cout<<"List 2: ";
    list2.display();
    cout<<endl;
    list1.merge(list2);
    cout<<"Merged list: ";
    list1.display();
}