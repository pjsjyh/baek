#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];  // 배열의 첫 번째 요소를 가장 큰 수로 초기화

    for (int i = 1; i < size; i++) {  // 두 번째 요소부터 마지막 요소까지 순차적으로 확인
        if (arr[i] > max) {
            max = arr[i];  // 더 큰 값이 나오면 max 값을 갱신
        }
    }

    return max;  // 가장 큰 값을 반환
}

int main() {
    int v;
    cin>>v;

    int num[v];
    int checknum[v] = {};
    for(int i=0;i<v;i++){
        cin>>num[i];
    }
    for(int i=v-1;i>=0;i--){
        int bignum=0;
        for(int j=v-1;j>i;j--){
            if(num[i]>num[j]){
                if(bignum<checknum[j]){
                    checknum[i] = checknum[j];
                    bignum = checknum[j];
                }
            }
        }
        checknum[i] +=1;
    }
    cout<<findMax(checknum, v);
}