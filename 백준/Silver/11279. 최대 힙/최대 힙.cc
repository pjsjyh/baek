#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
     ios::sync_with_stdio(false);
	int num;
	cin >> num;
	priority_queue<int> q;
	vector<int> li;
	for (int i = 0; i < num; i++) {
		int k;
		cin >> k;
		if (k == 0) {
			if (q.empty())
				li.push_back(0);
			else {
				li.push_back(q.top());
				q.pop();
			}
			
		}
		else {
			q.push(k);
		}
	}
	for (vector<int>::iterator i=li.begin(); i != li.end(); ++i) {
		cout << *i << '\n';
	}
}