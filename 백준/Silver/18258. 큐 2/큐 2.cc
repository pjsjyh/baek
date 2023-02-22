#include <iostream>
#include <queue>
using namespace std;


int n,num;
queue<int> q;
string s;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (s == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';

		}
		else if (s == "size")
		{
			cout << q.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (s == "front")
		{
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		else // s == "back"
		{
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
	}
}