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
        cout << "1. Linear Recursion\n";
        cout << "2. Dividing Recursion\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Linear Recursion Menu
            cout << "\nLinear Recursion Options:\n";
            cout << "1. Single\n";
            cout << "2. Double\n";
            cout << "Enter your choice: ";
            int linearChoice;
            cin >> linearChoice;

            switch (linearChoice)
            {
            case 1:
                cout << "Linear Recursion - Single selected.\n";
                // Call Single Recursion Solver (implement as needed)
                break;
            case 2:
                cout << "Linear Recursion - Double selected.\n";
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
