// 닉네임에 갓 붙이기
// https://www.acmicpc.net/problem/13163

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		string t, res;
		getline(cin, s);
		stringstream ss(s);
		int cnt = 0;
		while (ss >> t) {
			if (cnt == 0)
				res += "god";
			else
				res += t;
			cnt++;
		}
		cout << res << '\n';
	}
}

// 음절 단위로 주어진 닉네임에서 첫 음절을 god으로 바꾸고 나머지를 모두 붙인 결과 출력하기
// stringstream을 활용해 공백 있는 문자열을 쪼갠 후 첫 음절만 god, 나머지는 해당 조각을 붙여 결과 문자열 만들기
// n 입력 후 버퍼 처리를 위해 getline을 한번 쓰고 시작하기