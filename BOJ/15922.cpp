// 아우으 우아으이야!!
// https://www.acmicpc.net/problem/15922

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	int min = -2000000000, max = -20000000000, length = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (length == -1) {
			min = x;
			max = y;
			length = 0;
		}
		else {
			if (x > max) {
				length += max - min;
				min = x;
				max = y;
			}
			else if (y > max) {
				max = y;
			}
		}
	}
	length += max - min;
	cout << length << endl;
}