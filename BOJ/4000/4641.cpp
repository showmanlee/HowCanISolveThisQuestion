// Doubles
// https://www.acmicpc.net/problem/4641

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		vector<int> v;
		bool end = false;
		while (true) {
			int p;
			cin >> p;
			if (p == 0) {
				int res = 0;
				for (int i : v) {
					for (int j : v) {
						if (i * 2 == j) {
							res++;
						}
					}
				}
				cout << res << '\n';
				break;
			}
			else if (p == -1) {
				end = true;
				break;
			}
			v.push_back(p);
		}
		if (end) {
			break;
		}
	}
}

// 주어진 자연수 리스트에서 어떤 수가 다른 자연수의 두 배인 관계 개수 구하기

// 리스트를 n^2로 순회하며 찾기 - 찾아지는 건 단 한번
// 리스트 최대 크기가 15까지이므로 쉽게 접근 가능