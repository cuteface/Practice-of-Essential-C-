/*
    1. 接收用户输入多行文字并存入文件
    2. 打开并读取该文件，将文件内容存入vector，并用sort对其排序
    3. 并把排序结果写入新文件
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ifstream in_file("../text/text.txt");
    if (!in_file)
    {
        cerr << "oops! unable to open input file\n";
        return -1;
    }

    string word;
    vector<string> text_vec;
    while(in_file >> word)
    {
        text_vec.push_back(word);
    }

    sort(text_vec.begin(), text_vec.end());

    ofstream out_file("textsort.txt");
    if (!out_file)
    {
        cerr << "oops! unable to open output file\n";
    }
    for (auto linetext : text_vec)
    {
        out_file << linetext << endl;
    }

    return 0;
}