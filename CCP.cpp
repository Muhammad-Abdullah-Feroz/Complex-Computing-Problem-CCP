#include<iostream>
#include<conio.h>
#include<cmath>

using namespace std;

double logBase(double a, double b){
    return log(a)/log(b);
}

void masterTheorem(int a, int b, double d){

    cout<<endl<<"Master Theorem Analysis:"<<endl;
    cout<<"------------------------"<<endl;
    if (a < 1 || b <= 1 || d < 0){
        cout<<endl<<"Invalid Values for a, b, or d"<<endl;
        return;
    }
    double log_b_a = logBase(a, b);
    cout<<endl<<"Computed Log Base: log_"<<b<<"("<<a<<") = "<<log_b_a<<endl;
    if (abs(log_b_a - d) < 0.0001){
        if(log_b_a == 1){
            cout<<endl<<"Case 1: T(n) = Theta( n log(n) )"<<endl;
        }
        else{
            cout<<endl<<"Case 1: T(n) = Theta( n^"<<log_b_a <<" log(n) )"<<endl;
        }
    }
    else if (d < log_b_a){
        if(log_b_a == 1){
            cout<<endl<<"Case 2: T(n) = Theta( n )"<<endl;
        }
        else{
            cout<<endl<<"Case 2: T(n) = Theta( n ^ "<<log_b_a<<" )"<<endl;
        }
    }
    else if (d > log_b_a){
        if(d == 1){
            cout<<endl<<"Case 3: T(n) = Theta( n )"<<endl;
        }else if (d == 0){
            cout<<endl<<"Case 3: T(n) = Theta( 1 )"<<endl;
        }else{
            cout<<endl<<"Case 3: T(n) = Theta( n^"<<d<<" )"<<endl;
        }
    }
    else{
        cout<<endl<<"Invalid case"<<endl;
    }
}

void recurrenceTreeExpansion(int a, int b, double d) {
    cout << "\nRecurrence Tree Expansion:\n";
    cout << "---------------------------\n";

    int depth = 5; // Number of expansion steps to show
    for (int i = 0; i < depth; i++) {
        cout << "T(n) = " << a << "^" << i << " * T(n/" << pow(b, i) << ") + O(n^" << d << ")" << endl;
    }
}

int main(){
    int a, b;
    double d;
    cout<<"Enter the values of a, b, and d: ";
    cin>>a>>b>>d;
    cout<<endl<<"You entered: a = "<<a<<", b = "<<b<<", d = "<<d<<endl;
    cout<<"------------------------"<<endl;
    recurrenceTreeExpansion(a, b, d);
    masterTheorem(a, b, d);
    cout<<endl<<"Press any key to exit..."<<endl;
    getch();
    return 0;
}
