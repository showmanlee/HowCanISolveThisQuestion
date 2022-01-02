// 팬케익 뒤집기
// https://www.acmicpc.net/problem/2759

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
		int n;
		cin >> n;
		vector<int> pans(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> pans[i];
		vector<int> res;
		int idx = n;
		while (idx != 1) {
			int d = 0;
			for (int i = 1; i <= n; i++) {
				if (pans[i] == idx) {
					d = i;
					break;
				}
			}
			if (idx == d) {
				idx--;
				continue;
			}
			if (d != 1) {
				reverse(pans.begin() + 1, pans.begin() + d + 1);
				res.push_back(d);
			}
			reverse(pans.begin() + 1, pans.begin() + idx + 1);
			res.push_back(idx);
			idx--;
		}
		cout << res.size() << ' ';
		for (int i : res)
			cout << i << ' ';
		cout << '\n';
	}
}

// 서로 다른 크기의 팬케익이 쌓여 있는 상황에서 크기 순서대로 정렬하기 위해 맨 위부터 붙어있는 k개의 팬케익을 통째로 뒤집어야 할 때, 뒤집는 횟수와 그 방법 출력하기

// 팬케익을 뒤집는 최소 횟수를 찾는 문제가 아님 - 따라서 어떤 방식으로든 뒤집으면 통과되나, 최대 횟수는 2n-3으로 제한됨
// 이 숫자가 어디서 나왔냐 - 이 문제를 푸는 일반적인 방법이 있음
// n번 인덱스에 n번 팬케익이 나와야 하므로, n번부터 위로 인덱스를 올려가며 n번 팬케익의 위치를 찾은 뒤, 해당 위치에서 1번 뒤집어 n번 팬케익을 위로 올린 후 n번 위치에서 뒤집어 원래 자리로 가게 한다
// 다만 여기서 n번 팬케익이 자기 자리에 있음이 확인되면 뒤집지 않고, n번 팬케익이 맨 위에 있는 경우 위로 올리는 과정을 하지 않는다
// 이 방식으로 하면 최대 횟수는 2n-3이 나옴 - 2번 팬케익을 뒤집어야 할 때 2번 팬케익은 반드시 맨 위에 있기 때문에 -1, 1번 팬케익은 뒤집을 필요가 없으니 -2

// 구성적 문제 - Constructive Algorithm
// 우리가 원하는 답이 존재함을 실제로 만들어서 중명하는 문제 