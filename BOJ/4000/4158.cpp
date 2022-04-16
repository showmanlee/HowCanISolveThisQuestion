// CD
// https://www.acmicpc.net/problem/4158

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int idxa = 0, idxb = 0, res = 0;
		while (true) {
			if (n <= idxa || m <= idxb) {
				break;
			}
			if (a[idxa] > b[idxb]) {
				idxb++;
			}
			else if (a[idxa] < b[idxb]) {
				idxa++;
			}
			else {
				idxa++;
				idxb++;
				res++;
			}
		}
		cout << res << '\n';
	}
}

// 두 사람이 가지고 있는 cd의 종류가 주어졌을 때, 두 사람이 동시에 가지고 있는 cd의 개수 구하기

// cd 번호 수는 10억까지라 배열로 관리할 수 없음 - map을 활용하면 될 텐데 그것도 시간초과
// 그런데 가만 보면 cd 번호들은 오름차순으로 주어지고 있음 - 따라서 인덱스를 활용해 순서대로 찾아 나아가면 됨
// cd들을 배열로 놓고, 현재 인덱스들의 대소관계에 따라 인덱스를 앞으로 이동시켜준다
// 만약 두 인덱스가 가리키는 값이 같으면 결과값 누적