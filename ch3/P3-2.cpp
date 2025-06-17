#include <iostream>
#include <algorithm>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class short_than
{
public:
    bool operator()(const string& ls, const string& rs)
    {
        return ls.size() < rs.size();
    }
};

template<typename elemType>
void display_item(const vector<elemType>& vec, ostream& os=std::cout, int len = 8)
{
    typename vector<elemType>::const_iterator iter = vec.begin();
    typename vector<elemType>::const_iterator end_iter = vec.end();
    int elem_cnt = 1;
    while(iter != end_iter)
    {
        os << *iter++ << (!(elem_cnt ++ % len) ? '\n' : ' ');
    }
    os << endl;
}

int main()
{
    ifstream ifile("/Users/ykwang/dev/Practice-of-Essential-C-/ch3/output/test.txt");
    ofstream ofile("/Users/ykwang/dev/Practice-of-Essential-C-/ch3/output/sorttext.txt");
    if(!ifile || !ofile)
    {
        cerr << "Unable to open file - bailing out!\n";
        return -1;
    }

    vector<string> texts;
    string word;
    while(ifile >> word)
    {
        texts.push_back(word);
    }

    std::sort(texts.begin(), texts.end(), short_than());
    display_item(texts, ofile);
}