#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

float max(float a, float b)
{
    return a > b ? a : b;
}

string max(string a, string b)
{
    return a > b ? a : b;
}

int max(const vector<int>& v)
{
    return *max_element(v.begin(), v.end());
}

string max(const vector<string>& v)
{
    return *max_element(v.begin(), v.end());
}

int max(const int* parray, int size)
{
    return *max_element(parray, parray + size);
}

int main()
{
    // test code
    return 0;
}