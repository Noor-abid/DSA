#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>max;
    max.push(14);
    max.push(12);
    max.push(15);
    while(!max.empty()){
        cout<<max.top()<<endl;
        max.pop();
    }
}