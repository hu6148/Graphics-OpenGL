#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "Enter the number of layer: ";
	cin >> n;
	//ù��° �� �� ���
	for (int i = 1; i <= n; i++) {
		cout << "*";
		if (i == n) break;
		cout << " ";
	}
	cout << endl;

	//2��° �ٺ����� ���
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << " ";
		}
		cout << "*";
		if (i == n - 1) break;
		for (int k = n * 2 - i * 2 - 3; k > 0; k--) {
			cout << " ";
		}
		cout << "*" << endl;
	}


	return 0;
}