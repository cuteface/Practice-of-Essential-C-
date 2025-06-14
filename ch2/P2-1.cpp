#include <iostream>
using namespace std;

bool fibon_elem(int pos, int& elem)
{
    if (pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }

    int n1 = 1, n2 = 1;
    elem = 1;
    for (int i = 3; i <= pos; ++i)
    {
        elem = n1 + n2;
        n1 = n2;
        n2= elem;
    }
    return true;
}

int main()
{
    int pos, elem;
    char ch;
    bool domore = true;
    while (domore)
    {
        cout << "Please enter position: ";
        cin >> pos;
        if (fibon_elem(pos, elem))
        {
            cout << "element # " << pos << " is " << elem << endl;
        }
        else
        {
            cout << "Sorry, could not calculate element # " << pos << endl;
        }

        cout << "Would you like continue? Input y or n.";
        cin >> ch;
        if (ch == 'y')
            domore = true;
        else if (ch == 'n')
            domore = false;
    }
    return 0;
}