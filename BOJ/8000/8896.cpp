// 가위 바위 보
// https://www.acmicpc.net/problem/8896

#include <iostream>
#include <vector>
#include <string>
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
		vector<string> v(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		vector<bool> survive(n + 1, true);
		int left = n;
		for (int i = 0; i < v[1].length(); i++) {
			bool r = false, s = false, p = false;
			for (int j = 1; j <= n; j++) {
				if (!survive[j]) {
					continue;
				}
				if (v[j][i] == 'R') {
					r = true;
				} else if (v[j][i] == 'S') {
					s = true;
				} else if (v[j][i] == 'P') {
					p = true;
				}
 			}
			if (r && s && !p) {
				for (int j = 1; j <= n; j++) {
					if (survive[j] && v[j][i] == 'S') {
						survive[j] = false;
						left--;
					}
				}
			} else if (r && !s && p) {
				for (int j = 1; j <= n; j++) {
					if (survive[j] && v[j][i] == 'R') {
						survive[j] = false;
						left--;
					}
				}

			} else if (!r && s && p) {
				for (int j = 1; j <= n; j++) {
					if (survive[j] && v[j][i] == 'P') {
						survive[j] = false;
						left--;
					}
				}
			}
		}
		if (left == 1) {
			for (int j = 1; j <= n; j++) {
				if (survive[j]) {
					cout << j << '\n';
				}
			}
		} else {
			cout << 0 << '\n';
		}
	}
}

// 가위바위보 로봇들이 각 라운드에 낼 커맨드들이 주어질 때, 최후의 생존자 구하기

// 로봇 커맨드들을 모두 받고, 로봇의 생존 여부를 나타내는 배열과 생존자 수 변수를 준비해둔다
// 이후 첫 번째 글자부터 생존한 로봇을 돌면서 들어온 커맨드의 등장 여부를 본 뒤, 두 가지 커맨드가 들어왔다면 지는 커맨드를 낸 로봇 모두 죽이기
// 이렇게 돌다가 생존자가 1명만 남으면 그 로봇 번호를 출력하고, 아니면 0을 출력한다