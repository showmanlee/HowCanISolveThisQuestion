// 햄버거 분배
// https://www.acmicpc.net/problem/19941

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (j < 0 || j >= n) {
					continue;
				}
				if (s[j] == 'H') {
					s[j] = ' ';
					res++;
					break;
				}
			}
		}
	}
	cout << res << '\n';
}

// 길이가 n인 일렬로 이어진 식탁에 자라마다 사람 또는 햄버거가 있고, 각 사람은 좌우로 k 거리 안에 있는 햄버거 하나를 먹을 수 있을 때, 햄버거를 먹을 수 있는 사람의 최대 수는?

// 그리디 - 순서대로 돌면서 손에 닿는 거리에서 가장 먼저 보이는 햄버거를 집는다
// 식탁 상태를 문자열로 받고, 왼쪽부터 돌면서 사람 칸이라면 해당 칸에서 -k~k 사이를 돌며 먼저 만난 햄버거를 지운다