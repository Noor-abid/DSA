#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class linkedlist{
	Node* head;
	int a[4];
	int i=0;
	
	public:
		linkedlist():head(NULL){
		}
		int size=0;
		void insertatbeginning(int value){
		Node* newNode=new Node();
		newNode->data=value;
		newNode->next=head;
		head=newNode;}
		void insertatend(int value){
			Node* newNode=new Node();
			newNode->data=value;
			newNode->next=NULL;
		
		Node *temp=head;
		while(temp->next){
			temp=temp->next;
		}
		temp->next=newNode;
	}
	void print() {
		Node* temp=head;
		while(temp){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void reverse(){
		Node* temp=head;
		while(temp){
			a[i]=temp->data;
			
			i++;
			
		temp=temp->next; }
		
		for(int i=3;i>=0;i--){
			cout<<a[i]<<",";
		}
	}
	
	void linkedlistsize(){
		Node* temp=head;
		while(temp){
			temp=temp->next;
	size++;}
		
		cout<<"the size of te linkedlist is "<< size<<endl;	
	}
	bool search(int value){
		Node* temp=head;
		while(temp){
			if(value==temp->data){
				return true;
			
				
			}temp=temp->next;
		}
		return false;
	}
};
int main(){
	linkedlist l;
	l.insertatbeginning(2);
	l.insertatend(5);
	l.insertatend(10);
	l.insertatend(15);
	int a;
	label:
	cout<<"press 1 to display the linkedlist "<<endl;
	cout<<"press 2 to search the value in the linked list "<<endl;
	cout<<"press 3 to exit "<<endl;
	cout<<"press 4 to display te size of the linked list "<<endl;
	cout<<"press 5 to reverse the linkedlist "<<endl;
	cin>>a;
	switch (a){
		case 1:
			l.print();
			goto label;
		case 2:
			if	(l.search(10)){
				cout<<"value found "<<endl;
			}
			else {
				cout<<"value not found "<<endl;
			}
			
		
			goto label;
		case 3:
			cout<<"program exit successfully "<<endl;
			break;
			case 4:
				l.linkedlistsize();
				case 5:
					l.reverse();
	}
	
}