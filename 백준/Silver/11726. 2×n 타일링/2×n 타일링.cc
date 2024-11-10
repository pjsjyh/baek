#include <iostream>
using namespace std;

int main() {
    int v;
    cin>>v;

    int num[10001];

    num[1] = 1;
    num[2] = 2;
    for(int i=3;i<=v;i++){
        num[i] = (num[i-1] + num[i-2])%10007; 
    }
    cout<<num[v];
    return 0;
}