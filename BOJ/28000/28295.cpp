// 체육은 코딩과목 입니다
// https://www.acmicpc.net/problem/28295

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s = "NESW";
	int d = 0;
	for (int i = 0; i < 10; i++) {
		int p;
		cin >> p;
		d = (d + p) % 4;
	}
	cout << s[d] << '\n';
}

// 북쪽을 보고 있는 상태에서 우측으로 90도, 180도, 270도 회전 명령이 10개 주어질 때, 최종적으로 보고 있는 방향 구하기

// 직접 돌려보면서 구해봅니다