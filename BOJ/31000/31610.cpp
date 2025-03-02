// 飴の袋詰め (Drops Packing)
// https://www.acmicpc.net/problem/31610

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	cout << (a * b + c) << '\n';
}

// a * b + c 구하기