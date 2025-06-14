#include <iostream>
#include <vector>
using namespace std;

inline bool check_pos_valid(int pos)
{
    return (pos <= 0 || pos > 64) ? false : true;
}

const vector<int>* pentagonal_series(int pos)
{
    static vector<int> elems;
    if (check_pos_valid(pos) && pos > elems.size()) // lazy caculate
    {
        for(int i = elems.size()+1; i <= pos; ++i)
        {
            elems.push_back((i * (3*i - 1)) / 2);
        }
    }

    return &elems;
}

bool pentagonal_elem(int pos, int& elem)
{
    if (!check_pos_valid(pos))
    {
        cout << "Sorry, invalid pos!" << endl;
        elem = 0;
        return false;
    }

    const vector<int>* v = pentagonal_series(pos);
    elem = (*v)[pos-1];
    return true;
}

int main()
{
    int elem;
    if (pentagonal_elem(8, elem))
        cout << "element 8 is: " << elem << endl;
    if (pentagonal_elem(18, elem))
        cout << "element 18 is: " << elem << endl;
    if (pentagonal_elem(88, elem))
        cout << "element 88 is: " << elem << endl;
    
    return 0;
}