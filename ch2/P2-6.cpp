#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

template<typename elemType>
elemType max(const vector<elemType>& v)
{
    return *max_element(v.begin(), v.end());
}

template<typename elemType>
elemType max(const elemType* parray, int size)
{
    return *max_element(parray, parray + size);
}

int main()
{
    // test code
    return 0;
}