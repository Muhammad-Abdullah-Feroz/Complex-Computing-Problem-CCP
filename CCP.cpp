#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

double logBase(double a, double b)
{
    return log(a) / log(b);
}

void masterTheorem(int a, int b, double d)
{

    cout << endl
         << "Master Theorem Analysis:" << endl;
    cout << "------------------------" << endl;
    if (a < 1 || b <= 1 || d < 0)
    {
        cout << endl
             << "Invalid Values for a, b, or d" << endl;
        return;
    }
    double log_b_a = logBase(a, b);
    cout << endl
         << "Computed Log Base: log_" << b << "(" << a << ") = " << log_b_a << endl;
    if (abs(log_b_a - d) < 0.0001)
    {
        if (log_b_a == 1)
        {
            cout << endl
                 << "Case 1: T(n) = Theta( n log(n) )" << endl;
        }
        else
        {
            cout << endl
                 << "Case 1: T(n) = Theta( n^" << log_b_a << " log(n) )" << endl;
        }
    }
    else if (d < log_b_a)
    {
        if (log_b_a == 1)
        {
            cout << endl
                 << "Case 2: T(n) = Theta( n )" << endl;
        }
        else
        {
            cout << endl
                 << "Case 2: T(n) = Theta( n ^ " << log_b_a << " )" << endl;
        }
    }
    else if (d > log_b_a)
    {
        if (d == 1)
        {
            cout << endl
                 << "Case 3: T(n) = Theta( n )" << endl;
        }
        else if (d == 0)
        {
            cout << endl
                 << "Case 3: T(n) = Theta( 1 )" << endl;
        }
        else
        {
            cout << endl
                 << "Case 3: T(n) = Theta( n^" << d << " )" << endl;
        }
    }
    else
    {
        cout << endl
             << "Invalid case" << endl;
    }
}

void recurrenceTreeExpansion(int a, int b, double d)
{
    cout << "\nRecurrence Tree Expansion:\n";
    cout << "---------------------------\n";

    int depth = 5; // Number of expansion steps to show
    for (int i = 0; i < depth; i++)
    {
        cout << "T(n) = " << a << "^" << i << " * T(n/" << pow(b, i) << ") + O(n^" << d << ")" << endl;
    }
}

void decreasingSingleRecursion(){
    int a,b,d;
    cout<<endl<<"Decreasing Single Recursion Solver:"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"T(n) = aT(n-b) + O(n^d)"<<endl;
    cout<<"Enter the values of a, b, and d:"<<endl;
    cin>>a>>b>>d;
    if(a<1 || b<1 || d<0){
        cout<<endl<<"Invalid values for a, b, or d."<<endl;
        return;
    }

    cout<<endl<<"Analyzing T(n) = "<<a<<"T(n-"<<b<<") + O(n^"<<d<<")"<<endl;

    if (a==1){
        cout<<endl<<"T(n) = O( n^"<<d+1<<" )"<<endl;
    }else if(a > 1){
        cout<<endl<<"T(n) = O( n^"<<d<<" * "<<a<<"^(n/"<<b<<") )"<<endl;
    }else{
        cout<<endl<<"Invalid case."<<endl;
    }
}

void decreasingDoubleRecursion(){
    // Estimated - Not 100% accurate
    int a1,b1,a2,b2,d;
    cout<<endl<<"Decreasing Double Recursion Solver:"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"T(n) = a1.T(n-b1) + a2.T(n-b2) + O(n^d)"<<endl;
    cout<<"Enter the values of a1, b1, a2, b2, and d:"<<endl;
    cin>>a1>>b1>>a2>>b2>>d;
    if(a1<1 || b1<1 || a2<1 || b2<1 || d<0){
        cout<<endl<<"Invalid values for a1, b1, a2, b2, or d."<<endl;
        return;
    }

    cout << endl << "Analyzing T(n) = " << a1 << "T(n-" << b1 << ") + " << a2 << "T(n-" << b2 << ") + O(n^" << d << ")" << endl;

    if (a1 == 1 && a2 == 1) {
        cout << "=> T(n) = O(n^"<<(d + 1)<<")" << endl;
    } 
    else if (a1 > 1 || a2 > 1) {
        bool r1 = true;
        if (log(a1)/b1 < log(a2)/b2){
            r1 = false;
        }
        if (r1){
            cout << "T(n) = O(n^"<<d<<" * "<<a1<<"^ n/"<<b1<<")" << endl;
        }else{
            cout << "T(n) = O(n^"<<d<<" * "<<a2<<"^ n/"<<b2<<")" << endl;
        }
    }
    // If both a1 and a2 are 1, but d > 0, we still get polynomial complexity
    else {
        cout << "Unexpected case: a1 and a2 must both be >= 1." << endl;
    }

}

void recurrenceTreeSolver(int a, int b, double d)
{
    cout << "\nRecurrence Tree Solver:\n";
    cout << "------------------------\n";

    double log_b_a = logBase(a, b);
}

int main()
{
    cout << "Welcome to the Recurrence Solver!" << endl;
    cout << "=================================" << endl;

    int choice;

    do
    {
        cout << "\nChoose Recurrence Type to Solve:\n";
        cout << "1. Decreasing Recursion\n";
        cout << "2. Dividing Recursion\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Decreasing Recursion Menu
            cout << "\nDecreasing Recursion Options:\n";
            cout << "1. Single\n";
            cout << "2. Double\n";
            cout << "Enter your choice: ";
            int decreasingChoice;
            cin >> decreasingChoice;

            switch (decreasingChoice)
            {
            case 1:
                cout << "Decreasing Recursion - Single selected.\n";
                // Call Single Recursion Solver (implement as needed)
                decreasingSingleRecursion();
                break;
            case 2:
                cout << "Decreasing Recursion - Double selected.\n";
                decreasingDoubleRecursion();
                // Call Double Recursion Solver (implement as needed)
                break;
            default:
                cout << "Invalid choice! Returning to previous menu.\n";
            }
            break;

        case 2:
            // Dividing Recursion Menu
            cout << "\nDividing Recursion Options:\n";
            cout << "1. Single\n";
            cout << "2. Irregular\n";
            cout << "Enter your choice: ";
            int dividingChoice;
            cin >> dividingChoice;

            switch (dividingChoice)
            {
            case 1:
                // Single Division Menu
                cout << "\nSingle Division Options:\n";
                cout << "1. Master Theorem\n";
                cout << "2. Recursion Tree\n";
                cout << "Enter your choice: ";
                int singleDivisionChoice;
                cin >> singleDivisionChoice;

                switch (singleDivisionChoice)
                {
                case 1:
                    cout << "Single Division - Master Theorem selected.\n";
                    // Call Master Theorem Solver (implement as needed)
                    break;
                case 2:
                    cout << "Single Division - Recursion Tree selected.\n";
                    // Call Recursion Tree Solver (implement as needed)
                    break;
                default:
                    cout << "Invalid choice! Returning to previous menu.\n";
                }
                break;
            case 2:
                cout << "Dividing Recursion - Irregular selected.\n";
                // Call Irregular Recursion Solver (implement as needed)
                break;
            default:
                cout << "Invalid choice! Returning to previous menu.\n";
            }
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
