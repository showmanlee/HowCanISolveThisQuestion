// 상품의 주인은?
// https://www.acmicpc.net/problem/24509

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> a(n), b(n), c(n), d(n);
	vector<bool> got(n + 1);
	for (int i = 0; i < n; i++) {
		int p, aa, bb, cc, dd;
		cin >> p >> aa >> bb >> cc >> dd;
		a[i] = {-aa, p};
		b[i] = {-bb, p};
		c[i] = {-cc, p};
		d[i] = {-dd, p};
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());

	cout << a[0].second << ' ';
	got[a[0].second] = true;
	for (int i = 0; i < n; i++) {
		if (!got[b[i].second]) {
			got[b[i].second] = true;
			cout << b[i].second << ' ';
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!got[c[i].second]) {
			got[c[i].second] = true;
			cout << c[i].second << ' ';
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!got[d[i].second]) {
			got[d[i].second] = true;
			cout << d[i].second << '\n';
			break;
		}
	}
}

// 4개의 과목 중 점수가 높은 순서(동률이면 번호 순서)대로 상을 주는데, 같은 사람이 2개 이상의 상을 받지 않도록 배분하는 방법은?

// 각 과목별로 점수 내림차순 -> 번호 오름차순으로 정렬하는 pair 배열을 만들어 정렬한다
// 학생수가 20만 명이지만 그만큼 시간을 넉넉히 주기에 정렬 가능함
// 그렇게 각 배열의 맨 앞부터 받지 않은 학생에게 상을 준다