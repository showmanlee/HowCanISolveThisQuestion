// Yalda
// https://www.acmicpc.net/problem/33191

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if (n >= a) {
		cout << "Watermelon";
	} else if (n >= b) {
		cout << "Pomegranates";
	} else if (n >= c) {
		cout << "Nuts";
	} else {
		cout << "Nothing";
	}
	cout << '\n';
}

// 우선순위에 따라 주어진 예산으로 살 수 있는 물건 구하기