// HEPC1
// https://www.acmicpc.net/problem/33898

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<char> v(4);
	cin >> v[0] >> v[1] >> v[3] >> v[2];
	bool res = false;
	for (int i = 0; i < 4; i++) {
		if (v[(0 + i) % 4] == 'H' && v[(1 + i) % 4] == 'E' && v[(2 + i) % 4] == 'P' && v[(3 + i) % 4] == 'C') {
			res = true;
			break;
		}
		if (v[(0 + i) % 4] == 'C' && v[(1 + i) % 4] == 'P' && v[(2 + i) % 4] == 'E' && v[(3 + i) % 4] == 'H') {
			res = true;
			break;
		}
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 2*2로 배치된 문자를 시계방향이나 반시계방향으로 읽었을 때 HEPC가 나오는지 구하기