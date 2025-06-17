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
    void insertnewnode(int value,int pos ){
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        if(pos==0){
            newnode->next=head;
            head=newnode;
        }
        int current =0;
        Node* temp=head;
        while(temp && current==pos-1){
            temp=temp->next;
            current++;
        }
        if(temp==NULL){
            cout<<"invalid position! "<<endl;
            delete newnode;
            return;
        }
        newnode->next=temp->next;
        temp->next=newnode;

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
void reverselinkedlist(){
    Node* temp=head;
    Node* nextnode=NULL;
    Node* prev=NULL;
    while(temp){
        nextnode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextnode;
        
    }
    head=prev;
    cout<<"linkedlist after reversal ";
    display();
}
void linkedlistsize(){
		Node* temp=head;
		while(temp){
			temp=temp->next;
	size++;}
		
		cout<<"the size of the linkedlist is "<< size<<endl;	
	}
	bool search(int value){
		Node* temp=head;
		while(temp){
			if(value==temp->data){
				return true;
			}
            temp=temp->next;
		}
		return false;
	}
};

int main(){
    linkedlist obj;
    obj.addatbeginning(2);
    obj.addatend(3);
    obj.addatend(4);
    obj.addatend(5);
    obj.display();
    obj.insertnewnode(6,3);
    cout<<endl;
    obj.display();
    cout<<endl;
    obj.deletenode(2);
    cout<<endl;
    obj.display();
    cout<<endl;
    obj.reverselinkedlist();
    cout<<endl;
    if(obj.search(6)){
        cout<<"value found ";
    }
        else{
            cout<<"value not found "<<endl;
        }
        cout<<endl;
    obj.linkedlistsize();
}
