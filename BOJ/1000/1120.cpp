// 문자열
// https://www.acmicpc.net/problem/1120

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int res = 987654321;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[j + i]) {
				cnt++;
			}
		}
		res = min(res, cnt);
	}
	cout << res << '\n';
}

// 길이가 a <= b인 두 문자열에서 a 앞뒤로 아무 알파벳이나 붙여 b와 같은 길이로 만들 때, 둘의 차이가 최소화된 결과는?

// 일단 알파벳을 추가할 때 b와 최대한 같은 알파벳을 넣으면 되므로 차이 개수가 늘어나지는 않음
// 즉, a를 b 안에 놓을 때 대응되는 위치에서 두 문자열의 차이를 최소화할 때 차이의 개수를 구하면 되는 문제
// 이건 직접 대봐야 알 수 있음