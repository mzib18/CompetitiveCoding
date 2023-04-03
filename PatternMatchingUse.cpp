#include<iostream>
#include "PatternMatching.cpp"
using namespace std;
int main() {
    SuffixTrie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}
