// 귀여운 수~ε٩(๑> ₃ <)۶з
// https://www.acmicpc.net/problem/17294

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	if (s.length() <= 2)
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n";
	else {
		int diff = s[1] - s[0];
		bool res = true;
		for (int i = 2; i < s.length(); i++) {
			if (s[i] - s[i - 1] != diff) {
				res = false;
				break;
			}
		}
		cout << (res ? "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" : "흥칫뿡!! <(￣ ﹌ ￣)>") << '\n';
	}
}

// 주어지는 자연수를 이루는 수가 등차수열을 이루고 있는가?
// 자연수를 문자열로 받은 후 길이가 2 이하면 무조건 등차수열, 그렇지 않으면 첫 문자와 두 문자의 차가 이후 문자들에도 적용되는지 확인
// vs에서는 제대로 출력되지 않지만, boj 채점 프로그램은 제대로 출력해주니 안심해도 됨