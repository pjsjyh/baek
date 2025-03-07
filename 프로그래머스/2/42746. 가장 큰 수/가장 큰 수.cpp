#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a + b > b + a; 
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> list;
    for (int num : numbers) {
        list.push_back(to_string(num));
    }
     sort(list.begin(), list.end(), compare);
    if (list[0] == "0") return "0";

    for (string num : list) {
        answer += num;
    }
    return answer;
}