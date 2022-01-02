// 試験 (Exam)
// https://www.acmicpc.net/problem/18411

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	cout << (v[1] + v[2]) << '\n';
}

// 3개의 점수 중 가장 낮은 점수 하나를 뺀 두 개의 점수 합 구하기

// 원하는 방법으로 구하면 됩니다 - 어떤 방식이든 그리 복잡하지 않으니