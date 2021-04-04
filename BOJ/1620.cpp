// 나는야 포켓몬 마스터 이다솜
// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<string> names;
	map<string, int> numbers;
	names.push_back("");
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		names.push_back(s);
		numbers[s] = i;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (isdigit(s[0])) {
			int p = stoi(s);
			cout << names[p] << '\n';
		}
		else
			cout << numbers[s] << '\n';
	}
}

// 간단하게 말해서 포켓몬 이름이 도감 번호 순서대로 주어지고, 이름이 주어지면 번호를, 번호가 주어지면 이름을 출력해야 함
// 해시 문제 - 그러나 번호도 주어지기에 번호 인덱스(vector), 이름 인덱스(map)으로 저장하자
// 100000개가 주어질 수 있으니 빠른 입출력 코드는 꼭 달고