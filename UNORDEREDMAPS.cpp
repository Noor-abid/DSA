#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,string>m;
    m[1]="apple";
    m[3]="cherry";
    m[2]="banana";
    for(auto&pair:m)
        cout<<pair.first<<" : "<<pair.second<<endl;
        if (m.find(2) != m.end())
        cout << "Found key 2" << endl;
}