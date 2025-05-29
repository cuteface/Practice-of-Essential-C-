/*
    1. 询问用户姓名并读取用户输入
    2. 验证用户输入是否合法（大于两个字符即认为合法）
*/

#include <iostream>
using namespace std;

int main()
{
    string name;
    cout << "hi, Please your name." << endl;
    cin >> name;
    if (name.size() < 2)
        cout << "It's invalid value" << endl;

    return 0;
}