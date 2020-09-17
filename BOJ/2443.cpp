// 별 찍기 - 6
// https://www.acmicpc.net/problem/2443

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = n; i > 0; i--) {
		for (int j = n - i; j > 0; j--)
			cout << ' ';
		for (int j = 0; j < (i-1) * 2 + 1; j++)
			cout << '*';
		cout << endl;
	}
}