#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> >min;
    min.push(14);
    min.push(12);
    min.push(15);
    while(!min.empty()){
        cout<<min.top()<<endl;
        min.pop();
    }
}