// 문자열 폭발
// https://www.acmicpc.net/problem/9935

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	string st;
	for (char c : s) {
		st += c;
		while (st.length() >= t.length()) {
			string v;
			for (int i = 0; i < t.length(); i++) {
				v = st.back() + v;
				st.pop_back();
			}
			if (v == t)
				continue;
			else {
				st += v;
				break;
			}
		}
	}
	if (st == "")
		st = "FRULA";
	cout << st << '\n';
}

// 어떤 문자열에 '폭발 문자열'이 섞여있는 경우 모든 폭발 문자열이 폭발하고 조각들이 서로 붙는 과정이 반복될 때, 남은 문자열은?

// substr은 n^2의 시간복잡도를 가짐 - 따라서 문자열 길이가 1000000까지 가능한 이 상황에서는 사용하지 않는게 좋음
// 이를 대체할 수 있는 방법은 back()과 pop_back()을 활용하는 것 - 마지막 원소를 보는 것과 지우는 것은 1의 시간복잡도
// 스택으로 활용할 문자열에 문자를 넣은 뒤, 스택 문자열의 길이가 폭발 문자열의 길이 이상이 되면 스택 문자열 뒤의 폭발 문자열 길이만큼의 부분 문자열을 뽑는다
// 이 부분 문자열이 폭발 문자열과 다르다면 부분 문자열을 다시 스택 문자열에 붙이고, 폭발 문자열이라면 버린다 - 부분 문자열이 스택에 붙었다면 다음 문자를 받는다
// 이렇게 모든 문자를 스택에 붙인 후 스택 문자열의 상태가 정답 - 스택이 비었을 경우 FRULA 출력