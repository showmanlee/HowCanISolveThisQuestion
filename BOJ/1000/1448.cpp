// 삼각형 만들기
// https://www.acmicpc.net/problem/1448

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int res = -1;
	for (int i = 0; i < n - 2; i++) {
		if (v[i] < v[i + 1] + v[i + 2]) {
			res = v[i] + v[i + 1] + v[i + 2];
			break;
		}
	}
	cout << res << '\n';
}

// 길이가 다른 n개의 막대기 중 3개를 뽑아 삼각형을 만들 때 얻을 수 있는 가장 긴 삼각형 둘레의 길이 구하기

// 그리디 원리 - 내림차순으로 정렬한 후 맞닿은 3개의 막대를 선택해야 함
// 이에 따라 정렬한 후 맞닿은 3개의 막대기로 삼각형을 만들 수 있는 경우 해당 삼각형의 둘레를 결과로 하고, 아니면 계속 내려간다