#include<iostream>
using namespace std;
struct Node{
int data;
Node* next;
};
class linkedlist{
    Node* head;
    public:
    linkedlist():head(NULL){}
    void insertatbeginning(int value){
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=head;
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
    void addnew(int value, int pos){
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        if(pos==0){
            newnode->next=head;
            head=newnode;
            return;
        }
        Node* temp=head;
        int currentpos=0;
            while(temp!=NULL && currentpos < pos-1){
                temp=temp->next;
                currentpos++;
            }
            if(temp==NULL){
                cout<<" invalid position "<<endl;
                delete newnode;
                return;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    
};
int main(){
    linkedlist obj;
    obj.insertatbeginning(2);
    obj.insertatend(3);
    obj.insertatend(4);
    obj.insertatend(5);
    obj.display();
    cout<<endl;
    obj.addnew(6,4);
    obj.display();
}