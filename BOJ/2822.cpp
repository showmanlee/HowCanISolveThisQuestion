// 점수 계산
// https://www.acmicpc.net/problem/2822

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	vector<pr> v(8);
	for (int i = 1; i <= 8; i++) {
		int n;
		cin >> n;
		v[i - 1] = { n, i };
	}
	sort(v.begin(), v.end());
	int sum = 0;
	vector<int> res;
	for (int i = 7; i >= 3; i--) {
		sum += v[i].first;
		res.push_back(v[i].second);
	}
	sort(res.begin(), res.end());
	cout << sum << '\n';
	for (int i = 0; i < 5; i++)
		cout << res[i] << ' ';
	cout << '\n';
}

// 점수 8개 중 상위 5개의 합과 그 문제 번호들 출력하기
// pair로 점수와 번호 모두 기억하여 정렬, 이후 번호만 따로 따서 다시 정렬...