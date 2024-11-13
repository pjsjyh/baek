#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin>>n;
    int t[n+1], p[n+1], sumnum[n+1]={};
    for(int i=0;i<n;i++){
        cin>>t[i]>>p[i];
    }

    for(int i=0;i<n;i++){
        if (i + t[i] <= n) {
            sumnum[i + t[i]] = max(sumnum[i + t[i]], sumnum[i] + p[i]);
        }
        sumnum[i + 1] = max(sumnum[i + 1], sumnum[i]);
    }

    cout<<sumnum[n];
    return 0;
}