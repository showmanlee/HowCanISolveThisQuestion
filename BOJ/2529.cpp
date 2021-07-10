// 부등호
// https://www.acmicpc.net/problem/2529

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
char ineq[10];
bool selected[10];
int order[10];
string minn, maxx;

void dfs(int cnt) {
	if (cnt > n) {
		for (int i = 1; i <= n; i++) {
			if (ineq[i] == '<' && order[i - 1] > order[i])
				return;
			if (ineq[i] == '>' && order[i - 1] < order[i])
				return;
		}
		string p;
		for (int i = 0; i <= n; i++)
			p += char(order[i] + '0');
		minn = min(minn, p);
		maxx = max(maxx, p);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (!selected[i]) {
			selected[i] = true;
			order[cnt] = i;
			dfs(cnt + 1);
			order[cnt] = -1;
			selected[i] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ineq[i];
	for (int i = 0; i <= n; i++) {
		order[i] = -1;
		minn += "9";
		maxx += "0";
	}
	dfs(0);
	cout << maxx << '\n' << minn << '\n';
}

// 주어진 부등호들 사이에 0~9의 숫자를 넣어 식을 성립시키고 싶을 때, 가능하게 넣은 숫자들을 나열한 문자열의 최댓값과 최솟값 출력하기

// DFS 기반으로 중복되지 않게 n + 1개의 숫자들을 고른 뒤 주어진 부등호 관계를 보고 성립 여부를 본 뒤, 성립이 확인되면 최댓값과 최솟값을 갱신한다
// 각 자리에 최솟값은 9, 최댓값은 0을 n+1개만큼 채워주기 - min, max 함수는 string에서도 적용됩니다(비교가 가능하니까)