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
    void bubblesorting(){
        Node * temp=head;
        while (temp){
            size++;
            temp=temp->next;
        }
        for(int i=0;i<size-1;i++){
            Node* temp=head;
            while(temp->next){
                if(temp->data>temp->next->data){
                    int t=temp->data;
                    temp->data=temp->next->data;
                    temp->next->data=t;

                }
                temp=temp->next;
            }
        }
    }
};
int main(){
    Linkedlist obj;
    obj.addatbeginning(9);
    obj.addatend(6);
    obj.addatend(4);
    obj.addatend(1);
    cout<<"Original list: ";
    obj.display();
    obj.bubblesorting ();
    cout<<endl;
    cout<<"Sorted list: ";
    obj.display();
}