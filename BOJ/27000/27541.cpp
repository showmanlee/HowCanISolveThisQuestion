// 末尾の文字 (Last Letter)
// https://www.acmicpc.net/problem/27541

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<double, double> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s[n - 1] == 'G') {
		cout << s.substr(0, n - 1) << '\n';
	} else {
		cout << s << "G\n";
	}
}

// 주어진 대문자 문자열이 G로 끝나면 마지막 G를 빼고 출력하고, 아니라면 뒤에 G를 붙여 출력하기

// 마지막 글자만 보고 판단해준다 - substr이나 append냐