#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the character : ";
    char x; cin >> x;
    if(isalpha(x))
    {
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        {
            cout << "Vowel" << endl;
            return 0;
        }
    cout << "Consonant" << endl;
    }
    cout << "You Entered a Number " << endl;
    return 0;
}
