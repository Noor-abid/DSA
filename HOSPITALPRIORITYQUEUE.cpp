#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
struct Patient{
    string name;
    int severity;
      Patient(string n, int s) : name(n), severity(s) {}
    bool operator<(const Patient& other)const{
    return severity<other.severity;}
};
int main(){
    priority_queue<Patient>hospitalQueue;
     hospitalQueue.push(Patient("noor", 92));
hospitalQueue.push(Patient("zainab", 90));
hospitalQueue.push(Patient("eman", 91));

    if(!hospitalQueue.empty()){
        Patient p=hospitalQueue.top();
        cout<<"currently treating:  "<<p.name<<" ,severity "<<p.severity;
        cout<<endl;
        hospitalQueue.pop();
    }
 while(!hospitalQueue.empty()){
    cout<<"patients left in queue: ";
        Patient p=hospitalQueue.top();
        cout<<"patient "<<p.name<<" severity "<<p.severity;
        cout<<endl;
        hospitalQueue.pop();
    }
}