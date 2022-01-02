// 별 찍기 - 7
// https://www.acmicpc.net/problem/2444

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n - i - 1; j > 0; j--)
			cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++)
			cout << '*';
		cout << endl;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 0; j < (n - i - 1) * 2 + 1; j++)
			cout << '*';
		cout << endl;
	}
}