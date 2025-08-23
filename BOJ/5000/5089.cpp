// Travelling Salesman
// https://www.acmicpc.net/problem/5089

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int week = 0;
	while (true) {
		week++;
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		cin.ignore();
		map<string, bool> visit;
		int res = 0;
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			if (!visit[s]) {
				res++;
				visit[s] = true;
			}
		}
		cout << "Week " << week << ' ' << res << '\n';
	}
}

// ISBN에 빈 한 숫자 출력하기