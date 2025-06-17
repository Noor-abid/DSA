#include<iostream>
using namespace std;
struct Node {
Node *next;
int data;
};
class linkedlist{
    Node* head;
    int size=0;
    public:
    linkedlist(){
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
    void selectionsort(){
        for(Node * i=head; i!=NULL; i=i->next){
            Node* minNode=i;
            for(Node *j=i->next; j!=NULL; j=j->next){
                if(j->data < minNode->data){
                    minNode=j;
                }
            if(minNode!=i){
                int t=i->data;
                i->data=minNode->data;
                minNode->data=t;
            }
        }
    }
}
};
int main(){
    linkedlist obj;
    obj.addatbeginning(9);
    obj.addatend(7);
    obj.addatend(10);
    obj.addatend(8);
    cout<<"Original list: ";
    obj.display();
    cout<<endl;
    cout <<"Sorted array ";
    obj.selectionsort();
    obj.display();
}