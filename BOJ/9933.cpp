// 민균이의 비밀번호
// https://www.acmicpc.net/problem/9933

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	string res;
	for (int i = 0; i < n; i++) {
		string r = v[i];
		reverse(r.begin(), r.end());
		for (int j = 0; j < n; j++) {
			if (r == v[j]) {
				res = v[i];
				break;
			}
		}
		if (res != "")
			break;
	}
	cout << res.length() << ' ' << res[res.length() / 2] << '\n';
}

// 주어진 문자열들 중 원래 문자열과 뒤집은 문자열이 모두 존재하는 문자열을 찾고, 그 문자열의 길이와 가운데 문자 출력하기

// 문자열의 개수가 100개까지므로 n^2로도 풀 수 있음
// 문자열들을 받고, 해당 배열의 문자열 하나를 선택해 그 문자열을 뒤집은 다음, 뒤집은 형태가 다른 문자열로 존재하는지 확인
// 확인되면 해당 문자열의 길이와 가운데 문자를 출력하면 됨