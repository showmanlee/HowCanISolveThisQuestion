// Dyslexia
// https://www.acmicpc.net/problem/8387

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int res = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == b[i])
			res++;
	cout << res << '\n';
}

// 길이가 같은 두 문자열에서 서로 같은 문자 개수 구하기

// 길이가 주어지므로, 0부터 n-1까지 두 문자열의 인덱스를 돌면서 해당 문자가 같은 경우 ++