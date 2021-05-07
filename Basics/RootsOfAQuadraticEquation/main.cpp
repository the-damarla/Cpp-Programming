#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a,b,c;
    cout << "Enter x^2 term " ; cin >> a;
    cout << "Enter x^2 term " ; cin >> b;
    cout << "Enter x^2 term " ; cin >> c;
    float disc;
    disc = (b * b) - (4 * a * c);
    cout << "Discriminant is : " << disc <<endl;
    float root1,root2;
    if(disc > 0)
    {
        root1 = ((-b) + sqrt(b*b - (4 * a * c)))/(2 * a);
        root2 = ((-b) - sqrt(b*b - (4 * a * c)))/(2 * a);
    }
    else if(disc == 0)
    {
        root1 = -b / (2 * a);
        root2 = -b / (2 * a);
    }
    else
    {
        float real = -b / (2 * a);
        float img = sqrt((-disc)/(2 * a));
        cout << "Root1 = " << real <<"+" << img << "i" <<endl;
        cout << "Root1 = " << real << "-" << img << "i" << endl;
        return 0;
    }
    cout << root1 << "\n";
    cout << root2;
    return 0;
}
