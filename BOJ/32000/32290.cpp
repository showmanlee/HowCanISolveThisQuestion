// MEX vs OR
// https://www.acmicpc.net/problem/32290	

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, r, x;
	cin >> l >> r >> x;
	vector<int> v;
	for (int i = l; i <= r; i++) {
		int p = i | x;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	if (v[0] != 0) {
		cout << 0 << '\n';
	} else {
		int res = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != res) {
				break;
			}
			res++;
		}
		cout << res << '\n';
	}
}

// l에서 r을 x와 OR 연산한 결과들로 구성된 배열에 포함되지 않은 가장 작은 음이 아닌 정수 구하기