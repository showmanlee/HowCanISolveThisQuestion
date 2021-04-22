// 강력한 비밀번호
// https://www.acmicpc.net/problem/16944

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string special = "!@#$%^&*()-+";

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<bool> verify(4);
	for (char c : s) {
		if (isupper(c))
			verify[0] = true;
		if (islower(c))
			verify[1] = true;
		if (isdigit(c))
			verify[2] = true;
		if (special.find(c) != string::npos)
			verify[3] = true;
	}
	int res = 0;
	for (int i = 0; i < 4; i++)
		if (!verify[i])
			res++;
	if (s.length() + res < 6)
		res = 6 - s.length();
	cout << res << '\n';
}

// 강력한 비밀번호가 소문자, 대문자, 숫자, 특수문자가 한 개씩 들어가면서 6자를 넘겨야 할 때, 입력된 비밀번호를 강력한 비밀번호로 만들기 위해 추가해야 하는 문자 수는?
// 만약 각 타입의 문자가 있다면 체크해주고, 최종적으로 체크되지 않은 타입이 있는 경우 개당 1개씩 추가
// 그런데 문자를 추가해도 6글자가 되지 않는 경우, 6글자를 채울 수 있도록 조정하기