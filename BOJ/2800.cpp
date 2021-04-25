// 괄호 제거
// https://www.acmicpc.net/problem/2800

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string s;
int cnt;
bool check[11];
int marker[201];
vector<string> res;

void select(int p) {
	if (p > cnt) {
		bool valid = false;
		for (int i = 1; i <= cnt; i++)
			if (check[i])
				valid = true;
		if (!valid)
			return;
		string t;
		for (int i = 0; i < s.length(); i++)
			if (!check[marker[i]])
				t += s[i];
		res.push_back(t);
		return;
	}
	check[p] = false;
	select(p + 1);
	check[p] = true;
	select(p + 1);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	cnt = 0;
	stack<int> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			cnt++;
			marker[i] = cnt;
			st.push(cnt);
		}
		else if (s[i] == ')') {
			marker[i] = st.top();
			st.pop();
		}
	}
	select(1);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (string t : res)
		cout << t << '\n';
}

// 주어진 식에서 괄호를 올바르게 제거해 얻을 수 있는 수식들을 사전 순으로 나열하기

// 먼저 스택을 활용해 괄호 검출
// 여는 괄호가 발견될 때마다 괄호에 번호를 부여해 스택에 넣고, 괄호의 위치를 표시하는 인덱스에 해당 번호를 적는다
// 이후 이에 대응되는 닫힌 괄호가 발견되면 해당 번호를 스택에서 빼고, 인덱스에 해당 번호를 적는다
// 그리고 백트래킹으로 뺄 괄호들을 정해 해당 괄호를 뺀 배열을 결과 배열에 넣어준 후, 이를 정렬한다
// 여기서 하나의 식이 여러 개의 괄호에 싸일 수 있음에 주의 - 괄호를 뺸 식이 중복될 수 있음
// 따라서 정렬 후 중복 처리(erase(unique(begin, end), end))를 해줘야 함