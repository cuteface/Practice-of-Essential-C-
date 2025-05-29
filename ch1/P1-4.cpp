/*
    1. 提示用户同时输入名字和姓氏
    2. 同时打印姓氏和名字
*/

#include<iostream>
using namespace std;

int main()
{
    string user_first_name, user_last_name;
    cout << "Please input your last name:" << endl;
    cin >> user_last_name;

    cout << "Please input your first name:" << endl;
    cin >> user_first_name;

    cout << "user name is: " << user_first_name << " " << user_last_name << endl;
    return 0;
}