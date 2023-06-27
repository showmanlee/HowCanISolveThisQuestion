// Good Coin Denomination
// https://www.acmicpc.net/problem/26350

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		bool res = true;
		for (int i = 1; i < n; i++) {
			if (v[i] < v[i - 1] * 2) {
				res = false;
				break;
			}
		}
		cout << "Denominations:";
		for (int i = 0; i < n; i++) {
			cout << " " << v[i];
		}
		cout << "\n" << (res ? "Good" : "Bad") << " coin denominations!\n";
		if (t < tt - 1) {
			cout << '\n';
		}
	}
}

// 동전 액면가가 오름차순으로 주어질 떄, 각각의 액면가 차이가 2배 이상 차이나는지 출력하기

// 배열 순회하면서 서로 맞붙은 값 차이가 이전 값 2배 이상인지 확인하기