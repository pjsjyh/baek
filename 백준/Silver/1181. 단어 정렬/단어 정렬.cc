#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const string &a, const string &b) {
    if (a.length() == b.length()) return a < b; 
    return a.length() < b.length(); 
}
int main() {
    int n;
    cin>>n;
    char list[n];
    set<string> charlist;
     vector<string> words; 
    for(int i=0;i<n;i++){
        string ab;
        cin>>ab;
        charlist.insert(ab);
    }
     words.assign(charlist.begin(), charlist.end());
    sort(words.begin(), words.end(), compare);

     for (const string &word : words) {
        cout << word << '\n';
    }
    
    return 0;
}