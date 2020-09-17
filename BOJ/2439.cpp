// 별 찍기 - 2
// https://www.acmicpc.net/problem/2439

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j > 0; j--)
			cout << ' ';
		for (int j = 0; j < i; j++)
			cout << '*';
		cout << endl;
	}
}