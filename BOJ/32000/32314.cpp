// Christmas Tree Adapter
// https://www.acmicpc.net/problem/32314

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, w, v;
	cin >> a >> w >> v;
	cout << (w >= a * v) << '\n';
}

// 주어진 a, w, v가 w >= a * v를 만죽하는지 구하기