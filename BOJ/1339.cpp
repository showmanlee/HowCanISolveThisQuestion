// 단어 수학
// https://www.acmicpc.net/problem/1339

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int> check(26);

	for (int i = 0; i < n; i++) {
		int p = 1;
		for (int j = v[i].length() - 1; j >= 0; j--) {
			check[v[i][j] - 'A'] += p;
			p *= 10;
		}
	}
	vector<pr> sorter;
	for (int i = 0; i < 26; i++)
		if (check[i] != 0)
			sorter.push_back({ -check[i], i});
	sort(sorter.begin(), sorter.end());
	vector<int> assign(26);
	int t = 9;
	for (pr p : sorter) {
		assign[p.second] = t;
		t--;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		for (char c : v[i])
			s += assign[c - 'A'] + '0';
		res += stoi(s);
	}
	cout << res << '\n';
}

// 알파벳으로 이루어진 문자열에 숫자를 대입하여 수를 만들 때, 합을 최대로 만든 경우의 최댓값은?
// 브포로 접근하면 시간초과(특히 알파벳 10개가 모두 등장하는 경우 10!)
// 다른 방법이 필요함 - 일단 앞에 최대한 높은 숫자가 와야 최댓값을 만들 수 있음
// 그렇다고 무조건 먼저 나오는 수에게 9를 적용하면 틀릴 수도 있음

// 알파벳이 등장하는 위치의 자릿값을 모두 더해서 체크해보자 - ABC = 100A + 10B + 1C
// 이런 식으로 등장하는 알파벳 계수를 모두 더해 가장 높은 계수를 가진 알파벳부터 차례대로 숫자를 부여하면 더 빠르게 풀 수 있음
// 그러니까 일종의 다항식으로 만들어서 풀 수 있다는 것

// 등장하는 알파벳 종류는 최대 10종류지만, 그것이 꼭 ABCDEFGHIJ가 아님에 주의