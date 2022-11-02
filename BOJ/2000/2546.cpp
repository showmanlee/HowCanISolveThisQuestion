// 경제학과 정원영
// https://www.acmicpc.net/problem/2546

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
		int n, m;
		cin >> n >> m;
		double suma = 0, sumb = 0;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			suma += v[i];
		}
		for (int i = 0; i < m; i++) {
			int p;
			cin >> p;
			sumb += p;
		}
		suma /= n;
		sumb /= m;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (suma > v[i] && sumb < v[i]) {
				res++;
			}
		}
		cout << res << '\n';
	}
}

// C언어와 경제학원론 수업 수강생의 IQ가 주어질 때, C언어 수강생 중 C언어를 드랍해서 두 수업의 평균 IQ를 높일 수 있는 학생의 수는?

// 사람이 빠져서 평균을 올리려면 평균보다 낮은 사람이 빠져야 하고, 들어가서 올리려면 평균보다 높은 사람이 들어가야 한다
// 이를 고려하여 C언어 학생 중 이 조건을 만족하는 사람의 수를 구한다 - 자료형 조심하면서...