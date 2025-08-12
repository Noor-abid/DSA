#include<iostream>
using namespace std;
void TowerOfHanoi(int n,char from_rod, char to_rod, char aux_rod){
    if(n==1){
        cout<<"move disk 1"<<" from "<<from_rod<<" to "<<to_rod<<endl;
        return;
    }
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    cout<<"move disk "<< n <<" from "<<from_rod<<" to "<<to_rod<<endl;
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nTower of Hanoi solution for " << n << " disks:\n";
    TowerOfHanoi(n, 'A', 'C', 'B'); // A = source, C = destination, B = auxiliary
    return 0;
}