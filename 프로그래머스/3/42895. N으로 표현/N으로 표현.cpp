#include <string>
#include <vector>
#include <set>
using namespace std;
vector<set<int>> dp;
char ops[4] = {'+',  '*','-', '/'};
int solution(int N, int number) {
    int answer =0;
    dp.resize(9);
    dp[0].insert(N);
    int i=1;
    if(N==number) return 1;
     for (int i = 1; i <= 8; i++) {
    dp[i].insert(stoi(string(i, '0' + N)));

    for (int j = 1; j < i; j++) {
        for (int a : dp[j]) {
            for (int b : dp[i - j]) {
                for (int k = 0; k < 4; k++) {
                    switch (ops[k]) {
                        case '+': dp[i].insert(a + b); break;
                        case '-': dp[i].insert(a - b); break;
                        case '*': dp[i].insert(a * b); break;
                        case '/': if (b != 0) dp[i].insert(a / b); break;
                    }
                }
            }
        }
    }

    if (dp[i].count(number)) {
        return i;
    }
}
    answer = -1;
    return answer;
}