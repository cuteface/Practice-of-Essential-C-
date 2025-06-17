#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<string>

using namespace std;

static set<string> excludeSet = {"a", "an", "or", "the", "and", "but"};

void process_file(map<string, int>& wordmap, const set<string>& excludeSet, ifstream& ifile)
{
    string word;
    while(ifile >> word)
    {
        if (excludeSet.count(word))
        {
            continue;
        }
        wordmap[word]++;
    }
}

void search_word(const map<string, int>& wordmap)
{
    string word;
    cout << "Please input word what you want search";
    if (!cin) {
        cerr << "cin is in bad state!" << endl;
    }

    cin >> word;
    while (word.size() > 0 && word != "q")
    {
        std::map<string,int>::const_iterator it;
        if ((it = wordmap.find(word)) != wordmap.end())
        {
            cout << "This word " << it->first << " occurs " << it->second << " times in file" << endl;
        }
        else
        {
            cout << "This word is not in file" << endl;
        }

        cout << "Another search?(q to quit)\n";
        cin >> word;
    }
}

void display_wordcount(const map<string, int>& wordmap, ofstream& ofile)
{
    map<string, int>::const_iterator it;
    for (it = wordmap.begin(); it != wordmap.end(); ++it)
    {
        ofile << it->first << " occurs " << it->second << " times" << endl;
    }
}

int main()
{
    ifstream ifile("/Users/ykwang/dev/Practice-of-Essential-C-/ch3/output/test.txt");
    ofstream ofile("/Users/ykwang/dev/Practice-of-Essential-C-/ch3/output/test.map");
    if(!ifile || !ofile)
    {
        cerr << "Unable to open file - bailing out!\n";
        return -1;
    }

    map<string, int> wordcount;
    process_file(wordcount, excludeSet, ifile);
    search_word(wordcount);
    display_wordcount(wordcount, ofile);

    return 0;
}