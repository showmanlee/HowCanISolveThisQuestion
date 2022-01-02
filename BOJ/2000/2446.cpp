// 별 찍기 - 9
// https://www.acmicpc.net/problem/2446

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n - 1; j++)
			cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++)
			cout << '*';
		cout << endl;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n - 1; j++)
			cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++)
			cout << '*';
		cout << endl;
	}
}