// 엘프의 검
// https://www.acmicpc.net/problem/4436

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	long long n;
	while (cin >> n) {
		vector<bool> v(10);
		int cnt = 0;
		long long p = 0;
		while (cnt < 10) {
			p++;
			long long t = n * p;
			while (t > 0) {
				long long d = t % 10;
				if (!v[d]) {
					v[d] = true;
					cnt++;
				}
				t /= 10;
			}
		}
		cout << p << '\n';
	}
}

// n부터 n씩 더하는 등차수열에서 모든 숫자를 등장식키기 위해 필요한 최소 길이는?

// 브루트포스로 구해봅니다