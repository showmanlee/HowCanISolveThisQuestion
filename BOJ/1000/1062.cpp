// 가르침
// https://www.acmicpc.net/problem/1062

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
string words[51];
bool learned[27];
int res;

void dfs(int idx, int cnt) {
	if (cnt == k) {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			bool fail = false;
			for (char c : words[i]) {
				if (!learned[c - 'a']) {
					fail = true;
					break;
				}
			}
			if (!fail)
				ret++;
		}
		res = max(res, ret);
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (!learned[i]) {
			learned[i] = true;
			dfs(i + 1, cnt + 1);
			learned[i] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> words[i];

	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	}
	if (k == 26) {
		cout << n << '\n';
		return 0;
	}
	res = 0;
	learned['a' - 'a'] = learned['c' - 'a'] = learned['i' - 'a'] = learned['n' - 'a'] = learned['t' - 'a'] = true;
	k -= 5;
	dfs(0, 0);
	cout << res << '\n';
	return 0;
}

// anta~tica의 형태를 가진 n개의 소문자 단어가 있고, 가르칠 수 있는 알파벳 문자가 k개 있을 때, k개의 문자로 가르칠 수 있는 단어의 수는?

// k의 알파벳에는 anta, tica를 가르치는 알파벳도 포함되어 있음 - 따라서 k가 5(acint) 미만이면 필연적으로 모든 단어를 가르칠 수 없음
// 반대로 k가 26이면 필연적으로 모든 단어를 가르칠 수 있음
// 둘 다 아니고 k가 그 사이의 값이라면 남은 알파벳 21개 중 k-5개를 뽑아야 함 - 조합 기반으로, 순열이 아니기 때문에 충분히 브루트포스로 접근 가능
// a, c, i, n, t에는 체크를 해준 채 브루트포스로 나머지 k-5개의 알파벳을 뽑은 후, 모든 단어의 글자를 순회하며 선택한 알파벳들로만 단어가 구성되어 있을 경우 집계값에 ++
// 매 탐색마다 이렇게 쌓인 집계값을 바탕으로 결과값을 갱신한 후 출력하기