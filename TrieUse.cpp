#include<iostream>
using namespace std;
#include "Trie.h"

int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout<<t.searchWord("and")<<endl;
    t.removeWord("and");
    cout<<t.searchWord("and")<<endl;
}
