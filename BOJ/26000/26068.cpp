// 치킨댄스를 추는 곰곰이를 본 임스 2
// https://www.acmicpc.net/problem/26068

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int p = stoi(s.substr(2));
		if (p <= 90) {
			res++;
		}
	}
	cout << res << '\n';
}

// 기프티콘들의 남은 사용 기간이 주어질 때, 90일 이하로 남은 기프티콘의 수는?

// 기간이 D-XX 꼴로 주어지므로, substr을 구해서 계산해봅니다