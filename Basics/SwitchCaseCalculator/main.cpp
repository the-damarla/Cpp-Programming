#include <iostream>

using namespace std;

int main()
{
    cout << "Enter 1 to addition\n2 to Subtraction\n3 to Multiplication\n4 to Division\n5 to Exit the Calculator";
    int x;
    int y,z;
    while(1)
    {
        cout << "\nEnter ur choice : ";
        cin >> x;
        switch(x)
        {
            case 1:
                cout << "Enter two values : ";
                cin >> y >> z;
                cout << "Addition is : " << y + z;
                break;
            case 2:
                cout << "Enter two values : ";
                cin >> y >> z;
                cout << "Subtraction is : " << y - z;
                break;
            case 3:
                cout << "Enter two values : ";
                cin >> y >> z;
                cout << "multiplication is : " << y * z;
                break;
            case 4:
                cout << "Enter two values : ";
                cin >> y >> z;
                cout << "Division is : "<< y / z;
                break;
            case 5:
                exit(0);
            default:
                cout << "Enter a valid choice";
        }
    }
    return 0;
}
