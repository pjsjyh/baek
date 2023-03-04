#include<iostream>
#include<queue>
#include <stack>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<int> s;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string inn;
		cin >> inn;
		if (inn == "push") {

			int num;
			cin >> num;

			s.push(num);
		}
		else if (inn == "top") {
			if (s.empty())
				cout << "-1" << endl;
			else
				cout << s.top() << endl;
		}
		else if (inn == "size") {
			cout << s.size()<<endl;
		}
		else if (inn == "pop") {
			if (s.empty())
				cout << "-1" << endl;
			else {
				int a = s.top();
				cout << a << endl;
				s.pop();

			}
		}
		else if (inn == "empty") {
			if (s.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
	}
}