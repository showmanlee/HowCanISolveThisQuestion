// A+B - 5
// https://www.acmicpc.net/problem/10952

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int a, b;
	vector<int> v;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		v.push_back(a + b);
	}
	for (auto p = v.begin(); p != v.end(); p++)
		cout << *p << endl;
}