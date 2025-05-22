#include<iostream>
using namespace std;
struct Expense{
    string expensename;
    int amount;
    Expense* next;
    Expense(string e,int a){
        expensename=e;
        amount=a;
        next=NULL;
    }
};

struct Month{
    string monthname;
    Month* next;
    Expense* expensehead;
    Month(string m){
        monthname=m;
        next=NULL;
        expensehead=NULL;
    }
};

void addmonth(Month*& head,string monthname){
    Month *newmonth=new Month(monthname);
    newmonth->next=head;
    head=newmonth;
}

void addexpense(Month* head, string monthname, string expensename, int amount ){
    Month* temp=head;
    while(temp && temp->monthname!=monthname){
        temp=temp->next;
    }
    if(!temp){
        cout<<"Month "<<monthname<<"not found "<<endl;
        return;
    }
    Expense  *newexpense=new Expense(expensename , amount);
    newexpense->next=temp->expensehead;
    temp->expensehead=newexpense;
}

void displayAllExpenses(Month *head){
    Month* currentmonth=head;
    while(currentmonth){
        cout<<"Month "<<currentmonth->monthname<<endl;
        Expense *currentexpense=currentmonth->expensehead;
        while(currentexpense){
            cout<<"Name of expense: "<<currentexpense->expensename<<"Amount Rs: "<<currentexpense->amount<<endl;
            currentexpense=currentexpense->next;
        }
        currentmonth=currentmonth->next;
    }

}

void MaxExpense(Month* head, string monthname ){
    Month* temp=head;
    while(temp && temp->monthname!=monthname){
        temp=temp->next;
    }
    if(!temp){
        cout<<"month "<<monthname <<"not found "<<endl;
        return;
    }
    Expense* maxexpense=NULL;
    Expense* currentexpense=temp->expensehead;
    while(currentexpense){
        if(!maxexpense || currentexpense->amount>maxexpense->amount){
            maxexpense=currentexpense;
        }
        currentexpense=currentexpense->next;
    }
    if(maxexpense){
        cout<<"most expensive item in the month "<<temp->monthname<<"is "<<maxexpense->expensename<<"Rs: "<<maxexpense->amount<<endl;
    }
    else
    cout<<"no expenses recorded for the month "<<temp->monthname<<endl;
}

void updateExpense(Month* head, string monthname,  string expensename, int newamount) {
    Month* temp = head;
    while (temp &&temp ->monthname != monthname) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Month " << monthname << " not found "<<endl;
        return;
    }

    Expense* currentexpense = temp->expensehead;
    while (currentexpense && currentexpense->expensename != expensename) {
        currentexpense = currentexpense->next;
    }
    if (!currentexpense) {
        cout << "Expense '" << expensename << " not found in " << monthname << endl;
        return;
    }

    currentexpense->amount = newamount;
    cout << "Expense " << expensename << " updated to Rs" << newamount << " in " << monthname << ".\n";
}
int main(){
    Month* head=NULL;
    addmonth(head,"June");
    addmonth(head,"July");

addexpense(head, "June", "Notes",1000);
addexpense(head, "June", "Travel ",5000);
addexpense(head, "June", "Groceries ",6000);
addexpense(head, "June", "Utilities ", 10000);
addexpense(head,"July", "Notes ", 1200);

displayAllExpenses(head);

MaxExpense(head,"June");

updateExpense(head, "June", "Notes", 1300);
}