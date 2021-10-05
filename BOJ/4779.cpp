// 칸토어 집합
// https://www.acmicpc.net/problem/4779

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

void dfs(int s, int e, int p) {
	if (p == 1)
		return;
	int pp = p / 3;
	dfs(s, s + pp, pp);
	for (int i = s + pp; i < s + pp + pp; i++)
		str[i] = ' ';
	dfs(s + pp + pp, e, pp);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		str = "";
		int p = 1;
		for (int i = 0; i < n; i++)
			p *= 3;
		for (int i = 0; i < p; i++)
			str += "-";
		dfs(0, p, p);
		cout << str << '\n';
	}
}

// '-'가 3^n개 있는 문자열에서 삼등분 후 가운데 부분을 공백으로 만들고 남은 부분을 삼등분하여 부분이 1이 될 때까지 같은 과정을 반복할 때, 최종적으로 만들어지는 문자열은?

// 분할 정복형 재귀 문제
// 처음에 3^n 길이의 문자열을 만든 후, 재귀함수를 돌면서 필요한 곳을 공백으로 만들어준다