// 빅데이터? 정보보호!
// https://www.acmicpc.net/problem/26264

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int c = 0, b = 0;
	int idx = 0;
	while (idx < s.length()) {
		if (s[idx] == 'b') {
			b++;
			idx += 7;
		} else if (s[idx] == 's'){
			c++;
			idx += 8;
		}
	}
	if (b > c) {
		cout << "bigdata?\n";
	} else if (b < c) {
		cout << "security!\n";
	} else {
		cout << "bigdata? security!\n";
	}
}

// 띄어쓰기가 없는 소문자 문자열에서 bigdata / security의 등장 횟수 세서 가장 많이 나온 단어 출력하기

// 문자열에 bigdata, security만 등장함이 보장되므로 b나 s를 발견한 경우 각각 7/8글자씩 앞으로 간다는 느낌으로 문자열 인덱스를 본다
// 그렇게 문제에 나온 대로 세서 결과 출력하기