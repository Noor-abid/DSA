#include<iostream>
using namespace std;
struct Node {
    Node * next;
    Node* prev;
    int data;
};
class linkedlist{
    Node* head;
    public:
    linkedlist(){
        head=NULL;
    }
      void addatbeginning(int value ){
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=head;
        newnode->prev=NULL;
        head=newnode;
    }
    void addatend(int value){
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        Node* temp=head;
        while(temp->next){
            temp=temp->next;

        }
        temp->next=newnode;
        newnode->prev=temp;
    }

    void insertnewnode(int val,int pos){
        Node * newnode=new Node ();
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=NULL;
    if(pos==0){
        newnode->next=head;
        if(head)
        head->prev=newnode;
        head=newnode;
    }
    Node *temp=head;
    int curr=1;
    while(temp && curr<pos-1){
    temp=temp->next;
    curr++;
    }
    if(temp==NULL){
        cout<<"Invalid postion ";
        delete newnode;
        return;
    }
    newnode->next=temp->next;
    newnode->prev=temp;

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
 void deletenode(int val){
        Node* temp=head;
        Node * prev=NULL;
    
        
    while(temp && temp->data!=val){
        prev=temp;
        temp=temp->next;
    }
    if(!temp){
        cout<<"Node with value "<<val<<" not found in linked list "<<endl;
        return;
    }
    if(prev){
 prev->next=temp->next;

    }
    else {
        head=temp->next;
    }
    delete temp;
    cout<<" value "<< val<<" deleted successfully! "<<endl;
}
void printBackward(){
    Node* temp=head;
     while(temp->next){
        temp=temp->next;
     }
     while(temp){
cout<<temp->data<<" ";
temp = temp->prev;
} 
cout<<endl;
}

};
int main(){
    linkedlist obj;
    obj.addatbeginning(3);
    obj.addatend(4);
    obj.addatend(5);
    obj.addatend(6);
    obj.addatend(7);
    obj.display();
    obj.insertnewnode(6,4);
    obj.display();
    obj.deletenode(4);
    obj.display();
    obj.printBackward();
}