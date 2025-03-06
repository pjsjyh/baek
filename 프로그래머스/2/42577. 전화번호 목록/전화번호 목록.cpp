#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int phonesize = phone_book.size();
    unordered_set<string> hashSet;
    for(auto a:phone_book){
        hashSet.insert(a);
    }
    for (const string& phone : phone_book) {
        string prefix = "";
        for (char ch : phone) {
            prefix += ch;
            if (prefix != phone && hashSet.find(prefix) != hashSet.end()) {
                return false; 
            }
        }
    }
    
    return answer;
}