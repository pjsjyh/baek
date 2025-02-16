#include <iostream>
using namespace std;
int n;
pair<char, char> arr[26]; // 트리를 저장하는 배열

void preorder(char x) {
	if (x != '.') {
		cout << x;
		preorder(arr[x - 'A'].first);
		preorder(arr[x - 'A'].second);
	}
}

void inorder(char x) {
	if (x != '.') {
		inorder(arr[x - 'A'].first);
		cout << x;
		inorder(arr[x - 'A'].second);
	}
}

void postorder(char x) {
	if (x != '.') {
		postorder(arr[x - 'A'].first);
		postorder(arr[x - 'A'].second);
		cout << x;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		arr[a - 'A'] = {b, c}; // 올바르게 입력 저장
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;

	return 0;
}
