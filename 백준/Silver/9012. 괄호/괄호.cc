#include<iostream>
#include<queue>
#include <stack>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k = 0;
		stack<char> s;
		bool ok = false;
		string ne;
		cin >> ne;
		while (ne[k] == ')'|| ne[k]=='(') {
			if (ne[k] == '(') {
				s.push('(');
			}
			else if (ne[k] == ')') {
				if (s.empty())
					ok = true;
				else {
					s.pop();
				}
			}
			k++;
		}
		if (ok || s.empty()==false)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		
	}
}