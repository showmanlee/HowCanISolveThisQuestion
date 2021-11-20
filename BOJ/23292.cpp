// 코딩 바이오리듬
// https://www.acmicpc.net/problem/23292

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, string> pr;

bool compare(pr a, pr b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string d;
	cin >> d;
	int n;
	cin >> n;
	vector<pr> sorter;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int a = 0, r = 1;
		for (int i = 0; i < 4; i++) {
			a += ((s[i] - '0') - (d[i] - '0')) * ((s[i] - '0') - (d[i] - '0'));
		}
		r *= a;
		a = 0;
		for (int i = 4; i < 6; i++) {
			a += ((s[i] - '0') - (d[i] - '0')) * ((s[i] - '0') - (d[i] - '0'));
		}
		r *= a;
		a = 0;
		for (int i = 6; i < 8; i++) {
			a += ((s[i] - '0') - (d[i] - '0')) * ((s[i] - '0') - (d[i] - '0'));
		}
		r *= a;
		sorter.push_back({ r, s });
	}
	sort(sorter.begin(), sorter.end(), compare);
	cout << sorter[0].second << '\n';
}

// 생년월일과 날짜를 아래와 같이 계산한 코딩 바이오리듬이 있을 때, 코딩 바이오리듬이 가장 높은 날짜는(같다면 가장 빠른 날짜는)?

// 주어진대로 계산해서 정렬해서 첫 번째 값을 출력하면 되지롱