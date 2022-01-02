// 가장 쉬운 문제를 찾는 문제
// https://www.acmicpc.net/problem/22966

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int resn = 987654321;
	string ress;
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		if (p < resn) {
			resn = p;
			ress = s;
		}
	}
	cout << ress << '\n';
}

// 사전 순으로 정렬된 문제 이름과 난이도가 주어졌을 때, 그 중 가장 난이도가 낮은 문제 찾기

// 문제를 입력 받으며 현재까지 가장 낮은 난이도였다면 최소 난이도를 갱신하면서 그 이름도 결과값에 갱신해두기
// 그래서 문제 이름 출력하기