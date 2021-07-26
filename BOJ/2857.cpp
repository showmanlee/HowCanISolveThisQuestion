// FBI
// https://www.acmicpc.net/problem/2857

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool found = false;
	for (int i = 1; i <= 5; i++) {
		string s;
		cin >> s;
		if (s.length() < 3)
			continue;
		for (int j = 0; j <= s.length() - 3; j++) {
			if (s.substr(j, 3) == "FBI") {
				cout << i << ' ';
				found = true;
				break;
			}
		}
	}
	if (!found)
		cout << "HE GOT AWAY!";
	cout << '\n';
}

// 5명 중 코드네임에서 'FBI'가 등장하는 사람 출력하기

// 문자열을 받고, 그 문자열을 앞에서부터 3글자씩 보면서 FBI가 등장하면 등장 번호 출력하기 - 그러면서 발견했다는 표시하기
// 만약 발견 표시가 안 뜨면 발견 못했다고 표시하고
// boj나 그런 곳들은 입력과 출력이 별개라서 둘을 혼합하게 보여도 문제없음