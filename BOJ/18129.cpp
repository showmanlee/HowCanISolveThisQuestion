// 이상한 암호코드
// https://www.acmicpc.net/problem/18129

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	int k;
	cin >> s >> k;
	int combo = 1;
	vector<bool> visit(26);
	for (int i = 1; i <= s.length(); i++) {
		bool go = false;
		if (i != s.length())
			if (tolower(s[i]) == tolower(s[i - 1]))
				go = true;
		if (go)
			combo++;
		else {
			if (!visit[tolower(s[i - 1]) - 'a'])
				cout << (combo >= k ? 1 : 0);
			combo = 1;
			visit[tolower(s[i - 1]) - 'a'] = true;
		}
	}
}

// 대소문자로 이루어진 문자열과 자연수 k가 주어진다
// 만약 대소문자 구분 없이 연속된 문자가 k개 이상 등장한 경우 1로, 없으면 0으로 치환하고, 이미 치환된 알파벳이 다시 등장하면 그냥 버린다고 할 때, 출력된 결과는?

// 인덱스를 1부터 n까지 순회하며, 인덱스가 n이 아닌 경우 현재 문자와 전 문자와 비교해 계속 연속되고 있는지 확인하기
// 연속되는 경우 연속 길이를 누적하고, 그렇지 않은 경우 해당되는 문자를 출력한 뒤 연속 길이를 초기화하고, 지금까지 연속된 알파벳을 체크해준다