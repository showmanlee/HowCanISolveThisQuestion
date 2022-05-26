// 두라무리 휴지
// https://www.acmicpc.net/problem/25178

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	
	vector<int> al(26), bl(26);
	string aa, bb;
	for (int i = 0; i < n; i++) {
		al[a[i] - 'a']++;
		bl[b[i] - 'a']++;
		if (a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u') {
			aa += a[i];
		} 
		if (b[i] != 'a' && b[i] != 'e' && b[i] != 'i' && b[i] != 'o' && b[i] != 'u') {
			bb += b[i];
		}
	}
	bool res = true;
	for (int i = 0; i < 26; i++) {
		if (al[i] != bl[i]) {
			res = false;
			break;
		}
	}
	if (res) {
		if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
			res = false;
		}
		if (aa != bb) {
			res = false;
		}
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 길이가 같은 두 문자열이 다음 조건을 만족하는지 판정하기
// 1. 한 문자열의 문자를 재조합해 다른 문자열을 만들 수 있는가
// 2. 첫 글자와 마지막 문자가 동일한가
// 3. aeiou를 뺀 문자가 동일한가?

// 1번 조건 판정을 위해 등장 문자 개수를 세는 배열을 만들고, 3번 조건 판정을 위해 aeiou를 뺀 문자열을 문자 순회하면서 만든다
// 이들을 이용해 순서대로 조건에 부합하는지 보고 판정하기