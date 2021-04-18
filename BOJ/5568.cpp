// 카드 놓기
// https://www.acmicpc.net/problem/5568

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, k;
int res;
string cards[11];
bool selected[11];
int order[5];
unordered_map<string, bool> check;

void dfs(int p) {
	if (p == k) {
		string s;
		for (int i = 0; i < k; i++)
			s += cards[order[i]];
		if (!check[s]) {
			check[s] = true;
			res++;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!selected[i]) {
			selected[i] = true;
			order[p] = i;
			dfs(p + 1);
			selected[i] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> cards[i];
	res = 0;
	dfs(0);
	cout << res << '\n';
}

// n개의 카드 중 k개를 뽑아서 만들 수 있는 숫자의 종류는?
// 순열 문제 - 최대 10P4기 때문에 브포로 접근 가능
// 카드는 중복되지 않으나, 나오는 결과는 중복될 수 있음 - 따라서 답은 nPk가 아님
// 중복 판별은 어떻게? - 2자리 * 4개 = 8자리가 나올 수 있기에 배열로 관리하기에는 부담스러움
// 그렇다면 해시로 처리하면 됨