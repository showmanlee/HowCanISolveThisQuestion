// 에르다 노바와 오리진 스킬
// https://www.acmicpc.net/problem/29791

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n), w(m);
	int resn = 0, cntn = 0, resm = 0, cntm = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	for (int i : v) {
		if (i >= cntn) {
			resn++;
			cntn = i + 100;
		}
	}
	for (int i : w) {
		if (i >= cntm) {
			resm++;
			cntm = i + 360;
		}
	}
	cout << resn << ' ' << resm << '\n';
}

// 100초 쿨타임과 360초 쿨타임 스킬 버튼을 누른 타이밍이 주어질 때, 스킬이 들어간 횟수 구하기