#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> vec;
void dfs(int n, int k){
     int sum = 0;
     while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, k); // 각 자리의 P제곱 합
        n /= 10;
    }
     auto it = find(vec.begin(), vec.end(), sum);
    if(it != vec.end()){
        cout<<distance(vec.begin(), it);
    }
    else{
        vec.push_back(sum);
        dfs(sum,k);
    }
}
int main() {
    int n,k;
    cin>>n>>k;
    vec.push_back(n);
    dfs(n,k);
    return 0;
}