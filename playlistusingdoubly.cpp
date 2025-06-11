#include<iostream>
using namespace std;
struct song{
    song* prev;
    song* next;
    string name;

};
class playlist{
    song* head;
    song* current;
    public:
    playlist(){
    head=NULL;
    }

    void addsong(string songname){
        song* newsong=new song();
        newsong->name=songname;
        newsong->next=NULL;
        newsong->prev=NULL;
        if(head==NULL){
            head=newsong;
            current=head;
            cout<<"Added song "<<songname<<endl;
        return;
        }
        song* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newsong;
        newsong->prev=temp;
cout<<"Added song "<<songname<<endl;

    }
    void playCurrent() {
        if (current!=NULL)
            cout << "Playing " << current->name << endl;
        else
            cout << "Playlist is empty "<<endl;
    }
     void playNext() {
        if (current!=NULL && current->next!=NULL) {
            current = current->next;
            playCurrent();
        } else {
            cout << "No next song."<<endl;
        }
    }
     void playPrevious() {
        if (current!=NULL && current->prev!=NULL) {
            current = current->prev;
            playCurrent();
        } else {
            cout << "No previous song. "<<endl;
        }
    }
    void showplaylist(){
        song* temp=head;
        cout<<"Playlist: "<<endl;
        while(temp){
            cout<<"song name "<<temp->name<<endl;
        if(temp==current){
            cout<<"currently playing"<<current->name<<endl;
        }
        temp=temp->next;
    }
}


};
int main(){
    playlist p;
    p.addsong("song A");
    p.addsong("song B");
    p.addsong("song c");
    p.playCurrent();
    p.playPrevious();
    p.playNext();
    p.showplaylist();
}