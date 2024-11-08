#include <iostream>

using namespace std;

int main() {
    int num;
    cin>>num;

    int n[10];
        n[0] = 1;
        n[1] = 2;
        n[2] = 4;

        for(int i=3;i<11;i++){
            n[i] = n[i-3]+n[i-2]+n[i-1];
        }
    for(int i=0;i<num;i++){
        int k;
        cin>>k;

        cout<<n[k-1]<<endl;
        
    }
    return 0;
}