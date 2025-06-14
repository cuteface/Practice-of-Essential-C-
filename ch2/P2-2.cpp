#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool getPentagonalArray(int size, vector<int>& array)
{
    if (size <=0 || size >= 64)
    {
        cerr << "Sorry. Invalid position!" << endl;
        return false;
    }

    int val = 0;
    for (int i = array.size() + 1; i <= size; ++i)
    {
        val = i * (3 * i - 1) / 2;
        array.push_back(val);
    }
    return true;
}

void displayItems(vector<int>& array, const string title, ostream& os = cout)
{
    os << '\n' << title << "\n\t";
    for (int ix = 0; ix < array.size(); ++ix)
    {
        os << array[ix] << ' ';
    }
    os << endl;
}

int main()
{
    vector<int> pent;
    const string title("Pentagonal Numeric Series");
    if (getPentagonalArray(0, pent))
        displayItems(pent, title);

    if (getPentagonalArray(8, pent))
        displayItems(pent, title);

    return 0;
}