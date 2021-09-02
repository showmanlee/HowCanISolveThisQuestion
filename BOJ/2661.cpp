// 좋은수열
// https://www.acmicpc.net/problem/2661

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string res;

void dfs(int l, string s) {
	if (res != "")
		return;
	if (l == n) {
		res = s;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		string ss = s + to_string(i);
		bool pass = true;
		for (int j = 1; j <= ss.length() / 2; j++) {
			if (ss.substr(l + 1 - j, j) == ss.substr(l + 1 - j - j, j)) {
				pass = false;
				break;
			}
		}
		if (pass)
			dfs(l + 1, ss);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	res = "";
	dfs(1, "1");
	cout << res << '\n';
}

// 123으로 이루어진 수열에서 임의의 인접한 부분수열이 중복되지 않는 경우 좋은 수열이라고 부를 때, 길이가 n인 사전 순으로 가장 앞에 오는 좋은 수열은?

// dfs 방식으로 풀 수 있음 - dfs 함수는 지금까지의 길이와 만들어진 문자열을 기록
// 우선 시작은 "1"부터 시작 - 가장 작은 좋은 수열은 1부터 시작함이 명백함
// dfs 함수에 들어왔다면 주어진 문자열에 123을 차례로 넣어보면서, 좋은 수열 조건에 만족하면 dfs를 재귀 호출
// 조건 만족 여부는 1부터 길이/2까지 돌아보면서 마지막 글자부터 j글자 와 그 다음 j글자가 모두 다른지 확인하는 것 - 만약 같은 케이스가 발견되면 재귀를 돌리지 않음
// 이렇게 계속 돌리다 길이가 n인 결과값이 처음 나오면 해당 값을 전역변수로 선언된 결과값에 갱신하고, 만약 결과값 갱신이 확인되었다면 이후의 모든 dfs 함수에서 추가 탐색을 진행하지 않음
// 그리고나서 결과 출력하기