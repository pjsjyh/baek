#include <iostream>
#include <string>
using namespace std;

using u128 = __uint128_t;

// u128을 문자열로 바꿔서 출력
string u128_to_string(u128 value) {
    if (value == 0) return "0";
    string result;
    while (value > 0) {
        result = char('0' + value % 10) + result;
        value /= 10;
    }
    return result;
}

u128 combination(int n, int m) {
    u128 res = 1;
    for (int i = 1; i <= m; ++i) {
        res *= (u128)(n - i + 1);
        res /= i;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (m > n - m) m = n - m; 

    u128 result = combination(n, m);
    cout << u128_to_string(result) << '\n';
    return 0;
}
