#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int len;
    cin>>len;
    vector<pair<int,int>> vec;
    vec.resize(len);
    for(int i=0;i<len;i++) cin>>vec[i].first>>vec[i].second;
    sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.second==b.second)
            return a.first<b.first;
        return a.second < b.second;
    });
    int count = 0;
    int currentEnd = 0;

    for (auto& meeting : vec) {
        if (meeting.first >= currentEnd) {
            count++;
            currentEnd = meeting.second;
        }
    }

    cout << count << endl;
    return 0;
}