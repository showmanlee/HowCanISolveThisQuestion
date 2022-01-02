// 최소, 최대
// https://www.acmicpc.net/problem/10818

#include <iostream>
using namespace std;

int main(void) {
	int n, min = 1000001, max = -1000001;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a < min)
			min = a;
		if (a > max)
			max = a;
	}
	cout << min << ' ' << max << endl;
}