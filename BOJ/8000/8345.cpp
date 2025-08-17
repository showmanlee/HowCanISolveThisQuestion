// A Cat on a Keyboard
// https://www.acmicpc.net/problem/8345

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v = {
	"`1234567890-=",
	"QWERTYUIOP[]\\",
	"ASDFGHJKL;'",
	"ZXCVBNM,./",
	" "
};

char f(char c) {
	for (int i = 0; i < 5; i++) {
		if (v[i].find(c) != string::npos) {
			return '1' + i;
		}
	}
	return '0';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	string res;
	for (char c : s) {
		res += f(c);
	}
	cout << res << '\n';
}

// 주어진 수열에서 같은 원소가 k개 이하로 있는 가장 긴 연속 부분 수열의 길이 출력하기