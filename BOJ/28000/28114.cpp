// 팀명 정하기
// https://www.acmicpc.net/problem/28114

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<int> v1(3);
	vector<pr> v2(3);
	for (int i = 0; i < 3; i++) {
		cin >> v2[i].first >> v1[i] >> v2[i].second;
		v1[i] %= 100;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), greater<pr>());
	cout << v1[0] << v1[1] << v1[2] << '\n' << v2[0].second[0] << v2[1].second[0] << v2[2].second[0] << '\n';
}

// 세 사람의 BOJ에서 푼 문제 수, 입학연도, 성이 주어질 떄, 입학연두 % 100을 오름차순으로 정렬하여 출력하고, BOJ에서 푼 문제 수가 많은 순서대로 성의 첫 글자 출력하기

// 두 가지 정렬 문제를 하나로 - 3개를 한번에 관리할 필요는 없고, 조건에 따라 2개로 나누어 정렬하여 계산한다