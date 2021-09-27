// 알파벳 거리
// https://www.acmicpc.net/problem/5218

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string a, b;
		cin >> a >> b;
		cout << "Distances: ";
		for (int i = 0; i < a.length(); i++) {
			if (a[i] <= b[i])
				cout << int(b[i] - a[i]) << ' ';
			else
				cout << int(26 - (a[i] - b[i])) << ' ';
		}
		cout << '\n';
	}
}

// 길이가 같은 두 대문자 문자열의 각 문자간의 거리는?

// 실제로 같은 자리의 문자의 아스키 코드값의 차를 구해주면 된다
// 다만 a와 b가 역순인 경우 정방향으로 한 바퀴 도는 거리를 출력해야 함에 주의 - (26 - 차)